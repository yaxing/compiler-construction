%{
#include "header.h"
#include "flex-bison-header.h"
extern FILE *yyin;
extern int count;
extern char* yytext;

int parameterCount = 0;
int funcProcParamCount = 0;

int getConstantInt(char *sign, int num);

void addCurParamCounter(int delta);

void cleanCurParamCounter();

void cleanCurFuncProcParamCounter();

char * itoa(int a);

int setIdListType(struct TypeInfo *retType);

void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType, int paramQty, char *funcProc);

int enterNewScope(struct IdResp *id);

int setSymbolTypeAttr(int idAddr, int typeEntry, typeinfost *typedata);

int typeHandler(idresp *idResp);

int isIdDefined(struct IdResp *id);

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
                                            //YYERROR;
                                        }
                                    }
                                    else {
                                        if(setSymbolTypeAttr($1->idEntry, $3->typeEntry, $3) != 0) {
                                            //YYERROR;
                                        }
                                    }
                                  }
;

VariableDeclaration : IdentifierList COLON Type {
                                                    printf("VarDecl\n");
                                                    if(setIdListType($3) == 0) {
                                                        //YYERROR;
                                                    }
                                                }
;

ProcedureDeclaration : PROCEDURE ID {
                                        char *name = getNameInCurScope($2->idEntry);
                                        if(enterNewScope($2) != 0) {
                                            //YYERROR;
                                        }
                                        registerSymbolInCurScope(name);
                                    } 
                        BRACE_L FormalParameterList BRACE_R 
                        SEMICOLON {
                            printf("setting proc: %d %s\n", $2->idEntry, itoa(funcProcParamCount));
                            handleFuncProcDeclaration($2, NULL, funcProcParamCount, "procedure");
                        }
                        PFDeclarationFollow
                    {
                        printf("ProcDecl\n");
                        popScopeStack();
                    }
;

FunctionDeclaration : FUNCTION ID {
                                    char *name = getNameInCurScope($2->idEntry);
                                    if(enterNewScope($2) != 0) {
                                        //YYERROR;
                                    }
                                    registerSymbolInCurScope(name);
                                   } 
                      BRACE_L FormalParameterList BRACE_R COLON ResultType 
                      SEMICOLON {
                                    printf("setting func: %d %s %d\n", $2->idEntry, itoa(funcProcParamCount), $8->typeEntry);
                                    handleFuncProcDeclaration($2, $8, funcProcParamCount, "function");
                                }
                      PFDeclarationFollow
                    {
                        printf("FuncDecl\n");
                        popScopeStack();
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
                                                        if(setIdListType($3) == 0) {
                                                            //YYERROR;
                                                        }
                                                        funcProcParamCount = parameterCount;
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
                | ProcFuncStatement {printf("SimpleSS_ProState\n");}
                |
;

AssignmentStatement : Variable ASSIGN Expression {printf("AssiState\n");}
;

ProcFuncStatement : ID {} BRACE_L ActualParameterList BRACE_R {printf("ProFuncStat\n");}
;

StructuredStatement : CompoundStatement {printf("Struc_Comp\n");}
                    | IF Expression THEN Statement {printf("if_else\n");}
                    | IF Expression THEN Statement ELSE Statement {printf("if_else_m\n");}
                    | WHILE Expression DO Statement {printf("while_do\n");}
                    | FOR ID ASSIGN Expression TO Expression DO Statement {printf("for_to\n");}
;

Type : ID {
            printf("TypeID\n");
            if(typeHandler($1) == 0) {
                //YYERROR;
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
                    if(typeHandler($1) == 0) {
                        //YYERROR;
                    }
                    $$->typeEntry = $1->idEntry;
                    printf("result type: %d\n", $$->typeEntry);
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
       | ProcFuncStatement {printf("Factor_FuncRef\n");}
       | Variable {printf("Factor_Var\n");}
       | NOT Factor {printf("Factor_N_Fac\n");}
       | BRACE_L Expression BRACE_R {printf("Factor_Exp\n");}
;

Variable : ID {
                int isDefined;
                int preDefEntry;
                printf("Var\n");
                printf("checking var %d %s\n", $1->idEntry, $1->idStr);
                if(isIdDefined($1) == 0) {
                    preDefEntry = getDefInParentScope($1->idStr);
                    if(preDefEntry >= 0) {
                        printf("var %s defined in enclosing scope at %d\n", 
                            $1->idStr, preDefEntry);
                        removeTailSymbolFromCurScope();
                        $1->idEntry = preDefEntry;
                        $1->idRespStatus = -3;//defined in enclosing scope
                    }
                    else {
                        fprintf(stderr, "Undeclared var: %s\n", $1->idStr);
                        //YYERROR;
                    }
                }
              }
            ComponentSelection
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

void cleanCurFuncProcParamCounter() {
    funcProcParamCount = 0;
}

char * itoa(int a) {
    char * buf = (char *)malloc(sizeof(a) + 1);
    sprintf(buf, "%d", a);
    return buf;
}

int setIdListType(struct TypeInfo *retType) {
    char *info = setIdListTypeAttr(retType->typeEntry, retType->attrInfo);
    if(info != NULL) {
        fprintf(stderr, "%s", info);
        return 0;
    }
    return 1;
}

void handleFuncProcDeclaration(struct IdResp *id, struct TypeInfo *retType, int paramQty, char *funcProc) {
        union SymbolEntryAttr attr;
        attr.attr = NULL;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setFuncVarInScope(id->idStr, id->idEntry, retType->typeEntry, attr);
            registerFunc(id->idEntry, retType->typeEntry, retType->attrInfo, paramQty);
        }
        else {
            setSymbolTypeAttrInCurScope(0, getType("NIL"), attr);
            registerProc(id->idEntry, paramQty);
        }
        cleanCurParamCounter();
        cleanCurFuncProcParamCounter();
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
    printf("handling type: %s\n", idResp->idStr);
    int entry;
    if(idResp->idRespStatus == -1) {
        return 1;
    }
    entry = getType(idResp->idStr);
    if(entry >= 0) {
        idResp->idEntry = entry;
        return 1;
    }
    else {
        entry = getTypeInParentScope(idResp->idStr);
        if(entry >= 0) {
            idResp->idEntry = entry;
            idResp->idRespStatus = -2;
            return 1;
        }
    }
    fprintf(stderr, "Invalid type: %s\n", idResp->idStr);
    return 0;
}

int isIdDefined(struct IdResp *id) {
    if(getIDTypeStr(id->idEntry) == NULL) {
        return 0;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    FILE * fstream;
    initTypeDescList();
    initPredefinedSymboltable();
    initScope();
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nParsing...:\n\n");
    //fstream = stdout;
    //stdout=fopen("parser_debug.out","w");
    yyparse();
    //close(stdout);
    //stdout = fstream;
    printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
    //stdout=fopen("symtable.out","w");
    printAllSymbolTable();
    //close(stdout);
    //stdout = fstream;
    printf("Done, symbole table: symtable.out\n\n");
    //close(fstream);
    return 0;
}
