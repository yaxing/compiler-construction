%{
#include "header.h"
#include "flex-bison-header.h"
extern FILE *yyin;
extern int count;
extern char* yytext;

int parameterCount = 0;

int getConstantInt(char *sign, int num);

void addCurParamCounter(int delta);

void cleanCurParamCounter();

char * itoa(int a);

void setIdListType(struct TypeInfo *retType);

void handleFuncProcDeclaration(int idEntry, typeinfost *retType, int paramQty, char *funcProc);

int enterNewScope(struct IdResp *id);

int setSymbolTypeAttr(int idAddr, int typeEntry, typeinfost *typedata);

int typeHandler(idresp *idResp);

%}

%union {
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
    struct IdResp *idrespType;
    struct TypeInfo *typeinfo;
    int paramList[100];
}

%token BEGINSYM
%token FORWARD
%token DIV
%token DO
%token ELSE
%token END
%token FOR
%token <stringType> FUNCTION
%token IF
%token ARRAY
%token MOD
%token NOT
%token OF
%token OR
%token <stringType> PROCEDURE
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
%token <idrespType> ID
%token <stringType> STRING
%token AND
%token NIL
%token TRUE
%token FALSE

%type <idListType> IdentifierList
%type <typeinfo> Type
%type <typeinfo> ResultType
%type <intType> Constant
%type <stringType> Sign

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

TypeDefinition : ID OP_EQUAL Type {
                                    printf("TypeDef: %d %d\n", $1->idEntry, $3->typeEntry);
                                    if($3->additionType != NULL) {
                                        if(setSymbolTypeAttr($1->idEntry, -1, $3) != 0) {
                                            YYERROR;
                                        }
                                    }
                                    else {
                                        if(setSymbolTypeAttr($1->idEntry, $3->typeEntry, $3) != 0) {
                                            YYERROR;
                                        }
                                    }
                                  }
;

VariableDeclaration : IdentifierList COLON Type {
                                                    printf("VarDecl\n");
//                                                    char * resp = setIdListType($3);
//                                                    if(resp != NULL) {
//                                                        yyerror(resp);
//                                                        YYERROR;
//                                                    }
                                                }
;

ProcedureDeclaration : PROCEDURE ID {
                                        char *name = getNameInCurScope($2->idEntry);
                                        if(enterNewScope($2) != 0) {
                                            YYERROR;
                                        }
                                        registerSymbolInCurScope(name, NULL);
                                    } 
                        BRACE_L FormalParameterList BRACE_R SEMICOLON PFDeclarationFollow
                    {
                        printf("ProcDecl\n");
                        printf("setting proc: %d %s\n", $2->idEntry, itoa(parameterCount));
                        handleFuncProcDeclaration($2->idEntry, NULL, parameterCount, "procedure");
                    }
;

FunctionDeclaration : FUNCTION ID {
                                    char *name = getNameInCurScope($2->idEntry);
                                    if(enterNewScope($2) != 0) {
                                        YYERROR;
                                    }
                                    registerSymbolInCurScope(name, NULL);
                                   } 
                      BRACE_L FormalParameterList BRACE_R COLON ResultType SEMICOLON PFDeclarationFollow
                    {
                        printf("FuncDecl\n");
                        printf("setting func: %d %s\n", $2->idEntry, itoa(parameterCount));
                        handleFuncProcDeclaration($2->idEntry, $8, parameterCount, "function");
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

FormalParameterListSingle : IdentifierList COLON Type {
                                                        printf("Plist_single\n");
                                                        setIdListType($3);
                                                      }

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

Type : ID {
            printf("TypeID\n");
            if(typeHandler($1) != 0) {
                YYERROR;
            }
            $$->typeEntry = $1->idEntry;
          }
     | ARRAY BRACKET_L Constant DOUBLE_DOT Constant BRACKET_R OF Type {
                                                                        printf("Type_Array\n"); 
                                                                        $$->typeEntry = $8->typeEntry;
                                                                        $$->additionType = "array";
                                                                        $$->attrInfo.arrayInfo.boundLow = $3;
                                                                        $$->attrInfo.arrayInfo.boundUp = $5;
                                                                      }
     | RECORD FormalParameterList END {
                                        int i = 0;
                                        printf("Type_sub\n"); 
                                        $$->typeEntry = -1;
                                        $$->additionType = "record";
                                        $$->attrInfo.recordInfo.qty = maxSetEntryId;
                                        for(i = 0; i < maxSetEntryId; i ++) {
                                            $$->attrInfo.recordInfo.recordMembers[i] = latestSetEntries[i];
                                        }
                                      }
;

ResultType : ID {
                    printf("ResultType\n");
                    typeHandler($1);
                    $$->typeEntry = $1->idEntry;
                }
;

Constant : Sign INT {printf("Constant_SIGN_INT\n"); $$ = getConstantInt($1, $2);}
         | INT {printf("Constant_INT\n"); $$ = getConstantInt(NULL, $1);}
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

AddOpTerm : Term AddOp AddOpTerm {printf("AddOpTerm_Mul\n");}
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
       | FunctionReference {printf("Factor_FuncRef\n");}
       | Variable {printf("Factor_Var\n");}
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
                                        appendToIdList($1->idEntry);
                                       }
;

IdentifierListMore : COMMA IdentifierList {printf("IdListM\n");}
                   |
;

Sign : OP_ADD {printf("Sign_Add\n"); $$ = "+";}
     | OP_MIN {printf("Sign_Min\n"); $$ = "-";}
;

%%
yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

int getConstantInt(char *sign, int num) {
    if(sign == NULL || strcmp(sign, "+") == 0) {
        return num;
    }
    return 0 - num;
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

void setIdListType(struct TypeInfo *retType) {
    setIdListTypeAttr(retType->typeEntry, retType->attrInfo);
}

void handleFuncProcDeclaration(int idEntry, struct TypeInfo *retType, int paramQty, char *funcProc) {
        union SymbolEntryAttr attr;
        attr.attr = NULL;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setSymbolTypeAttrInCurScope(0, retType->typeEntry, attr);
            popScopeStack();
            registerFunc(idEntry, retType->typeEntry, retType->attrInfo, paramQty);
        }
        else {
            setSymbolTypeAttrInCurScope(0, getType("NIL"), attr);
            popScopeStack();
            registerProc(idEntry, paramQty);
        }
        cleanCurParamCounter();
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != 0) {
        name = getNameInCurScope(id->idEntry);
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry, struct TypeInfo *typedata) {
    int resp;
    char *name;
    entryAttr attr;
    int i = 0;

    if(typedata->additionType != NULL) {
        typeEntry = getType(typedata->additionType);
        if(strcmp(typedata->additionType, "array")) {
            attr.arrayInfo.boundLow = typedata->attrInfo.arrayInfo.boundLow;
            attr.arrayInfo.boundUp = typedata->attrInfo.arrayInfo.boundUp;
            attr.arrayInfo.typeEntry = typedata->typeEntry;
        }
        else if(strcmp(typedata->additionType, "record")) {
            attr.recordInfo.qty = typedata->attrInfo.recordInfo.qty;
            for(i = 0; i < attr.recordInfo.qty; i ++) {
                attr.recordInfo.recordMembers[i] = typedata->attrInfo.recordInfo.recordMembers[i];
            }
        }
    }

    resp = setSymbolTypeAttrInCurScope(idAddr, typeEntry, attr);
    if(resp == -1) {
        name = getNameInCurScope(idAddr);
        fprintf(stderr, "Redefinition of symbol %s\n", name);
        return -1;
    }
    return 0;
}

int typeHandler(struct IdResp *idResp) {
    char *name = "";
    if(idResp->idRespStatus != -1) {
        name = getNameInCurScope(idResp->idEntry);
        fprintf(stderr, "Invalid type: %s\n", name);
        return -1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    FILE * fstream;
    initPredefinedSymboltable();
    initScope();
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
    printAllSymbolTable();
    close(stdout);
    stdout = fstream;
    printf("Done, symbole table: symtable.out\n\n");
    close(fstream);
    return 0;
}
