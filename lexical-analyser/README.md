This is a lexical analyser based on FLEX
========================================

How to compile
--------------

flex lex.l

gcc lex.yy.c -o lexer.out


How to run
----------

./lexer.out <input program file>


Symbol table
------------

A preliminary symbol table is implemented in symboltable.h;

A linked list of Struct is used as the main data structure;

Duplicated IDs would be mapped to the same entry and have the same address;

Scope is not implemented;
