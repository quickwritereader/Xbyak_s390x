### Commands to extract information from IbmZ15.pdf

instruction_format.txt file contains Instruction Formats that will be used for binary encoding

The below scripts use pdfplumber python package.
```
python3 -m pip install pdfplumber
```
Pdfplumber is *a little bit slow*, so be patient if you want to re-extract the information

##### Extracts ISA tables from IBM Z Principles of Operation

It's a good source to get the text representation of the facilities, exceptions
```
python3 xtract_isa.py IbmZ15.pdf
```

##### Extracts ISA and its format from IBM Z Principles of Operation
```
python3 xtract_isa.py IbmZ15.pdf

```

### Command to generate mnemonics and also extension methods

After extraction codes, there should be files prefixed with IbmZ15.pdf_
then it is possible to generate codes needed for xbyak_s390x with the following command

```
python3 generate_xbyak.py IbmZ15.pdf

```

