%option noyywrap
%{
    //
    //  compiler-lexer
    //
    //  Copyright (c) 2012 Yaxing Chen. All rights reserved.
    //
    
    #include "flex-bison-header.h"
    #include "translate.tab.h"
    
    enum ERRORTYPE {
        INVALID_ID = -1,
        UNK_CHAR = -2
    };
%}

line   [\n\r]
delim  [ \t]
letter [a-zA-Z]
char   [.]
digit  [0-9]
id     {letter}({letter}|{digit}|_)*
int    {digit}+
string \"[^\"]*\"
ws     {delim}+
comments \{[^{}]*\}
invalidId {digit}+{id}

%%
{line} {addLineNo();}
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
function {yylval.stringType = yytext; return FUNCTION;}
array {return ARRAY;}
mod {return MOD;}
not {return NOT;}
of {return OF;}
or {return OR;}
procedure {yylval.stringType = yytext; return PROCEDURE;}
program {return PROGRAM;}
record {return RECORD;}
then {return THEN;}
to {return TO;}
type {return TYPE;}
var {return VAR;}
while {return WHILE;}
NIL {return NIL;}
true {return TRUE;}

{invalidId} {yylval.stringType = yytext; return INVALID_ID;}
{id} {
        printf("registering %s\n", yytext);
        idHandler();
        return ID;
     }
{int} {yylval.intType = atoi(yytext); return INT;}
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

int idHandler() {
    int entry = -1;
    yylval.idrespType = (struct IdResp *)malloc(sizeof(struct IdResp));
    yylval.idrespType->idStr = (char *)malloc(sizeof(yytext));
    strcpy(yylval.idrespType->idStr, yytext);
    entry = getPredefType(yytext);
    if(entry >=0) {
        printf("id %s is predefined-type at %d\n", yytext, entry);
        yylval.idrespType->idEntry = entry;
        yylval.idrespType->idRespStatus = IDRESP_PREDEF_TYPE;
        return 0;
    }
    entry = getPredefineVar(yytext);
    if(entry >= 0) {
        printf("id %s is predefined-keyword at %d\n", yytext, entry);
        yylval.idrespType->idEntry = entry;
        yylval.idrespType->idRespStatus = IDRESP_PREDEF_KEYW;
        return 0;
    }
    entry = registerSymbolInCurScope(yytext);
    yylval.idrespType->idEntry = entry;
    yylval.idrespType->idRespStatus = IDRESP_NORMAL;
    printf("registered %s at %d\n", yytext, entry);
    return 0;
}
