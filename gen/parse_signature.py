"""IBM Z Principles of Operation method singature parser"""
import sys
TOK_DIGIT = 1
TOK_LETTERS = 2
TOK_HEX = 3
TOK_SYM = 4
TOK_END = 99
TOK_NONE = 44
ARG_MAX_NUMB = 198809999999


def get_token_string(kind):
    """Gets token string"""
    if kind == TOK_DIGIT:
        return "digit"
    if kind == TOK_LETTERS:
        return "letter"
    if kind == TOK_SYM:
        return "symbol"
    if kind == TOK_HEX:
        return "hex"
    if kind == TOK_END:
        return "end"
    return "none"


class Token:
    """Token"""

    def __init__(self, kind, val):
        self.kind = kind
        self.val = val

    def __repr__(self):
        return f"Tok('{get_token_string(self.kind)}', '{self.val}')"

    def __str__(self):
        return self.__repr__()


class ArgElement:
    """Represents Argument element"""

    def __init__(self, kind, val):
        self.kind = kind
        self.val = val

    def __repr__(self):
        return f"ArgElement({self.kind}, {self.val})"

    def __str__(self):
        return self.__repr__()

    def __eq__(self, other):
        return self.kind == other.kind and self.val == other.val

    def get_arg_type(self):
        """Gets arg type"""
        arg_type = ""
        if self.kind is None or self.kind in "[]":
            arg_type = ""
        elif self.kind == "r":
            arg_type = "Operand"
        elif self.kind == "v":
            arg_type = "VReg"
        elif self.kind == "f":
            arg_type = "FReg"
        elif self.kind in ["ri", "m", "i"]:
            arg_type = "int"
        elif self.kind[0] == "d":
            arg_type = f"Addr{self.kind.upper()}"
        return arg_type

    def get_arg_name(self):
        """Gets arg name"""
        if self.kind == "number" or self.kind in "()|":
            return str(self.val)
        if str(self.val) == "-1":
            return f"{self.kind}"
        return f"{self.kind}{self.val}"

    def get_arg_default(self):
        """Gets arg default value"""
        arg_type = self.get_arg_type()
        if arg_type == "int":
            return "0"
        else:
            return f"{arg_type}{{}}"


def skip_nonsense(string, begin_index=0):
    "Skips whitspaces and comma"
    i = begin_index
    # skip till ,[](d)
    while i < len(string):
        if string[i] in ", \t\n\r":
            i += 1
        else:
            break
    return i


def get_symbol(string, begin_index):
    """Gets symbols"""
    if begin_index < len(string) and string[begin_index] in "[]()|":
        return (begin_index + 1, string[begin_index])
    return (begin_index, None)


def get_hex(string, begin_index):
    """Gets Hexadecimal number"""
    i = begin_index
    if i < len(string) and string[i] == "0":
        i += 1
        if i < len(string) and string[i] == "x":
            i += 1
    while i < len(string):
        if string[i] >= "0" and string[i] <= "9":
            i += 1
        elif string[i] >= 'a' and string[i] <= 'f':
            i += 1
        else:
            break
    if i < begin_index+3:
        # at least 3 symbols needed 0x0
        return (begin_index, None)
    return (i, None if begin_index >= i else string[begin_index:i])


def get_letters(string, begin_index):
    """Gets letters"""
    i = begin_index
    while i < len(string):
        if string[i] >= "a" and string[i] <= "z":
            i += 1
        else:
            break
    return (i, None if begin_index >= i else string[begin_index:i])


def get_digits(string, begin_index):
    """Gets digits"""
    i = begin_index
    while i < len(string):
        if string[i] >= "0" and string[i] <= "9":
            i += 1
        else:
            break
    return (i, None if begin_index >= i else string[begin_index:i])


def tokenize(string):
    """Tokenize"""
    string = string.lower()
    i = 0
    while i < len(string):
        unk = True
        i = skip_nonsense(string, i)
        i, val = get_hex(string, i)
        if val is not None:
            unk = False
            yield Token(TOK_HEX, val)
        i, val = get_letters(string, i)
        if val is not None:
            unk = False
            yield Token(TOK_LETTERS, val)
        i, val = get_digits(string, i)
        if val is not None:
            unk = False
            yield Token(TOK_DIGIT, val)
        i, val = get_symbol(string, i)
        if val is not None:
            unk = False
            yield Token(TOK_SYM, val)
        if unk:
            print("warning unk, force skip", file=sys.stderr)
            i += 1
    yield Token(TOK_END, 0)


def get_unit(current_token, tokenizer):
    """Gets Unit ArgElement"""
    if current_token.kind == TOK_END:
        return (current_token, None)
    if current_token.kind == TOK_LETTERS:
        strx = current_token.val
        # possible addr
        current_token = next(tokenizer)
        digit = -1
        if current_token.kind == TOK_DIGIT:
            digit = current_token.val
            current_token = next(tokenizer)
        return (current_token, ArgElement(strx, int(digit)))
    return (current_token, None)


def get_disp_addr(current_token, tokenizer):
    """Gets displacement address"""
    current_token, arg = get_unit(current_token, tokenizer)
    if arg is None or arg.kind != "d":
        return (current_token, arg)
    # check if symbol ( and find compound addr
    if current_token.val == "(":
        current_token = next(tokenizer)
        # try registers and lengths
        current_token, arg1 = get_unit(current_token, tokenizer)

        if arg1 is not None and arg1.kind in "bxlvr":
            arg.val = max(arg.val, arg1.val)
            arg.kind += arg1.kind
            # try registers and lengths
            current_token, arg2 = get_unit(current_token, tokenizer)

            if arg2 is not None and arg1.kind in "bxlvr":
                arg.val = max(arg.val, arg2.val)
                arg.kind += arg2.kind
    if current_token.kind == TOK_SYM and current_token.val == ")":
        current_token = next(tokenizer)
    else:
        print("warning error", file=sys.stderr)
    return (current_token, arg)


def parse_arg(string):
    """
    Parse, its very relaxed and simply skips errors
    optionals starts whenever it encounters [ symbol
    """
    parsed_list = []
    optional_start = None
    tokenizer = tokenize(string)
    tok_next = next(tokenizer)
    while tok_next.kind != TOK_END:
        tok_next, address = get_disp_addr(tok_next, tokenizer)
        if address is not None:
            parsed_list.append(address)
        else:
            if tok_next.kind == TOK_SYM:
                if optional_start is None and tok_next.val == "[":
                    optional_start = len(parsed_list)
                    # we do not care for other symbols or later occurences
                if tok_next.val == "|":
                    parsed_list.append(ArgElement("|", tok_next.val))
                if tok_next.val == "(":
                    parsed_list.append(ArgElement("(", tok_next.val))
                if tok_next.val == ")":
                    parsed_list.append(ArgElement(")", tok_next.val))
                tok_next = next(tokenizer)
            elif tok_next.kind in (TOK_DIGIT, TOK_HEX):
                parsed_list.append(ArgElement("number", tok_next.val))
                tok_next = next(tokenizer)
            else:
                # force
                print(f"warning force skip: {tok_next}", file=sys.stderr)
                tok_next = next(tokenizer)

    return (parsed_list, optional_start)


class Signature:
    """Method Signature"""

    def __init__(self, format_string):
        arg_list, optional_index = parse_arg(format_string)
        self.optional_start = optional_index if optional_index is not None else ARG_MAX_NUMB
        self.arg_list = arg_list

    def __repr__(self):
        return f"Signature({self.arg_list}, {self.optional_start})"

    def __str__(self):
        return self.__repr__()


def get_merged_signature(ls1: Signature, ls2: Signature):
    ''' 
    returns  (overlapped_signature, amibiguity index)
    '''
    len1 = len(ls1.arg_list)
    len2 = len(ls2.arg_list)
    min_len = min(len1, len2)
    # merge by type
    types1 = [x.get_arg_type() for x in ls1.arg_list[:min_len]]
    types2 = [x.get_arg_type() for x in ls2.arg_list[:min_len]]
    optional_ind = min(ls1.optional_start, ls2.optional_start, min_len)
    types_overlaps = types2 == types1
    # print(f"{ls1} {ls2} overlaps {overlaps}")
    if not types_overlaps:
        return (None, ARG_MAX_NUMB)
    # check if args overlaps:
    first_differ_index = -1
    for i in range(0, min_len):
        if ls1.arg_list[i] != ls2.arg_list[i]:
            first_differ_index = i
            break
    # ls1.arg_list[:min_len] == ls2.arg_list[:min_len]
    args_overlap = first_differ_index == -1
    # find min optional, it should be minimum of min_len, 1st optional, 2nd optional
    if not args_overlap:
        # we may have  a problem
        print(f"Warning: it maybe ambiguous as types overlap, but args don't :\n{ls1.arg_list}\n{ls2.arg_list}",
            file=sys.stderr)
        print("We will try to merge some cases\nYou may need to fix that portion of the code manually",
            file=sys.stderr)
        if len1 == len2:
            print("length are equal, so we will merge args by index order")
            merged_list = Signature("")
            merged_list.arg_list = ls1.arg_list[:first_differ_index]
            merged_list.optional_start = optional_ind
            gi1 = first_differ_index
            gi2 = gi1
            while gi1 < len1 and gi2 < len2:
                ar1 = ls1.arg_list[gi1]
                ar2 = ls2.arg_list[gi2]
                if ar1.val < ar2.val:
                    gi1 += 1
                    merged_list.arg_list.append(ar1)
                else:
                    gi2 += 1
                    merged_list.arg_list.append(ar2)
            while gi1 < len1:
                merged_list.arg_list.append(ls1.arg_list[gi1])
                gi1 += 1
            while gi2 < len2:
                merged_list.arg_list.append(ls2.arg_list[gi2])
                gi2 += 1
            return (merged_list, first_differ_index)
    # lets change the one with more arguments
    new_list = ls1 if len1 > len2 else ls2
    new_list.optional_start = optional_ind
    return (new_list, ARG_MAX_NUMB)
