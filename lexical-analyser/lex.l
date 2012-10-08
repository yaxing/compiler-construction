%option noyywrap
%{
    #include<stdio.h>
    #include <string.h>
    #define AND  0;
    #define BEG  1;
    #define FORWARD 2;
    #define DIV  3;
    #define DO  4;
    #define ELSE  5;
    #define END  6;
    #define FOR  7;
    #define FUNCTION  8;
    #define IF  9;
    #define ARRAY  10;
    #define MOD  11;
    #define NOT  12;
    #define OF  13;
    #define OR  14;
    #define PROCEDURE  15;
    #define PROGRAM  16;
    #define RECORD  17;
    #define THEN  18;
    #define TO  19;
    #define TYPE  20;
    #define VAR  21;
    #define WHILE  22;
    #define OP_ADD  23;
    #define OP_MUL  24;
    #define OP_MIN  25;
    #define OP_RELOP  26;
    #define OP_LESS  27;
    #define OP_LESS_EQ  28;
    #define OP_GREATER  29;
    #define OP_GREATER_EQ  30;
    #define OP_NOT_EQ  31;
    #define DOT  32;
    #define COMMA  33;
    #define COLON  34;
    #define SEMICOLON  35;
    #define EQUAL  36;
    #define DOUBLE_DOT  37;
    #define BRACE_L  38;
    #define BRACE_R  39;
    #define BRACKET_L  40;
    #define BRACKET_R  41;
    #define INT 42;
    #define NUM  43;
    #define ID  44;
    #define STRING  45;
    #define UNK  46;
    
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

{id} {return ID;}
{int} {return INT;}
{number} {return NUM;}
{string} {return STRING;}

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
        printf("Token: %s  value: %s\n", symbol_names[token], yytext);
    }
    return 0;
}
