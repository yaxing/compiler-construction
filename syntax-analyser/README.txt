//
//Compiler Construction
// Project 2-Syntax Analyser
//
// @author Yaxing Chen(N16929794)

1. How to compile and run
(symboltable.h has to be in current directory)
flex lex.l
bison -d translate.y
gcc lex.yy.c translate.tab.c -ll -o SA.out
./SA.out < <testfile>

Or you can directly run: 
compile_run.sh <testfile>

Symbol table would be print to file: symtable.out

3. Symbol table
A preliminary symbol table is implemented in symboltable.h.
Only one global scope is implemented.
Symbol table is implemented as a struct array.
Duplicated IDs would be mapped to the same entry and have the same address.
Re-defined variables would cause syntax error.

What is in symbol table:
All IDs matched by lexical analyser.

Each entry has following field:
Address:     entry address in table;
ID: ID name
Type:        type of ID, e.g. function
Attr:   additional attribute of the ID, e.g. parameter number of a function.

4. Environment
Verified running on CIMS machine: crunchy3.cims.nyu.edu

5. Error Handling
Parser is detecting general parsing errors.
Also when encounter re-defined variable, an error would raise.