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
    
    curArrayType *curArrayTypeInfo = NULL;
    
    //this is for inter-code gen for
    //recursive Variable component selection
    char *curVar = NULL;
    // this is for maintain correct quadtable
    // before enter record scope
    quadrupleTable *curQuadTableForVar = NULL;

    //===declaration for funcs in translate.y===//
    
    void yyerror_unequal_type(struct TypeInfo *type1, struct TypeInfo *type2);
    
    int getConstantInt(char *sign, int num);

    void addCurParamCounter(int delta);

    void cleanCurParamCounter();

    int setIdListType(struct TypeInfo *retType);

    void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType,
                                   int paramQty, char *funcProc);
    
    void finishFuncProcDeclaration(struct IdResp *id, char *funcProc);

    int enterNewScope(struct IdResp *id);

    int setSymbolTypeAttr(int idAddr, int typeEntry,
                          typeinfost *typedata, int attrTag);

    int typeHandler(idresp **idResp);

    int isIdDefined(struct IdResp *id);
    
    int certainTypeCheck(struct TypeInfo *type, char *typeToCheck);

    int contextSwitch(struct IdResp *idInfo);
    
    void resetCurTypeEnvironment();
    
    void handleBinop(struct TypeInfo **ruleHead,
                     struct TypeInfo *op1,
                     struct TypeInfo *op2,
                     char *operator,
                     char *designatedRuleHeadType);
    
    void handleUnaryOpICTable(struct TypeInfo **ruleHead,
                              struct TypeInfo *op1,
                              char *operator);
    
    void handleAssignStatement(struct TypeInfo *assignTo,
                               struct TypeInfo *assignFrom);
%}

%union {
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
    struct IdResp *idrespType;
    struct TypeInfo *typeinfo;
    struct STRUCTUREDSTATEMENT *structuredStatementHeadType;
    int paramList[100];
}

%token BEGINSYM
%token FORWARD
%token DIV
%token DO
%token ELSE
%token END
%token <structuredStatementHeadType> FOR
%token <stringType> FUNCTION
%token <structuredStatementHeadType> IF
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
%token <structuredStatementHeadType> WHILE
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
%type <typeinfo> ProcFuncStatement
%type <typeinfo> ComponentSelection
%type <stringType> MulOp
%type <stringType> AddOp
%type <stringType> RelationalOp
%type <structuredStatementHeadType> IfThenStatement

%%

Program: PROGRAM ID SEMICOLON CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON TypeDefinitions CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON VariableDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON SubprogramDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON TypeDefinitions VariableDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON VariableDeclarations SubprogramDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON TypeDefinitions SubprogramDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
| PROGRAM ID SEMICOLON TypeDefinitions VariableDeclarations SubprogramDeclarations CompoundStatement DOT {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_RETURN, NULL, NULL, NULL);
}
;


TypeDefinitions : TYPE TypeDefinitionList {
    if(MODE_DEBUG == 1) {
        printf("TypeDef_Mul\n");
    }
    cleanCurParamCounter();
}
;


TypeDefinitionList : TypeDefinition SEMICOLON {
    if(MODE_DEBUG == 1) {
        printf("TypeDefList\n");
    }
}
| TypeDefinition SEMICOLON TypeDefinitionList {
    if(MODE_DEBUG == 1) {
        printf("TypeDefList_Multi\n");
    }
}
;


VariableDeclarations : VAR VariableDeclarationList {
    if(MODE_DEBUG == 1){
        printf("VarDecl_Mul\n");
    }
    cleanCurParamCounter();
}
;


VariableDeclarationList : VariableDeclaration SEMICOLON {
    if(MODE_DEBUG == 1) {
        printf("VarDeclList\n");
    }
}
| VariableDeclaration SEMICOLON VariableDeclarationList {
    if(MODE_DEBUG == 1) {
        printf("VarDeclList_Mul\n");
    }
}
;


SubprogramDeclarations : SubprogramDeclaration SEMICOLON SubprogramDeclarations {
    if(MODE_DEBUG == 1) {
        printf("SubDecl_mul\n");
    }
}
| SubprogramDeclaration SEMICOLON {
    if(MODE_DEBUG == 1) {
        printf("SubDecl_Mul\n");
    }
}
;


SubprogramDeclaration : ProcedureDeclaration {
    if(MODE_DEBUG == 1) {
        printf("SubDeclP\n");
    }
}
    | FunctionDeclaration {
        if(MODE_DEBUG == 1) {
            printf("SubDeclF\n");
        }
    }
;


TypeDefinition : ID OP_EQUAL Type {
    if(MODE_DEBUG == 1){
        printf("TypeDef: id: %d type: %d tag: %d\n",
               $1->idEntry, $3->typeEntry, $3->tag);
    }
    if(setSymbolTypeAttr($1->idEntry, $3->typeEntry, $3, ATTR_TYPE) != 0) {
        //YYERROR;
    }
    free($3);
    resetCurTypeEnvironment();
}
;


VariableDeclaration : IdentifierList COLON Type {
    if(MODE_DEBUG == 1){
        printf("VarDecl\n");
    }
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
    cleanCurFuncProcCallParamCounter();
}

BRACE_L FormalParameterList BRACE_R SEMICOLON {
    if(MODE_DEBUG == 1){
        printf("setting proc: %d %s\n", $2->idEntry, itoa(funcProcParamCount));
    }
    handleFuncProcDeclaration($2, NULL, funcProcParamCount, "procedure");
}

PFDeclarationFollow {
    if(MODE_DEBUG == 1){
        printf("ProcDecl\n");
    }
    finishFuncProcDeclaration($2, "procedure");
    popScopeStack();
}
;


FunctionDeclaration : FUNCTION ID {
    char *name = getNameInCurScope($2->idEntry);
    if(enterNewScope($2) != 0) {
        //YYERROR;
    }
    registerSymbolInCurScope(name);
    cleanCurFuncProcCallParamCounter();
} 

BRACE_L FormalParameterList BRACE_R COLON ResultType SEMICOLON {
    if(MODE_DEBUG == 1){
        printf("setting func: %d %s %d\n",
               $2->idEntry, itoa(funcProcParamCount), $8->typeEntry);
    }
    handleFuncProcDeclaration($2, $8, funcProcParamCount, "function");
}

PFDeclarationFollow {
    if(MODE_DEBUG == 1){
        printf("FuncDecl\n");
    }
    finishFuncProcDeclaration($2, "function");
    popScopeStack();
}
;


PFDeclarationFollow : Block {
    if(MODE_DEBUG == 1) {
        printf("PFDecl_Block\n");
    }
}

| FORWARD {
    if(MODE_DEBUG == 1) {
        printf("PFDecl_Forward\n");
    }
}
;


FormalParameterList : {
    if(MODE_DEBUG == 1){
        printf("empty paramlist\n");
    }
}

| FormalParameterListSingle FormalParameterListMore {
    if(MODE_DEBUG == 1){printf("FormalPList\n");}
}
;


FormalParameterListSingle : IdentifierList COLON Type {
    if(MODE_DEBUG == 1){
        printf("Plist_single\n");
    }
    if(setIdListType($3) == 0) {
        //YYERROR;
    }
    funcProcParamCount = parameterCount;
}

FormalParameterListMore : SEMICOLON FormalParameterList {
    if(MODE_DEBUG == 1) {
        printf("PList_M\n");
    }
}

|
;


Block : CompoundStatement {
    if(MODE_DEBUG == 1) {
        printf("Block_CompState\n");
    }
}
| VariableDeclarations CompoundStatement {
    if(MODE_DEBUG == 1) {
        printf("Block_CompSt_V\n");
    }
}
;


CompoundStatement : BEGINSYM StatementSequence END {
    if(MODE_DEBUG == 1) {
        printf("CompStBE\n");
    }
}
;


StatementSequence : Statement {
    if(MODE_DEBUG == 1) {
        printf("SteS\n");
    }
}
| StatementSequence SEMICOLON Statement {
    if(MODE_DEBUG == 1) {
        printf("SteSSte\n");
    }
}
;


Statement : SimpleStatement {
    if(MODE_DEBUG == 1) {
        printf("Statement_Simple\n");
    }
}
| StructuredStatement {
    if(MODE_DEBUG == 1) {
        printf("Statement_Structured\n");
    }
}
;

SimpleStatement : AssignmentStatement {
    if(MODE_DEBUG == 1) {
        printf("SimpleS_AssignState\n");
    }
}

| ProcFuncStatement {
    if(MODE_DEBUG == 1) {
        printf("SimpleSS_ProState\n");
    }
    free($1);
}

|
;


AssignmentStatement : Variable ASSIGN Expression {
    if(MODE_DEBUG == 1){
        printf("AssiState\n");
        printf("assign var type: %d\n", $1->typeEntry);
    }
    handleAssignStatement($1, $3);
}
;


ProcFuncStatement : ID {
    cleanCurFuncProcCallParamCounter();
}

BRACE_L ActualParameterList BRACE_R {
    int defined;
    int preDefEntry;
    char *info;
    defined = isIdDefined($1);
    if(MODE_DEBUG == 1){
        printf("ProFuncStat\n");
        printf("checking func/proc %d %s\n", $1->idEntry, $1->idStr);
    }
    if(defined == 0) {
        preDefEntry = getFuncProcDefInParentScope($1->idStr);
        if(preDefEntry >= 0) {
            if(MODE_DEBUG == 1){
                printf("func/proc %s defined in enclosing scope at %d\n",
                       $1->idStr, preDefEntry);
            }
            removeTailSymbolFromCurScope();
            $1->idEntry = preDefEntry;
            $1->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
            defined = 1;
        }
        else {
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
    constructTypeInfoFromIdResp(&$$, $1);
    $$->tag = ATTR_VAR;
    handleFuncProcCallIntermediateCode(&$$);
    destroyParamTypeList();
    cleanCurFuncProcCallParamCounter();
    //put in table, create tmp
}
;


StructuredStatement : CompoundStatement {
    if(MODE_DEBUG == 1) {
        printf("Struc_Comp\n");
    }
}

| IfThenStatement {
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->falseLabel), NULL, NULL);
}

| IfThenStatement ELSE {
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_GOTO,
                    buildStrArg($1->nextLabel), NULL, NULL);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->falseLabel), NULL, NULL);
}
Statement {
    if(MODE_DEBUG == 1){
        printf("if_else_m\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->nextLabel), NULL, NULL);
}

| WHILE {
    $1 = buildstructuredStatementHeadType();
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->trueLabel), NULL, NULL);
}
Expression {
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_IF,
                    NULL, NULL,
                    buildStrArg($1->nextLabel));
}
DO Statement {
    if(MODE_DEBUG == 1){printf("while_do\n");}
    if(!certainTypeCheck($3, "boolean")) {
        fprintf(stderr, "While Condition is not boolean\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_GOTO,
                    buildStrArg($1->trueLabel), NULL, NULL);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->nextLabel), NULL, NULL);
}

| FOR {
    $1 = buildstructuredStatementHeadType();
}
ID ASSIGN Expression {
    insertQuadruple(getCurQueadrupleTable(), ":=", buildStrArg($5->code),
                    NULL,
                    buildStrArg($3->idStr));
}
TO Expression {
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->trueLabel), NULL, NULL);
    insertQuadruple(getCurQueadrupleTable(), "<",
                    buildStrArg($3->idStr), buildStrArg($8->code),
                    NULL);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_IF,
                    NULL, NULL,
                    buildStrArg($1->nextLabel));
}
DO Statement {
    if(MODE_DEBUG == 1){printf("for_to\n");}
    struct TypeInfo *idType;
    constructTypeInfoFromIdResp(&idType, $3);
    if(!typeCheck(idType, $5)) {
        yyerror_unequal_type(idType, $5);
    }
    free(idType);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_GOTO,
                    buildStrArg($1->trueLabel), NULL, NULL);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->nextLabel), NULL, NULL);
}
;


IfThenStatement : IF {
    $1 = buildstructuredStatementHeadType();
}
Expression {
    if(!certainTypeCheck($3, "boolean")) {
        fprintf(stderr, "If Condition is not boolean\n");
    }
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_IF,
                    NULL, NULL,
                    buildStrArg($1->trueLabel));
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_GOTO,
                    buildStrArg($1->falseLabel), NULL, NULL);
    insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                    buildStrArg($1->trueLabel), NULL, NULL);
    free($3);
} THEN Statement {
    if(MODE_DEBUG == 1){
        printf("if_else\n");
    }
    $$ = $1;
}
;


Type : ID {
    if(MODE_DEBUG == 1){
        printf("TypeID %d\n", $1->idEntry);
    }
    typeHandler(&$1);
    constructTypeInfoFromIdResp(&$$, $1);
    $$->tag = ATTR_TYPE;
    if(MODE_DEBUG == 1) {
        printAllSymbolTable();
    }
    curTypeIdResp = $1;
}

| ARRAY BRACKET_L Constant DOUBLE_DOT Constant BRACKET_R OF Type {
    if(MODE_DEBUG == 1){
        printf("Type_Array\n");
    }
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
    if(MODE_DEBUG == 1){
        printf("Type_Record_Init\n");
    }
    curRecordScopeHash = recordIdHashCode();
    newScopeAndPush(curRecordScopeHash);
    pushRecordHashInStack(curRecordScopeHash);
}

FormalParameterList END {
    if(MODE_DEBUG == 1){
        printf("Type_Record\n");
    }
    $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    $$->typeEntry = getPredefType("record");
    $$->attrInfo.recordInfo.scopeHashCode = curRecordScopeHash;
    $$->tag = ATTR_TYPE;
    $$->defScopeId = getCurScopeId();
    curRecordScopeHash = handleRecordEnd();
}
;


ResultType : ID {
    if(MODE_DEBUG == 1){
        printf("ResultType\n");
    }
    typeHandler(&$1);
    constructTypeInfoFromIdResp(&$$, $1);
    $$->tag = ATTR_TYPE;
    if(MODE_DEBUG == 1){
        printf("return type: %d\n", $$->typeEntry);
    }
    if($$->typeEntry == 5) {
        if(MODE_DEBUG == 1){
            printf("return array type: %d, scope: %d\n",
                   $$->attrInfo.arrayInfo.typeEntry,
                   $$->attrInfo.arrayInfo.typeDefScopeId);
        }
    }
}
;


Constant : Sign INT {
    if(MODE_DEBUG == 1) {
        printf("Constant_SIGN_INT\n");
    }
    $$ = getConstantInt($1, $2);
}

| INT {
    if(MODE_DEBUG == 1) {
        printf("Constant_INT\n");
    }
    $$ = getConstantInt(NULL, $1);
}
;


Expression : SimpleExpression {
    $$ = $1;
    if(MODE_DEBUG == 1){
        printf("Exp_simp\n");
        printf("type reduced as %d\n", $$->typeEntry);
    }
}

| SimpleExpression RelationalOp SimpleExpression {
    handleBinop(&$$, $1, $3, $2, "boolean");
    if(MODE_DEBUG == 1){
        printf("Exp_Simp_Ro\n");
        printf("type reduced as %d\n", $$->typeEntry);
    }
}
;


RelationalOp : OP_EQUAL {
    if(MODE_DEBUG == 1) {
        printf("RelationalOp_EQ\n");
    }
    $$ = "=";
}

| OP_LESS {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_Less\n");
    }
    $$ = "<";
}

| OP_LESS_EQ {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_LE\n");
    }
    $$ = "<=";
}

| OP_GREATER {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_G\n");
    }
    $$ = ">";
}

| OP_GREATER_EQ {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_GE\n");
    }
    $$ = ">=";
}

| OP_NOT_EQ {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_NE\n");
    }
    $$ = "<>";
}
;


SimpleExpression : Sign AddOpTerm {
    if(MODE_DEBUG == 1){
        printf("SimpleExp_Sign_AddTerm\n");
    }
    $$ = $2;
    handleUnaryOpICTable(&$$, $2, $1);
}

| AddOpTerm {
    if(MODE_DEBUG == 1){
        printf("SimpleExp_AddTerm\n");
        printf("type reduced as %d\n", $$->typeEntry);
    }
    $$ = $1;
}
;


AddOpTerm : Term AddOp AddOpTerm {
    if(MODE_DEBUG == 1){
        printf("AddOpTerm_Mul\n");
    }
    handleBinop(&$$, $1, $3, $2, NULL);
    if(MODE_DEBUG == 1){
        printf("type reduced as %d\n", $$->typeEntry);
    }
}

| Term {
    $$ = $1;
    if(MODE_DEBUG == 1){
        printf("AddOpTerm_Single\n");
        printf("type reduced as %d\n", $$->typeEntry);
    }
}
;


AddOp : OP_ADD {
    if(MODE_DEBUG == 1) {
        printf("AddOp_Add\n");
    }
    $$ = "+";
}

| OP_MIN {
    if(MODE_DEBUG == 1) {
        printf("AddOp_Min\n");
    }
    $$ = "-";
}

| OR {
    if(MODE_DEBUG == 1) {
        printf("AddOp_OR\n");
    }
    $$ = "or";
}
;


Term : Factor MulOp Term {
    if(MODE_DEBUG == 1){
        printf("Term_Fac_Mul\n");
    }
    handleBinop(&$$, $1, $3, $2, NULL);
    if(MODE_DEBUG == 1){
        printf("type reduced as %d\n", $$->typeEntry);
    }
}

| Factor {
    if(MODE_DEBUG == 1){
        printf("Term_Factor\n");
        printf("type reduced as %d\n", $$->typeEntry);
    }
    $$ = $1;
}
;


MulOp : OP_MUL {
    if(MODE_DEBUG == 1) {
        printf("MulOp_MUL\n");
    }
    $$ = "*";
}

| DIV {
    if(MODE_DEBUG == 1) {
        printf("MulOp_DIV\n");
    }
    $$ = "/";
}

| MOD {
    if(MODE_DEBUG == 1) {
        printf("MulOp_MOD\n");
    }
    $$ = "%";
}

| AND {
    if(MODE_DEBUG == 1) {
        printf("MulOp_AND\n");
    }
    $$ = "and"
}
;


Factor : INT {
    if(MODE_DEBUG == 1){
        printf("Factor_INT\n");
    }
    $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    $$->typeEntry = getPredefType("integer");
    $$->tag = ATTR_VAR;
    $$->code = itoa(yylval.intType);
    printf("int: %d %s\n\n", $$->typeEntry, $$->code);
}

| STRING {
    if(MODE_DEBUG == 1){
    printf("Factor_String\n");
    }
    $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    $$->typeEntry = getPredefType("string");
    $$->tag = ATTR_VAR;
    $$->code = strcpy2(yylval.stringType);
    printf("String: %d %s\n", $$->typeEntry, $$->code);
}

| ProcFuncStatement {
    if(MODE_DEBUG == 1){
        printf("Factor_FuncRef\n");
    }
    $$ = $1;
}

| Variable {
    if(MODE_DEBUG == 1){
        printf("Factor_Var\n");
    }
    $$ = $1;
}

| NOT Factor {
    if(MODE_DEBUG == 1){
        printf("Factor_N_Fac\n");
    }
    $$ = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    $$->typeEntry = getPredefType("boolean");
    $$->tag = ATTR_VAR;
    handleUnaryOpICTable(&$$, $2, "not");
    free($2);
}

| BRACE_L Expression BRACE_R {
    if(MODE_DEBUG == 1){
        printf("Factor_Exp\n");
    }
    $$ = $2;
}
;


Variable : ID {
    arg *argTmp;
    char *tmp;
    if(MODE_DEBUG == 1){
        printf("Var_ID\n");
        printf("checking var %d %s\n", $1->idEntry, $1->idStr);
    }
    int defined = 0;
    int preDefEntry;
    defined = isIdDefined($1);
    if($1->idRespStatus == IDRESP_NORMAL
        && !defined) {
        preDefEntry = getDefInParentScope($1->idStr, ATTR_VAR);
        if(preDefEntry >= 0) {
            if(MODE_DEBUG == 1){
                printf("var %s defined in enclosing scope at %d\n", $1->idStr, preDefEntry);
            }
            removeTailSymbolFromCurScope();
            $1->idEntry = preDefEntry;
            $1->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
            defined = 1;
        }
        else {
            fprintf(stderr, "Undeclared var: %s\n", $1->idStr);
            //YYERROR;
        }
    }
    if(defined) {
        //enter record scope
        curVarIdResp = $1;
        if(MODE_DEBUG == 1){
            printf("var id: %s\n", $1->idStr);
            printf("curVarIdResp changed to: %d\n", curVarIdResp->idEntry);
        }
    }
    else {
        curVarIdResp = NULL;
        if(MODE_DEBUG == 1){
            printf("curVarIdResp changed to: NULL\n");
        }
    }
    
    //intermediate code gen
    if(curVar == NULL
       && curQuadTableForVar == NULL) {
        curVar = $1->idStr;
        curQuadTableForVar = getCurQueadrupleTable();
    }
    else {
        //only one case: record component happened at
        //previous recursion
        argTmp = buildStrArg(strcat2(strcat2(curVar, "."), $1->idStr));
        tmp = createTmp();
        insertQuadruple(curQuadTableForVar, ":=", argTmp, NULL,
                        buildStrArg(tmp));
        curVar = tmp;
    }
}

ComponentSelection {
    if(MODE_DEBUG == 1){
        printf("Var_Comp\n");
    }
    //exit record scope
    if($3->typeEntry == -1) {
        free($3);
        constructTypeInfoFromIdResp(&$$, $1);
        $$->tag = ATTR_VAR;
        $$->code = curVar;
        curVar = NULL;
        curQuadTableForVar = NULL;
    }
    else {
        $$ = $3;
    }
    if(MODE_DEBUG == 1){
        printf("var type: %d\n", $$->typeEntry);
    }
}
;


ComponentSelection : DOT {
    if(!isTypeConstructor(curVarIdResp, "record")) {
        fprintf(stderr, "Invalid var: %s is not a record\n", curVarIdResp->idStr);
    }
    else {
        curRecordScopeHash = handleRecordStart(curVarIdResp);
        if(curRecordScopeHash != 0) {
            if(MODE_DEBUG == 1){
            printf("enter recordhash: %d\n", curRecordScopeHash);
            }
        }
    }
}

Variable {
    if(MODE_DEBUG == 1){
        printf("CompSel_Record\n");
    }
    $$ = $3;
    $$->code = curVar;
    curRecordScopeHash = handleRecordEnd();
    if(curRecordScopeHash != 0) {
        if(MODE_DEBUG == 1){
            printf("out recordhash: %d\n", curRecordScopeHash);
        }
    }
    if(MODE_DEBUG) {
        printf("reduced as type: %d\n", $3->typeEntry);
    }
}

| BRACKET_L {
    if(!isTypeConstructor(curVarIdResp, "array")) {
        fprintf(stderr, "Invalid var: structure is not an array\n", curVarIdResp->idStr);
    }
    else {
         pushArrayIdRespInStack(curVarIdResp);
    }
}

Expression {
      if(!certainTypeCheck($3, "integer")) {
          fprintf(stderr, "Invalid array index\n");
      }
}

BRACKET_R {
    char *tmp;
    curArrayTypeInfo = NULL;
    curVarIdResp = popArrayIdResp();
    handleArrayVar(&curVarIdResp, &curArrayTypeInfo);
    if(MODE_DEBUG) {
        printf("curVarIdResp changed to: %d\n", curVarIdResp->idEntry);
    }
    curVar = strcat2(curVar, "[");
    curVar = strcat2(curVar, $3->code);
    curVar = strcat2(curVar, "]");
    tmp = createTmp();
    insertQuadruple(curQuadTableForVar, ":=", buildStrArg(curVar),
                    NULL, buildStrArg(tmp));
    curVar = tmp;
}

ComponentSelection {
    if(MODE_DEBUG == 1){
        printf("CompSel_Array\n");
    }
    if($7->typeEntry == -1) {
        constructTypeInfoFromArrayTypeInfo(&$$, curArrayTypeInfo);
        free(curArrayTypeInfo);
    }
    else {
        $$ = $7;
    }
    $$->tag = ATTR_VAR;
    if(MODE_DEBUG) {
        printf("reduced as type: %d\n", $3->typeEntry);
    }
    $$->code = curVar;
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

ExpressionMore {
    if(MODE_DEBUG == 1) {
        printf("ActualParamL\n");
    }
}

| {
    if(MODE_DEBUG == 1) {
        printf("ActualParamL\n");
    }
}
;


ExpressionMore : COMMA Expression {
    if(MODE_DEBUG == 1){
        printf("ExpM\n");
    }
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList($2);
}

ExpressionMore

|
;


IdentifierList : ID IdentifierListMore {
    if(MODE_DEBUG == 1){
        printf("IdList\n");
    }
    addCurParamCounter(1);
    appendToIdList($1->idEntry);
}
;


IdentifierListMore : COMMA IdentifierList {
    if(MODE_DEBUG == 1) {
        printf("IdListM\n");
    }
}

|
;


Sign : OP_ADD {
    if(MODE_DEBUG == 1) {
        printf("Sign_Add\n");
    }
    $$ = "+";
}

| OP_MIN {
    if(MODE_DEBUG == 1){
        printf("Sign_Min\n");
    }
    $$ = "-";
}
;


%%

yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}

void yyerror_unequal_type(struct TypeInfo *typeInfo1,
                          struct TypeInfo *typeInfo2) {
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
    if(MODE_DEBUG == 1){
        printf("setting idlist\n");
    }
    char *info = NULL;
    info = setIdListTypeAttr(retType->typeEntry, retType->attrInfo, ATTR_VAR);
    if(MODE_DEBUG == 1){
        printf("set idlist\n");
    }
    destroyCurIdList();
    cleanLatestSetList();
    if(info != NULL) {
        fprintf(stderr, "%s\n", info);
        free(info);
        return 0;
    }
    return 1;
}

void handleFuncProcDeclaration(struct IdResp *id,
                               struct TypeInfo *retType,
                               int paramQty,
                               char *funcProc) {
        union SymbolEntryAttr attr;
        union ARGINFO quadArg1;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setFuncVarInScope(id->idStr, id->idEntry,
                              retType->typeEntry, retType->attrInfo);
            registerFunc(id->idEntry, retType->typeEntry,
                         retType->attrInfo, paramQty);
        }
        else {
            registerProc(id->idEntry, paramQty);
        }
        cleanCurParamCounter();
        cleanCurFuncProcCallParamCounter();

        quadArg1.strInfo = strcpy2(id->idStr);
        insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL,
                        buildArg(ARGTYPE_VAR_STR, quadArg1), NULL, NULL);
}
    
void finishFuncProcDeclaration(struct IdResp *id, char *funcProc) {
    char *op = QUAD_OP_RETURN;
    arg *returnArg = NULL;
    if(strcmp(funcProc, "function") == 0) {
        op = QUAD_OP_FUNRETURN;
        returnArg = buildStrArg(id->idStr);
    }
    insertQuadruple(getCurQueadrupleTable(), op,
                    returnArg, NULL, NULL);
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != IDRESP_NORMAL) {
        name = getNameInCurScope(id->idEntry);
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry,
                      struct TypeInfo *typedata, int attrTag) {
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
        fprintf(stderr, "Redefinition of symbol %s\n", name);
        return -1;
    }
    return 0;
}

int typeHandler(struct IdResp **idResp) {
    char *name = "";
    if(MODE_DEBUG == 1){
        printf("handling type: %s\n", (*idResp)->idStr);
    }
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
    
//handling binary operations: e.g. addops/mulops/relops
//including change current production rule's reducing type
//and set intermediate table
// if designatedRuleHeadType is NULL
// ruleHead would be pointed to one of the operands
// other wise ruleHead would be assigned as that type
void handleBinop(struct TypeInfo **ruleHead,
                 struct TypeInfo *op1,
                 struct TypeInfo *op2,
                 char *operator,
                 char *designatedRuleHeadType) {
    union ARGINFO arg1;
    union ARGINFO arg2;
    union ARGINFO arg_res;
    int eq = 0;
    arg1.strInfo = op1->code;
    arg2.strInfo = op2->code;
    arg_res.strInfo = createTmp();
    insertQuadruple(getCurQueadrupleTable(), operator,
                    buildArg(ARGTYPE_VAR_STR, arg1),
                    buildArg(ARGTYPE_VAR_STR, arg2),
                    buildArg(ARGTYPE_VAR_STR, arg_res));
    
    if(typeCheck(op1, op2)) {
        eq = 1;
    }
    else {
        yyerror_unequal_type(op1, op2);
        eq = 0;
    }
    
    if(designatedRuleHeadType == NULL) {
        setReduceTypeInfo(&(*ruleHead), op1, op2, eq);
    }
    else {
        constructTypeInfoForCertainSimpleType(&(*ruleHead), designatedRuleHeadType);
    }
    
    (*ruleHead)->code = arg_res.strInfo;
}
    
//handling unaryOperator's intermediate code table operation
// e.g. NOT, -
// including setting rulehead's reducing code as tmp name
// setting intermediate code accordingly
void handleUnaryOpICTable(struct TypeInfo **ruleHead,
                        struct TypeInfo *op1,
                        char *operator) {
    union ARGINFO arginfo1;
    union ARGINFO arginfo_res;
    arginfo1.strInfo = op1->code;
    (*ruleHead)->code = createTmp();
    arginfo_res.strInfo = (*ruleHead)->code;
    insertQuadruple(getCurQueadrupleTable(), operator,
                    buildArg(ARGTYPE_VAR_STR, arginfo1),
                    NULL,
                    buildArg(ARGTYPE_VAR_STR, arginfo_res));
}
    
//handling assignsatement
// including insert into intermediate table
// and typechecking, free var
void handleAssignStatement(struct TypeInfo *assignTo,
                           struct TypeInfo *assignFrom) {
    union ARGINFO arginfo1;
    union ARGINFO arginfo_res;
    if(!typeCheck(assignTo, assignFrom)) {
        yyerror_unequal_type(assignTo, assignFrom);
    }
    arginfo1.strInfo = assignTo->code;
    arginfo_res.strInfo = assignFrom->code;
    insertQuadruple(getCurQueadrupleTable(), ":=",
                    buildArg(ARGTYPE_VAR_STR, arginfo_res),
                    NULL,
                    buildArg(ARGTYPE_VAR_STR, arginfo1));
    free(assignTo);
    free(assignFrom);
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
    if(MODE_DEBUG == 1){
        //stdout=fopen("parser_debug.out","w");
    }
    yyparse();
    if(MODE_DEBUG == 1){
        //close(stdout);
    }
    stdout = fstream;
    if(MODE_DEBUG == 1){
        printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
        stdout=fopen("symtable.out","w");
        printAllSymbolTable();
        close(stdout);
        stdout = fstream;
        printAllQuadTable();
        printf("\n\n\n");
        printAllQuadTableAsCommand();
        printf("Done, symbole table: symtable.out\n\n");
    }
    else {
        stdout = fopen("intermediatecode.out", "w");
        printAllQuadTableAsCommand();
        close(stdout);
        stdout = fstream;
        printf("Done, intermediatecode: intermediatecode.out\n\n");
        printf("\n\nParsing done\n\n");
    }
    return 0;
}