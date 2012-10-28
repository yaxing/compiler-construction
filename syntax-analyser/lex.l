%option noyywrap
%{
    //
    //  compiler-lexer
    //
    //  Copyright (c) 2012 Yaxing Chen. All rights reserved.
    //
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    #include "translate.tab.h"
    
    enum ERRORTYPE {
        INVALID_ID = -1,
        UNK_CHAR = -2
    };
 
    int lineNo = 0;
%}

line   [\n\r]
delim  [ \t]
letter [a-zA-Z]
char   [.]
digit  [0-9]
id     {letter}({letter}|{digit}|_)*
int    [+-]?{digit}+
string \"[^\"]*\"
ws     {delim}+
number [+-]?{digit}+([\.]{digit}+)?
expnumber {number}[eE]{number}
comments \{[^{}]*\}
invalidId {digit}+{id}

%%
{line} {lineNo ++;}
{ws} {/*discard*/}
{comments} {/*discard*/}

and {return AND;}
if {return IF;}
begin {return BEGINSYM;}
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

{expnumber} {yylval.stringType = yytext; return NUM;}
{invalidId} {yylval.stringType = yytext; return INVALID_ID;}
{id} {
        yylval.idEntryType = registerSymbol(yytext, NULL, NULL);
        return ID;
     }
{int} {yylval.stringType = yytext; return INT;}
{number} {yylval.stringType = yytext; return NUM;}
{string} {yylval.stringType = yytext; return STRING;}

"+" {return OP_ADD;}
"*" {return OP_MUL;}
"-" {return OP_MIN;}
"=" {return OP_EQUAL;}
"<" {return OP_LESS;}
"<=" {return OP_LESS_EQ;}
">" {return OP_GREATER;}
">=" {return OP_GREATER_EQ;}
"<>" {return OP_NOT_EQ;}
"." {return DOT;}
"," {return COMMA;}
":" {return COLON;}
";" {return SEMICOLON;}
":=" {return ASSIGN;}
".." {return DOUBLE_DOT;}
"(" {return BRACE_L;}
")" {return BRACE_R;}
"[" {return BRACKET_L;}
"]" {return BRACKET_R;}

. {yylval.stringType = yytext; return UNK_CHAR;}
%%