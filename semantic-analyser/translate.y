%{
#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;
    
int const CONTEXT_NORMAL = 0;
int const CONTEXT_ARRAY = 1;
int const CONTEXT_RECORD = 2;

int parameterCount = 0;
int curRecordScopeHash = 0;

int context = 0;
    
idresp *curVarIdResp = NULL;
idresp *curTypeIdResp = NULL;
int curTypeIdDefScopeId = -2;
    
void printLineNo();
    
void yyerror_unequal_type(struct TypeInfo *type1, struct TypeInfo *type2);
    
int getConstantInt(char *sign, int num);

void addCurParamCounter(int delta);

void cleanCurParamCounter();

int setIdListType(struct TypeInfo *retType);

void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType, int paramQty, char *funcProc);

int enterNewScope(struct IdResp *id);

int setSymbolTypeAttr(int idAddr, int typeEntry, typeinfost *typedata, int attrTag);

int typeHandler(idresp **idResp);

int isIdDefined(struct IdResp *id);
    
int certainTypeCheck(struct TypeInfo *type, char *typeToCheck);

int contextSwitch(struct IdResp *idInfo);
    
void resetCurTypeEnvironment();
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
%type <intType> Constant
%type <stringType> Sign
%type <typeinfo> Variable
%type <typeinfo> Type
%type <typeinfo> ResultType
%type <typeinfo> Expression
%type <typeinfo> SimpleExpression
%type <typeinfo> AddOpTerm
%type <typeinfo> Term
%type <typeinfo> Factor
%type <typeinfo> MulOpTerm
%type <typeinfo> ProcFuncStatement
%type <typeinfo> ComponentSelection

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

VariableDeclarations : VAR VariableDeclarationList {
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
    printf("TypeDef: id: %d type: %d tag: %d\n", $1->idEntry, $3->typeEntry, $3->tag);
    if(setSymbolTypeAttr($1->idEntry, $3->typeEntry, $3, ATTR_TYPE) != 0) {
        //YYERROR;
    }
    free($3);
    resetCurTypeEnvironment();
}
;

VariableDeclaration : IdentifierList COLON
                      Type {
                          printf("VarDecl\n");
                          if(setIdListType($3) == 0) {
                            //YYERROR;
                          }
                          free($3);
                      }
;

ProcedureDeclaration : PROCEDURE ID {
                                        char *name = getNameInCurScope($2->idEntry);
                                        if(enterNewScope($2) != 0) {
                                            //YYERROR;
                                        }
                                        //registerSymbolInCurScope(name);
                                    }
                        BRACE_L FormalParameterList BRACE_R 
                        SEMICOLON {
                            printf("setting proc: %d %s\n", $2->idEntry, itoa(funcProcParamCount));
                            handleFuncProcDeclaration($2, NULL, funcProcParamCount, "procedure");
                        }
                        PFDeclarationFollow {
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
                      PFDeclarationFollow {
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

AssignmentStatement : Variable ASSIGN Expression {
    printf("AssiState\n");
    printf("assign var type: %d\n", $1->typeEntry);
    if(!typeCheck($1, $3)) {
        yyerror_unequal_type($1, $3);
    }
}
;

ProcFuncStatement :
                    ID {
                        cleanCurFuncProcCallParamCounter();
                    }
                    BRACE_L ActualParameterList BRACE_R {
                        printf("ProFuncStat\n");
                        int defined;
                        int preDefEntry;
                        char *info;
                        defined = isIdDefined($1);
                        printf("checking func/proc %d %s\n", $1->idEntry, $1->idStr);
                        if(defined == 0) {
                            preDefEntry = getFuncProcDefInParentScope($1->idStr);
                            if(preDefEntry >= 0) {
                                printf("func/proc %s defined in enclosing scope at %d\n",
                                $1->idStr, preDefEntry);
                                removeTailSymbolFromCurScope();
                                $1->idEntry = preDefEntry;
                                $1->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
                                defined = 1;
                            }
                            else {
                                printLineNo();
                                fprintf(stderr, "Undeclared func/proc: %s\n", $1->idStr);
                                //YYERROR;
                            }
                        }
                        if(defined) {
                            info = checkFuncProcCallParamType($1);
                            if(info != NULL) {
                                fprintf(stderr, "%s\n", info);
                                free(info);
                                //YYERROR;
                            }
                        }
                        destroyParamTypeList();
                        cleanCurFuncProcCallParamCounter();
                        constructTypeInfoFromIdResp(&$$, $1);
                        $$->tag = ATTR_VAR;
                    }
;

StructuredStatement : CompoundStatement {printf("Struc_Comp\n");}
                    | IF Expression THEN Statement {printf("if_else\n");}
                    | IF Expression THEN Statement ELSE Statement {printf("if_else_m\n");}
                    | WHILE Expression DO Statement {printf("while_do\n");}
                    | FOR ID ASSIGN Expression TO Expression DO Statement {printf("for_to\n");}
;

Type : ID {
            printf("TypeID %d\n", $1->idEntry);
            typeHandler(&$1);
            constructTypeInfoFromIdResp(&$$, $1);
            $$->tag = ATTR_TYPE;
            printAllSymbolTable();
            curTypeIdResp = $1;
          }
     | ARRAY BRACKET_L Constant DOUBLE_DOT Constant BRACKET_R OF
       Type {
           printf("Type_Array\n");
           $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
           $$->typeEntry = getPredefType("array");
           $$->defScopeId = getCurScopeId();
           $$->attrInfo.arrayInfo.boundLow = $3;
           $$->attrInfo.arrayInfo.boundUp = $5;
           $$->attrInfo.arrayInfo.typeEntry = curTypeIdResp->idEntry;
           $$->attrInfo.arrayInfo.typeDefScopeId = curTypeIdDefScopeId;
           $$->tag = ATTR_TYPE;
       }
     | RECORD {
         printf("Type_Record_Init\n");
         curRecordScopeHash = recordIdHashCode();
         newScopeAndPush(curRecordScopeHash);
         pushRecordHashInStack(curRecordScopeHash);
     }
       FormalParameterList END {
           printf("Type_Record\n");
           $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
           $$->typeEntry = getPredefType("record");
           $$->attrInfo.recordInfo.scopeHashCode = curRecordScopeHash;
           $$->tag = ATTR_TYPE;
           $$->defScopeId = getCurScopeId();
           curRecordScopeHash = handleRecordEnd();
       }
;

ResultType : ID {
                    printf("ResultType\n");
                    typeHandler(&$1);
                    constructTypeInfoFromIdResp(&$$, $1);
                    $$->tag = ATTR_TYPE;
                    printf("return type: %d\n", $$->typeEntry);
                    if($$->typeEntry == 5) {
                        printf("return array type: %d, scope: %d\n", $$->attrInfo.arrayInfo.typeEntry, $$->attrInfo.arrayInfo.typeDefScopeId);
                    }
                }
;

Constant : Sign INT {printf("Constant_SIGN_INT\n"); $$ = getConstantInt($1, $2);}
         | INT {printf("Constant_INT\n"); $$ = getConstantInt(NULL, $1);}
;

Expression : SimpleExpression {
                                printf("Exp_simp\n");
                                $$ = $1;
                                printf("type reduced as %d\n", $$->typeEntry);
                              }
           | SimpleExpression RelationalOp 
             SimpleExpression {
                                printf("Exp_Simp_Ro\n");
                                //check type here $1 & $3
                                //create boolean type
                                $$ = $3;
                                printf("type reduced as %d\n", $$->typeEntry);
                              }
;

RelationalOp : OP_EQUAL {printf("RelationalOp_EQ\n");}
             | OP_LESS {printf("RelationslOp_Less\n");}
             | OP_LESS_EQ {printf("RelationslOp_LE\n");}
             | OP_GREATER {printf("RelationslOp_G\n");}
             | OP_GREATER_EQ {printf("RelationslOp_GE\n");}
             | OP_NOT_EQ {printf("RelationslOp_NE\n");}
;

SimpleExpression : Sign AddOpTerm {
                                    printf("SimpleExp_Sign_AddTerm\n");
                                    $$ = $2;
                                  }
                 | AddOpTerm {
                                printf("SimpleExp_AddTerm\n");
                                $$ = $1;
                                printf("type reduced as %d\n", $$->typeEntry);
                             }
;

AddOpTerm : Term AddOp AddOpTerm {
                                    printf("AddOpTerm_Mul\n");
                                    char *type1;
                                    char *type2;
                                    //check type here $1 & $3
                                    if(typeCheck($1, $3)) {
                                        $$ = $3;
                                        setReduceTypeInfo(&$$, $1, $3, 1);
                                    }
                                    else {
                                        yyerror_unequal_type($1, $3);
                                        setReduceTypeInfo(&$$, $1, $3, 0);
                                    }
                                    printf("type reduced as %d\n", $$->typeEntry);
                                 }
          | Term {
                    printf("AddOpTerm_Single\n");
                    $$ = $1;
                    printf("type reduced as %d\n", $$->typeEntry);
                 }
;

AddOp : OP_ADD {printf("AddOp_Add\n");}
      | OP_MIN {printf("AddOp_Min\n");}
      | OR {printf("AddOp_OR\n");}
;

Term : Factor MulOpTerm {
                            printf("Term_Fac_Mul\n");
                            if(typeCheck($1, $2)) {
                                $$ = $2;
                                setReduceTypeInfo(&$$, $1, $2, 1);
                            }
                            else {
                                yyerror_unequal_type($1, $2);
                                $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                                setReduceTypeInfo(&$$, $1, $2, 0);
                            }
                            printf("type reduced as %d\n", $$->typeEntry);
                        }
     | Factor {
                $$ = $1;
                printf("type reduced as %d\n", $$->typeEntry);
              }
;

MulOpTerm : MulOp Term {
                            printf("MulOpTerm\n");
                            $$ = $2;
                       }
;

MulOp : OP_MUL {printf("MulOp_MUL\n");}
      | DIV {printf("MulOp_DIV\n");}
      | MOD {printf("MulOp_MOD\n");}
      | AND {printf("MulOp_AND\n");}
;

Factor : INT {
                printf("Factor_INT\n");
                $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                $$->typeEntry = getPredefType("integer");
                $$->tag = ATTR_VAR;
             }
       | STRING {
                    printf("Factor_String\n");
                    $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                    $$->typeEntry = getPredefType("string");
                    $$->tag = ATTR_VAR;
                }
       | ProcFuncStatement {
                                printf("Factor_FuncRef\n");
                                $$ = $1;
                           }
       | Variable {
                    printf("Factor_Var\n");
                    $$ = $1;
                  }
       | NOT Factor {
                        printf("Factor_N_Fac\n");
                        $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                        $$->typeEntry = getPredefType("bool");
                        $$->tag = ATTR_VAR;
                    }
       | BRACE_L Expression BRACE_R {
                                        printf("Factor_Exp\n");
                                        $$ = $2;
                                    }
;

Variable :
            ID {
                printf("Var_ID\n");
                int defined = 0;
                int preDefEntry;
                printf("checking var %d %s\n", $1->idEntry, $1->idStr);
                defined = isIdDefined($1);
                if($1->idRespStatus == IDRESP_NORMAL
                && defined == 0) {
                    preDefEntry = getDefInParentScope($1->idStr, ATTR_VAR);
                    if(preDefEntry >= 0) {
                        printf("var %s defined in enclosing scope at %d\n",
                        $1->idStr, preDefEntry);
                        removeTailSymbolFromCurScope();
                        $1->idEntry = preDefEntry;
                        $1->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
                        defined = 1;
                    }
                    else {
                        printLineNo();
                        fprintf(stderr, "Undeclared var: %s\n", $1->idStr);
                        //YYERROR;
                    }
                }
                if(defined) {
                    //enter record scope
                    printf("var id: %s\n", $1->idStr);
                    curVarIdResp = $1;
                }
                else {
                    curVarIdResp = NULL;
                }
            }
            ComponentSelection {
                printf("Var_Comp\n");
                //exit record scope
                if($3->typeEntry == -1) {
                    free($3);
                    constructTypeInfoFromIdResp(&$$, $1);
                }
                else {
                    $$ = $3;
                }
                printf("var type: %d\n", $$->typeEntry);
                //contextSwitch(NULL);
                curVarIdResp = NULL;
            }
;

ComponentSelection :
                     DOT {
                         if(!isTypeConstructor(curVarIdResp, "record")) {
                             fprintf(stderr, "Invalid var: %s is not a record\n", curVarIdResp->idStr);
                         }
                         else {
                             curRecordScopeHash = handleRecordStart(curVarIdResp);
                             if(curRecordScopeHash != 0) {
                                 printf("enter recordhash: %d\n", curRecordScopeHash);
                             }
                         }
                     }
                     Variable {
                         printf("CompSel_Record\n");
                         $$ = $3;
                         curRecordScopeHash = handleRecordEnd();
                         if(curRecordScopeHash != 0) {
                             printf("out recordhash: %d\n", curRecordScopeHash);
                         }
                     }
                   | BRACKET_L {
                       if(!isTypeConstructor(curVarIdResp, "array")) {
                           fprintf(stderr, "Invalid var: structure is not an array\n", curVarIdResp->idStr);
                       }
                   }
                     Expression {
                         if(!certainTypeCheck($3, "integer")) {
                             fprintf(stderr, "Invalid array index\n");
                         }
                     }
                     BRACKET_R {
                         handleArrayVar(&curVarIdResp);
                     }
                     ComponentSelection {
                         printf("CompSel_Array\n");
                         constructTypeInfoFromIdResp(&$$, curVarIdResp);
                         $$->tag = ATTR_VAR;
                     }
                   | {
                       $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                       $$->typeEntry = -1;
                     }
;

ActualParameterList : Expression {
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList($1);
}
                      ExpressionMore {printf("ActualParamL\n");}
                    | {printf("ActualParamL\n");}
;

ExpressionMore : COMMA Expression {
    printf("ExpM\n");
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList($2);
}
                 ExpressionMore
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
    printLineNo();
    fprintf(stderr, "error: %s\n", s);
}

void printLineNo() {
//    fprintf(stderr, "Line: %d  ", getLineNo());
}

void yyerror_unequal_type(struct TypeInfo *typeInfo1, struct TypeInfo *typeInfo2) {
    char *type1;
    char *type2;
    char *tag1;
    char *tag2;
    type1 = getTypeName(typeInfo1);
    type2 = getTypeName(typeInfo2);
    
    switch(typeInfo1->tag) {
        case -1:
            tag1 = "Default";
            break;
        case 0:
            tag1 = "Type";
            break;
        case 1:
            tag1 = "Var";
            break;
    }
    
    switch(typeInfo2->tag) {
        case -1:
        tag2 = "Default";
        break;
        case 0:
        tag2 = "Type";
        break;
        case 1:
        tag2 = "Var";
        break;
    }
    printLineNo();
    fprintf(stderr, "Operation Betwween Incompatiable Types: ");
    fprintf(stderr, "%s(%s), %s(%s)\n", tag1, type1, tag2, type2);
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

int setIdListType(struct TypeInfo *retType) {
    printf("setting idlist\n");
    char *info = NULL;
    info = setIdListTypeAttr(retType->typeEntry, retType->attrInfo, ATTR_VAR);
    printf("set idlist\n");
    destroyCurIdList();
    cleanLatestSetList();
    if(info != NULL) {
        printLineNo();
        fprintf(stderr, "%s\n", info);
        free(info);
        return 0;
    }
    return 1;
}

void handleFuncProcDeclaration(struct IdResp *id, struct TypeInfo *retType, int paramQty, char *funcProc) {
        union SymbolEntryAttr attr;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setFuncVarInScope(id->idStr, id->idEntry, retType->typeEntry, retType->attrInfo);
            registerFunc(id->idEntry, retType->typeEntry, retType->attrInfo, paramQty);
        }
        else {
            registerProc(id->idEntry, paramQty);
        }
        cleanCurParamCounter();
        cleanCurFuncProcCallParamCounter();
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != IDRESP_NORMAL) {
        name = getNameInCurScope(id->idEntry);
        printLineNo();
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry, struct TypeInfo *typedata, int attrTag) {
    int resp;
    char *name;
    entryAttr attr;
    int i = 0;
    if(typeEntry == getPredefType("array")) {
        attr.arrayInfo.boundLow = typedata->attrInfo.arrayInfo.boundLow;
        attr.arrayInfo.boundUp = typedata->attrInfo.arrayInfo.boundUp;
        attr.arrayInfo.typeEntry = typedata->attrInfo.arrayInfo.typeEntry;
        attr.arrayInfo.typeDefScopeId = typedata->attrInfo.arrayInfo.typeDefScopeId;
    }
    if(typeEntry == getPredefType("record")) {
        attr.recordInfo.scopeHashCode = typedata->attrInfo.recordInfo.scopeHashCode;
    }

    resp = setSymbolTypeAttrInCurScope(idAddr, typeEntry, attr, attrTag);
    if(resp == -1) {
        name = getNameInCurScope(idAddr);
        printLineNo();
        fprintf(stderr, "Redefinition of symbol %s\n", name);
        return -1;
    }
    return 0;
}

int typeHandler(struct IdResp **idResp) {
    char *name = "";
    printf("handling type: %s\n", (*idResp)->idStr);
    int entry;
    if((*idResp)->idRespStatus == IDRESP_PREDEF_TYPE) {
        curTypeIdDefScopeId = -2;
        return 1;
    }
    entry = getTypeDefAddr((*idResp)->idStr);
    if(entry >= 0) {
        (*idResp)->idEntry = entry;
        (*idResp)->idRespStatus = IDRESP_NORMAL;
        curTypeIdDefScopeId = getCurScopeId();
        return 1;
    }
    else {
        entry = getTypeDefInParentScope((*idResp)->idStr);
        if(entry >= 0) {
            (*idResp)->idRespStatus = IDRESP_DEF_IN_PARENT;
            (*idResp)->idEntry = entry;
            removeTailSymbolFromCurScope();
            curTypeIdDefScopeId = getParentScopeId();
            return 1;
        }
    }
    printLineNo();
    (*idResp)->idRespStatus = IDRESP_UNDEF;
    (*idResp)->idEntry = -1;
    fprintf(stderr, "Undeclared type: %s\n", (*idResp)->idStr);
    return 0;
}

int isIdDefined(struct IdResp *id) {
    if(getIDTypeStr(id->idEntry) == NULL) {
        return 0;
    }
    return 1;
}

//check if a certain type match
int certainTypeCheck(struct TypeInfo *type, char *typeToCheck) {
    struct TypeInfo *tmp = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
    tmp->typeEntry = getPredefType(typeToCheck);
    tmp->tag = type->tag;
    if(!typeCheck(type, tmp)) {
        return 0;
    }
    return 1;
}

void resetCurTypeEnvironment() {
    curTypeIdResp = NULL;
    curTypeIdDefScopeId = -2;
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
    fstream = stdout;
    stdout=fopen("parser_debug.out","w");
    yyparse();
    close(stdout);
    stdout = fstream;
    printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
    stdout=fopen("symtable.out","w");
    printAllSymbolTable();
    close(stdout);
    stdout = fstream;
    printf("Done, symbole table: symtable.out\n\n");
    close(fstream);
    return 0;
}