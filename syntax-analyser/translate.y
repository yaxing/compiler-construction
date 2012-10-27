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
%token <stringType> TYPE
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

TypeDefinitions : TYPE TypeDefinitionList {}
;

TypeDefinitionList : TypeDefinition SEMICOLON {}
                   | TypeDefinition SEMICOLON TypeDefinitionList {}
;

VariableDeclarations : VAR VariableDeclarationList
;

VariableDeclarationList : VariableDeclaration SEMICOLON {}
                        | VariableDeclaration SEMICOLON VariableDeclarationList {}
;

SubprogramDeclarations : SubprogramDeclaration SEMICOLON SubprogramDeclaration {}
                       | SubprogramDeclaration SEMICOLON {}
;

SubprogramDeclaration : ProcedureDeclaration {}
                      | FunctionDeclaration {}
;

TypeDefinition : ID OP_EQUAL Type {setSymbolEntyTypeAttr($1, $3, NULL);}
;

VariableDeclaration : IdentifierList COLON Type {
                                                    setIdListTypeAttr($3, NULL);
                                                }
;

ProcedureDeclaration : PROCEDURE ID BRACE_L FormalParameterList BRACE_R SEMICOLON PFDeclarationFollow {}
;

FunctionDeclaration : FUNCTION ID BRACE_L FormalParameterList BRACE_R COLON ResultType SEMICOLON PFDeclarationFollow {}
;

PFDeclarationFollow : Block {}
                  | FORWARD {}
;

FormalParameterList : IdentifierList COLON Type FormalParameterListMore {
                                                                            setIdListTypeAttr($3, NULL);
                                                                        }
                    |
;

FormalParameterListMore : SEMICOLON IdentifierList COLON Type FormalParameterListMore {
                                                                                        setIdListTypeAttr($4, NULL);
                                                                                      }
                        |
;

Block : CompoundStatement {}
      | VariableDeclarations CompoundStatement {}
;

CompoundStatement : BEGINSYM StatementSequence END {}
;

StatementSequence : Statement {}
                  | StatementSequence SEMICOLON Statement {}
;

Statement : SimpleStatement {}
          | StructuredStatement {}
;

SimpleStatement : AssignmentStatement
                | ProcedureStatement
                |
;

AssignmentStatement : Variable ASSIGN Expression {}
;

ProcedureStatement : ID BRACE_L ActualParameterList BRACE_R {}
;

StructuredStatement : CompoundStatement {}
                    | IF Expression THEN Statement {}
                    | IF Expression THEN Statement ELSE Statement {}
                    | WHILE Expression DO Statement {}
                    | FOR ID ASSIGN Expression TO Expression DO Statement {}
;

Type : ID {setSymbolTypeAttrDirec($1, NULL, NULL);}
     | ARRAY BRACKET_L Constant DOUBLE_DOT Constant BRACKET_R OF Type {}
     | RECORD FormalParameterList END {}
;

ResultType : ID {}
;

Constant : Sign INT {}
         | INT {}
;

Expression : SimpleExpression {}
           | SimpleExpression RelationalOp SimpleExpression {}
;

RelationalOp : OP_EQUAL {}
             | OP_LESS {}
             | OP_LESS_EQ {}
             | OP_GREATER {}
             | OP_GREATER_EQ {}
             | OP_NOT_EQ {}
;

SimpleExpression : Sign AddOpTerm {}
                 | AddOpTerm {}
;

AddOpTerm : Term AddOp Term AddOpTerm {}
          | Term
;

AddOp : OP_ADD {}
      | OP_MIN {}
      | OR {}
;

Term : Factor MulOpTerm {}
;

MulOpTerm : MulOp Term {}
            |
;

MulOp : OP_MUL {}
      | DIV {}
      | MOD {}
      | AND {}
;

Factor : INT {}
       | STRING {}
       | Variable {}
       | FunctionReference {}
       | NOT Factor {}
       | BRACE_L Expression BRACE_R {}
;

FunctionReference : ID BRACE_L ActualParameterList BRACE_R {}
;

Variable : ID ComponentSelection {}
;

ComponentSelection : DOT ID ComponentSelection {}
                   | BRACKET_L Expression BRACKET_R ComponentSelection {}
                   |
;

ActualParameterList : Expression ExpressionMore {}
                    |
;

ExpressionMore : COMMA Expression ExpressionMore {}
               |
;

IdentifierList : ID IdentifierListMore {
                                        addCurParamCounter(1);
                                        appendToIdList($1);
                                       }
;

IdentifierListMore : COMMA ID IdentifierListMore {
                                                    addCurParamCounter(1); 
                                                    appendToIdList($2);
                                                 }
                   |
;

Sign : OP_ADD {}
     | OP_MIN {}
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
    //registerKeywords(keywords, 23);
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nParsing...:\n\n");
//    freopen("rule.out","w",stdout);
    yyparse();

//    freopen("symtable.out","w",stdout);
    printf("done.\n");
    printf("\n\nSymbol Table:\n");
    printSymbolTable();
    int i;
}
