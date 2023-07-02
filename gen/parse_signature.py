import sys

TOK_DIGIT = 1
TOK_LETTERS = 2
TOK_HEX = 3
TOK_SYM = 4
TOK_END = 99
TOK_NONE = 44
ARG_MAX_NUMB = 198809999999


def getSTR(kind):
    if kind == TOK_DIGIT:
        return "digit"
    elif kind == TOK_LETTERS:
        return "letter"
    elif kind == TOK_SYM:
        return "symbol"
    elif kind == TOK_HEX:
        return "hex"
    elif kind == TOK_END:
        return "end"
    else:
        return "none"


class Tok:
    def __init__(self, kind, val):
        self.kind = kind
        self.val = val

    def __repr__(self):
        return f"Tok('{getSTR(self.kind)}', '{self.val}')"

    def __str__(self):
        return self.__repr__()


class ArgElement:
    def __init__(self, kind, val):
        self.kind = kind
        self.val = val

    def __repr__(self):
        return f"ArgElement({self.kind}, {self.val})"

    def __str__(self):
        return self.__repr__()

    def __eq__(self, other):
        return self.kind == other.kind and self.val == other.val

    def getCppArgType(self):
        if self.kind is None or self.kind in "[]":
            return ""
        xtra = self.val if self.val != None and self.val >= 0 else ""
        if self.kind == "r":
            return "Operand"
        elif self.kind == "v":
            return "VReg"
        elif self.kind == "f":
            return "FReg"
        elif self.kind in ["ri", "m", "i"]:
            return "int"
        elif self.kind[0] == "d":
            return f"Addr{self.kind.upper()}"
        return ""

    def getCppArgName(self):
        if self.kind == "number" or self.kind in "()|":
            return str(self.val)
        if str(self.val) == "-1":
            return f"{self.kind}"
        return f"{self.kind}{self.val}"

    def getCppArgDefault(self):
        t = self.getCppArgType()
        if t =="int":
            return "0"
        else:
            return f"{t}{{}}"
    



def skip_nonsense(s, beg=0):
    i = beg
    # skip till ,[](d)
    while i < len(s):
        c = s[i]
        if c in ", \t\n\r":
            i += 1
        else:
            break
    return i


def get_symbol(s, beg):
    if beg < len(s) and s[beg] in "[]()|":
        return (beg + 1, s[beg])
    return (beg, None)

def get_hex(s, beg):
    i = beg
    if i<len(s) and s[i] == "0":
        i+=1
        if i<len(s) and s[i] == "x":
            i+=1
    while i < len(s):
        if s[i] >= "0" and s[i] <= "9":
            i += 1
        elif s[i] >='a' and s[i]<='f':
            i += 1
        else:
            break
    if i<beg+3:
        #at least 3 symbols needed 0x0
        return (beg, None)
    return (i, None if beg >= i else s[beg:i])


def get_letters(s, beg):
    i = beg
    while i < len(s):
        if s[i] >= "a" and s[i] <= "z":
            i += 1
        else:
            break
    return (i, None if beg >= i else s[beg:i])


def get_digits(s, beg):
    i = beg
    while i < len(s):
        if s[i] >= "0" and s[i] <= "9":
            i += 1
        else:
            break
    return (i, None if beg >= i else s[beg:i])

def get_digits(s, beg):
    i = beg
    while i < len(s):
        if s[i] >= "0" and s[i] <= "9":
            i += 1
        else:
            break
    return (i, None if beg >= i else s[beg:i])


def tokenize(s):
    s = s.lower()
    i = 0
    while i < len(s):
        unk = True
        i = skip_nonsense(s, i)
        i, val = get_hex(s, i)
        if val is not None:
            unk = False
            yield Tok(TOK_HEX, val)
        i, val = get_letters(s, i)
        if val is not None:
            unk = False
            yield Tok(TOK_LETTERS, val)
        i, val = get_digits(s, i)
        if val is not None:
            unk = False
            yield Tok(TOK_DIGIT, val)
        i, val = get_symbol(s, i)
        if val is not None:
            unk = False
            yield Tok(TOK_SYM, val)
        if unk:
            print("warning unk, force skip", file=sys.stderr)
            i += 1
    yield (Tok(TOK_END, 0))


def get_unit(curr_token, tokenizer):
    if curr_token.kind == TOK_END:
        return (curr_token, None)
    if curr_token.kind == TOK_LETTERS:
        strx = curr_token.val
        # possible addr
        curr_token = next(tokenizer)
        digit = -1
        if curr_token.kind == TOK_DIGIT:
            digit = curr_token.val
            curr_token = next(tokenizer)
        return (curr_token, ArgElement(strx, int(digit)))
    return (curr_token, None)


def get_disp_addr(curr_token, tokenizer):
    curr_token, arg = get_unit(curr_token, tokenizer)
    if arg is None or arg.kind != "d":
        return (curr_token, arg)
    # check if symbol ( and find compound addr
    if curr_token.val == "(":
        curr_token = next(tokenizer)
        # try registers and lengths
        curr_token, arg1 = get_unit(curr_token, tokenizer)

        if arg1 is not None and arg1.kind in "bxlvr":
            arg.val = max(arg.val, arg1.val)
            arg.kind += arg1.kind
            # try registers and lengths
            curr_token, arg2 = get_unit(curr_token, tokenizer)

            if arg2 is not None and arg1.kind in "bxlvr":
                arg.val = max(arg.val, arg2.val)
                arg.kind += arg2.kind
    if curr_token.kind == TOK_SYM and curr_token.val == ")":
        curr_token = next(tokenizer)
    else:
        print("warning error", file=sys.stderr)
    return (curr_token, arg)



def parse_arg(s):
    """
    Parse, its very relaxed and simply skips errors
    optionals starts whenever it encounters [ symbol
    """
    listx = []
    optional_start = None
    tokenizer = tokenize(s)
    tok_next = next(tokenizer)
    while tok_next.kind != TOK_END:
        tok_next, a = get_disp_addr(tok_next, tokenizer)
        if a is not None:
            listx.append(a)
        else:
            if tok_next.kind == TOK_SYM:
                if optional_start is None and tok_next.val == "[":
                    optional_start = len(listx)
                    # we do not care for other symbols or later occurences
                if tok_next.val == "|":
                    listx.append(ArgElement("|", tok_next.val))
                if tok_next.val == "(":
                    listx.append(ArgElement("(", tok_next.val))
                if tok_next.val == ")":
                    listx.append(ArgElement(")", tok_next.val))
                tok_next = next(tokenizer)
            elif tok_next.kind == TOK_DIGIT or tok_next.kind == TOK_HEX:
                listx.append(ArgElement("number", tok_next.val))
                tok_next = next(tokenizer)
            else:
                #force
                print(f"warning force skip: {tok_next}", file=sys.stderr)
                tok_next = next(tokenizer)


    return (listx, optional_start)


class Signature:


    def __init__(self, formatX):
        pp, ii = parse_arg(formatX)
        self.optionalStart = ii if ii is not None else ARG_MAX_NUMB
        self.argList = pp

    def __repr__(self):
        return f"Signature({self.argList}, {self.optionalStart})"

    def __str__(self):
        return self.__repr__()


def getMergedSignature(ls1, ls2):
    ''' 
    returns
       (overlapped_signature, amibiguity index)
    '''
    len1 = len(ls1.argList)
    len2 = len(ls2.argList)
    min_len = min(len1, len2)
    #merge by type
    types1=[x.getCppArgType() for x in ls1.argList[:min_len]]
    types2=[x.getCppArgType() for x in ls2.argList[:min_len]]
    optional_ind = min(ls1.optionalStart, ls2.optionalStart, min_len)
    types_overlaps = types2 == types1
    # print(f"{ls1} {ls2} overlaps {overlaps}")
    if types_overlaps == False:
        return (None, ARG_MAX_NUMB)
    #check if args overlaps:
    first_differ_index = -1
    for i in range(0,min_len):
        if ls1.argList[i] != ls2.argList[i]:
            first_differ_index = i
            break
    args_overlap = first_differ_index==-1 #ls1.argList[:min_len] == ls2.argList[:min_len]
    # find min optional, it should be minimum of min_len, 1st optional, 2nd optional    
    if args_overlap == False:
        #we may have  a problem
        print(f"Warning: it maybe ambiguous as types overlap, but args don't :\n{ls1.argList}\n{ls2.argList}", file = sys.stderr)
        print("We will try to merge some cases\nYou may need to fix that portion of the code manually",  file = sys.stderr)
        if len1 == len2:
            print(f"length are equal, so we will merge args by index order")
            lsret = Signature("")
            lsret.argList = ls1.argList[:first_differ_index]
            lsret.optionalStart = optional_ind
            gi1 = first_differ_index
            gi2 = gi1
            while gi1<len1 and gi2<len2:
                ar1 = ls1.argList[gi1] 
                ar2 = ls2.argList[gi2]
                if ar1.val < ar2.val:
                    gi1+=1
                    lsret.argList.append(ar1)
                else:
                    gi2+=1
                    lsret.argList.append(ar2)
            while gi1 < len1:
                lsret.argList.append(ls1.argList[gi1])
                gi1+=1
            while gi2 < len2:
                lsret.argList.append(ls2.argList[gi2])
                gi2+=1
            return (lsret, first_differ_index)
    
    # lets change the one with more arguments
    lsRet = ls1 if len1 > len2 else ls2
    lsRet.optionalStart = optional_ind
    return (lsRet, ARG_MAX_NUMB)
