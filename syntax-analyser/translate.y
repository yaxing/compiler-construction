%{
#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;

int parameterCount = 0;

void addCurParamCounter(int delta);

void cleanCurParamCounter();

char * itoa(int a);

%}

%union {
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
}

%token BEGINSYM
%token FORWARD
%token DIV
%token DO
%token ELSE
%token END
%token FOR
%token FUNCTION
%token IF
%token ARRAY
%token MOD
%token NOT
%token OF
%token OR
%token PROCEDURE
%token PROGRAM
%token RECORD
%token THEN
%token TO
%token TYPE
%token VAR
%token WHILE
%token OP_ADD
%token OP_MUL
%token OP_MIN
%token OP_EQUAL
%token OP_LESS
%token OP_LESS_EQ
%token OP_GREATER
%token OP_GREATER_EQ
%token OP_NOT_EQ
%token DOT
%token COMMA
%token COLON
%token SEMICOLON
%token ASSIGN
%token DOUBLE_DOT
%token BRACE_L
%token BRACE_R
%token BRACKET_L
%token BRACKET_R
%token <intType> INT
%token <doubleType> NUM
%token <idEntryType> ID
%token <stringType> STRING
%token AND

%type <idListType> IdentifierList
%type <idEntryType> Type

%%

Program: PROGRAM ID SEMICOLON CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON TypeDefinitions CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON VariableDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON TypeDefinitions VariableDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON VariableDeclarations SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON TypeDefinitions SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAM ID SEMICOLON TypeDefinitions VariableDeclarations SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
;

TypeDefinitions : TYPE TypeDefinitionList {printf("TypeDef_Mul\n");cleanCurParamCounter();}
;

TypeDefinitionList : TypeDefinition SEMICOLON {printf("TypeDefList\n");}
                   | TypeDefinition SEMICOLON TypeDefinitionList {printf("TypeDefList_Multi\n");}
;

VariableDeclarations : VAR VariableDeclarationList 
                        {
                            printf("VarDecl_Mul\n");
                            cleanCurParamCounter();
                        }
;

VariableDeclarationList : VariableDeclaration SEMICOLON {printf("VarDeclList\n");}
                        | VariableDeclaration SEMICOLON VariableDeclarationList {printf("VarDeclList_Mul\n");}
;

SubprogramDeclarations : SubprogramDeclaration SEMICOLON SubprogramDeclarations {printf("SubDecl_mul\n");}
                       | SubprogramDeclaration SEMICOLON {printf("SubDecl_Mul\n");}
;

SubprogramDeclaration : ProcedureDeclaration {printf("SubDeclP\n");}
                      | FunctionDeclaration {printf("SubDeclF\n");}
;

TypeDefinition : ID OP_EQUAL Type {printf("TypeDef: %d %d\n", $1, $3);setSymbolEntyTypeAttr($1, $3, NULL);}
;

VariableDeclaration : IdentifierList COLON Type {
                                                    printf("VarDecl\n");
                                                    setIdListTypeAttr($3, NULL);
                                                }
;

ProcedureDeclaration : PROCEDURE ID BRACE_L FormalParameterList BRACE_R SEMICOLON PFDeclarationFollow 
                    {
                        printf("ProcDecl\n");
                        setSymbolTypeAttrDirec($2, itoa(parameterCount), NULL);
                        cleanCurParamCounter();
                    }
;

FunctionDeclaration : FUNCTION ID BRACE_L FormalParameterList BRACE_R COLON ResultType SEMICOLON PFDeclarationFollow 
                    {
                        printf("FuncDecl\n");
                        printf("setting func: %d %s\n", $2, itoa(parameterCount));
                        setSymbolTypeAttrDirec($2, itoa(parameterCount), NULL);
                        cleanCurParamCounter();
                    }
;

PFDeclarationFollow : Block {printf("PFDecl_Block\n");}
                  | FORWARD {printf("PFDecl_Forward\n");}
;

FormalParameterList : {printf("empty paramlist\n");}
                    | FormalParameterListSingle FormalParameterListMore {
                                                                            printf("FormalPList\n");
                                                                        }
;

FormalParameterListSingle : IdentifierList COLON Type {printf("Plist_single\n");setIdListTypeAttr($3, NULL);}

FormalParameterListMore : SEMICOLON FormalParameterList {printf("PList_M\n");}
                        |
;

Block : CompoundStatement {printf("Block_CompState\n");}
      | VariableDeclarations CompoundStatement {printf("Block_CompSt_V\n");}
;

CompoundStatement : BEGINSYM StatementSequence END {printf("CompStBE\n");}
;

StatementSequence : Statement {printf("SteS\n");}
                  | StatementSequence SEMICOLON Statement {printf("SteSSte\n");}
;

Statement : SimpleStatement {printf("Statement_Simple\n");}
          | StructuredStatement {printf("Statement_Structured\n");}
;

SimpleStatement : AssignmentStatement {printf("SimpleS_AssignState\n");}
                | ProcedureStatement {printf("SimpleSS_ProState\n");}
                |
;

AssignmentStatement : Variable ASSIGN Expression {printf("AssiState\n");}
;

ProcedureStatement : ID BRACE_L ActualParameterList BRACE_R {printf("ProState\n");}
;

StructuredStatement : CompoundStatement {printf("Struc_Comp\n");}
                    | IF Expression THEN Statement {printf("if_else\n");}
                    | IF Expression THEN Statement ELSE Statement {printf("if_else_m\n");}
                    | WHILE Expression DO Statement {printf("while_do\n");}
                    | FOR ID ASSIGN Expression TO Expression DO Statement {printf("for_to\n");}
;

Type : ID {printf("TypeID\n"); $$ = $1;}
     | ARRAY BRACKET_L Constant DOUBLE_DOT Constant BRACKET_R OF Type {printf("Type_Array\n"); $$ = getSymbolEntry("array");}
     | RECORD FormalParameterList END {printf("Type_sub\n"); $$ = getSymbolEntry("record");}
;

ResultType : ID {printf("ResultType\n");}
;

Constant : Sign INT {printf("Constant_SIGN_INT\n");}
         | INT {printf("Constant_INT\n");}
;

Expression : SimpleExpression {printf("Exp_simp\n");}
           | SimpleExpression RelationalOp SimpleExpression {printf("Exp_Simp_Ro\n");}
;

RelationalOp : OP_EQUAL {printf("RelationalOp_EQ\n");}
             | OP_LESS {printf("RelationslOp_Less\n");}
             | OP_LESS_EQ {printf("RelationslOp_LE\n");}
             | OP_GREATER {printf("RelationslOp_G\n");}
             | OP_GREATER_EQ {printf("RelationslOp_GE\n");}
             | OP_NOT_EQ {printf("RelationslOp_NE\n");}
;

SimpleExpression : Sign AddOpTerm {printf("SimpleExp_Sign_AddTerm\n");}
                 | AddOpTerm {printf("SimpleExp_AddTerm\n");}
;

AddOpTerm : Term AddOp Term AddOpTerm {printf("AddOpTerm_Mul\n");}
          | Term {printf("AddOpTerm_Single\n");}
;

AddOp : OP_ADD {printf("AddOp_Add\n");}
      | OP_MIN {printf("AddOp_Min\n");}
      | OR {printf("AddOp_OR\n");}
;

Term : Factor MulOpTerm {printf("Term_Fac_Mul\n");}
;

MulOpTerm : MulOp Term {printf("MulOpTerm\n");}
            |
;

MulOp : OP_MUL {printf("MulOp_MUL\n");}
      | DIV {printf("MulOp_DIV\n");}
      | MOD {printf("MulOp_MOD\n");}
      | AND {printf("MulOp_AND\n");}
;

Factor : INT {printf("Factor_INT\n");}
       | STRING {printf("Factor_String\n");}
       | Variable {printf("Factor_Var\n");}
       | FunctionReference {printf("Factor_FuncRef\n");}
       | NOT Factor {printf("Factor_N_Fac\n");}
       | BRACE_L Expression BRACE_R {printf("Factor_Exp\n");}
;

FunctionReference : ID BRACE_L ActualParameterList BRACE_R {printf("Func_Ref\n");}
;

Variable : ID ComponentSelection {printf("Var\n");}
;

ComponentSelection : DOT ID ComponentSelection {printf("CompSel_Dot\n");}
                   | BRACKET_L Expression BRACKET_R ComponentSelection {printf("CompSel_Exp\n");}
                   |
;

ActualParameterList : Expression ExpressionMore {printf("ActualParamL\n");}
                    | {printf("ActualParamL\n");}
;

ExpressionMore : COMMA Expression ExpressionMore {printf("ExpM\n");}
               |
;

IdentifierList : ID IdentifierListMore {
                                        printf("IdList\n");
                                        addCurParamCounter(1);
                                        appendToIdList($1);
                                       }
;

IdentifierListMore : COMMA IdentifierList {printf("IdListM\n");}
                   |
;

Sign : OP_ADD {printf("Sign_Add\n");}
     | OP_MIN {printf("Sign_Min\n");}
;

%%
yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

void addCurParamCounter(int delta) {
    parameterCount += delta;
}

void cleanCurParamCounter() {
    parameterCount = 0;
}

char * itoa(int a) {
    char * buf = (char *)malloc(sizeof(a) + 1);
    sprintf(buf, "%d", a);
    return buf;
}

int main(int argc, const char * argv[]) {
    FILE * fstream;
    registerKeywords(keywords, 23);
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nParsing...:\n\n");
    fstream = stdout;
    stdout=fopen("parser_debug.out","w");
    yyparse();
    close(stdout);
    stdout = fstream;
    printf("Parsing done (debugging info: parser_debug.out).\n\n");
    stdout=fopen("symtable.out","w");
    printSymbolTable();
    close(stdout);
    stdout = fstream;
    printf("Done, symbole table: symtable.out\n\n");
    close(fstream);
}
