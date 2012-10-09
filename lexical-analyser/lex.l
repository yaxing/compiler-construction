%option noyywrap
%{
    //
    //  symboltable.h
    //  compiler-lexer
    //
    //  Copyright (c) 2012 Yaxing Chen. All rights reserved.
    //
    #include <stdio.h>
    #include "symboltable.h"
    
    enum KEYS {
        AND = 0,
        BEG = 1,
        FORWARD = 2,
        DIV = 3,
        DO = 4,
        ELSE = 5,
        END = 6,
        FOR = 7,
        FUNCTION = 8,
        IF = 9,
        ARRAY = 10,
        MOD = 11,
        NOT = 12,
        OF = 13,
        OR = 14,
        PROCEDURE = 15,
        PROGRAM = 16,
        RECORD = 17,
        THEN = 18,
        TO = 19,
        TYPE = 20,
        VAR = 21,
        WHILE = 22,
        OP_ADD = 23,
        OP_MUL = 24,
        OP_MIN = 25,
        OP_RELOP = 26,
        OP_LESS = 27,
        OP_LESS_EQ = 28,
        OP_GREATER = 29,
        OP_GREATER_EQ = 30,
        OP_NOT_EQ = 31,
        DOT = 32,
        COMMA = 33,
        COLON = 34,
        SEMICOLON = 35,
        EQUAL = 36,
        DOUBLE_DOT = 37,
        BRACE_L = 38,
        BRACE_R = 39,
        BRACKET_L = 40,
        BRACKET_R = 41,
        INT = 42,
        NUM = 43,
        ID = 44,
        STRING = 45,
        UNK = 46
    };
    
    char *symbol_names[] = {
        "AND",
        "BEG",
        "FORWARD",
        "DIV",
        "DO",
        "ELSE",
        "END",
        "FOR",
        "FUNCTION",
        "IF",
        "ARRAY",
        "MOD",
        "NOT",
        "OF",
        "OR",
        "PROCEDURE",
        "PROGRAM",
        "RECORD",
        "THEN",
        "TO",
        "TYPE",
        "VAR",
        "WHILE",
        "OP_ADD",
        "OP_MUL",
        "OP_MIN",
        "OP_RELOP",
        "OP_LESS",
        "OP_LESS_EQ",
        "OP_GREATER",
        "OP_GREATER_EQ",
        "OP_NOT_EQ",
        "DOT",
        "COMMA",
        "COLON",
        "SEMICOLON",
        "EQUAL",
        "DOUBLE_DOT",
        "BRACE_L",
        "BRACE_R",
        "BRACKET_L",
        "BRACKET_R",
        "INT",
        "NUM",
        "ID",
        "STRING",
        "UNK"
    };
    
    long yylval = 0;
%}

delim  [ \n\t\r]
letter [a-zA-Z]
char   [.]
digit  [0-9]
id     {letter}({letter}|{digit}|_)*
int    {digit}+
string \"[^\"]*\"
ws     {delim}+
number [+-]?{int}+([\.]{int}+)?
comments \{[^{}]*\}

%%
{ws} {/*discard*/}
{comments} {/*discard*/}

if {return IF;}
and {return AND;}
begin {return BEG;}
forward {return FORWARD;}
div {return DIV;}
do {return DO;}
else {return ELSE;}
end {return END;}
for {return FOR;}
function {return FUNCTION;}
array {return ARRAY;}
mod {return MOD;}
not {return NOT;}
of {return OF;}
or {return OR;}
procedure {return PROCEDURE;}
program {return PROGRAM;}
record {return RECORD;}
then {return THEN;}
to {return TO;}
type {return TYPE;}
var {return VAR;}
while {return WHILE;}

{id} {yylval = registerSymbol(yytext, "id"); return ID;}
{int} {yylval = registerSymbol(yytext, "int"); return INT;}
{number} {yylval = registerSymbol(yytext, "num");return NUM;}
{string} {yylval = registerSymbol(yytext, "string");return STRING;}

"+" {return OP_ADD;}
"*" {return OP_MUL;}
"-" {return OP_MIN;}
"=" {return OP_RELOP;}
"<" {return OP_LESS;}
"<=" {return OP_LESS_EQ;}
">" {return OP_GREATER;}
">=" {return OP_GREATER_EQ;}
"<>" {return OP_NOT_EQ;}
"." {return DOT;}
"," {return COMMA;}
":" {return COLON;}
";" {return SEMICOLON;}
":=" {return EQUAL;}
".." {return DOUBLE_DOT;}
"(" {return BRACE_L;}
")" {return BRACE_R;}
"[" {return BRACKET_L;}
"]" {return BRACKET_R;}

. {return UNK;}
%%

int main(int argc, char *argv[]){
    argc --;
    argv ++;
    yyin = fopen(argv[0], "r");
    int token = 0;
    while(token = yylex()) {
        printf("Token: %s", symbol_names[token]);
        if(token == ID || token == INT || token == NUM || token == STRING) {
            entry *tableEntry = getSymbolEntryByAddr(yylval);
            printf("  Lexeme: %s  Addr: %ld  Attr: %s", yytext, yylval, tableEntry->attribute);
        }
        printf("\n");
    }
    return 0;
}
