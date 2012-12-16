//
//  quadruple
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/30/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_quadruple_h
#define compiler_debugging_quadruple_h

int const ARGTYPE_ID;
int const ARGTYPE_VAR_STR;

char *QUAD_OP_PROG = "program";
char *QUAD_OP_NOT = "not";
char *QUAD_OP_LABEL = "L";
char *QUAD_OP_GOTO = "goto";
char *QUAD_OP_FUNCALL = "funcall";
char *QUAD_OP_CALL = "call";
char *QUAD_OP_PARAM = "param";
char *QUAD_OP_RETURN = "return";
char *QUAD_OP_FUNRETURN = "funreturn";
char *QUAD_OP_IF = "if";

//char *QUAD_OP_IF_LESS = "if_<";
//char *QUAD_OP_IF_GREATER = "if_>";
//char *QUAD_OP_IF_LESS_EQ = "if_<=";
//char *QUAD_OP_IF_GREATER_EQ = "if_>=";
//char *QUAD_OP_IF_EQ = "if_=";
//char *QUAD_OP_IF_NOT_EQ = "if_<>";


typedef struct ARGIdINFO {
    int address;
    int scopeId;
} argIdInfo;

union ARGINFO {
    argIdInfo *idInfo;
    char *strInfo;
};

typedef struct ARG {
    int argType;
    union ARGINFO argInfo;
} arg;

typedef struct QUAD {
    char *op;
    arg *arg1;
    arg *arg2;
    arg *result;
} quad;

typedef struct QUADRUPLES {
    int maxIndex;
    int size;
    quad quads[500];
} quadrupleTable;

quadrupleTable *createQuadrupleTable() {
    quadrupleTable *table = (quadrupleTable *)malloc(sizeof(quadrupleTable));
    table->size = sizeof(table->quads) / sizeof(quad);
    table->maxIndex = -1;
    return table;
}

void insertQuadruple(quadrupleTable *table, char *op, arg *arg1, arg *arg2, arg *result) {
    int index = table->maxIndex + 1;
    if(index >= table->size - 1) {
        return;
    }
    table->maxIndex = index;
    table->quads[index].op = (char *)malloc(sizeof(op));
    strcpy(table->quads[index].op, op);
    table->quads[index].arg1 = arg1;
    table->quads[index].arg2 = arg2;
    table->quads[index].result = result;
}

arg *buildArg(int type, union ARGINFO argInfo) {
    arg *newArg = (arg *)malloc(sizeof(arg));
    newArg->argType = type;
    newArg->argInfo = argInfo;
    return newArg;
}

arg *buildStrArg(char *str) {
    if(str == NULL) {
        return NULL;
    }
    arg *newArg = (arg *)malloc(sizeof(arg));
    newArg->argType = ARGTYPE_VAR_STR;
    newArg->argInfo.strInfo = str;
    return newArg;
}

int argIsNull(arg *argT) {
    if(argT == NULL) {
        return 1;
    }
    if(argT->argType == ARGTYPE_VAR_STR
       && argT->argInfo.strInfo == NULL) {
        return 1;
    }
    if(argT->argType == ARGTYPE_ID
       && argT->argInfo.idInfo == NULL) {
        return 1;
    }
    return 0;
}

char *getLastArg1(quadrupleTable *table) {
    if(table->maxIndex < 0) {
        return NULL;
    }
    return table->quads[table->maxIndex].arg1->argInfo.strInfo;
}

void removeLastCode(quadrupleTable *table) {
    int max = table->maxIndex;
    if(max < 0) {
        return;
    }
    table->quads[max].arg1 = NULL;
    table->quads[max].arg2 = NULL;
    table->quads[max].op = NULL;
    table->quads[max].result = NULL;
    table->maxIndex --;
}

#endif
