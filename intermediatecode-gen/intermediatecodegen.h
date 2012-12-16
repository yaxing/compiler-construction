//
//  intermediatecodegen.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 12/1/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_intermediatecodegen_h
#define compiler_debugging_intermediatecodegen_h

int maxTmpId = 0;
int maxLableId = 0;

typedef struct VARREFSTACKNODE {
    char *var;
    struct VARREFSTACKNODE *prev;
} varReferStackNode;

varReferStackNode *varReferStackTop = NULL;

char *itoa(int a);
char *strcpy2(char *str);

char *createTmp() {
    maxTmpId ++;
    char *tmp = (char *)malloc(sizeof("tmp") + sizeof(int));
    strcpy(tmp, "tmp");
    strcat(tmp, itoa(maxTmpId));
    return tmp;
}

char *createLable() {
    maxLableId ++;
    char *tmp = (char *)malloc(sizeof("LABEL_") + sizeof(int));
    strcpy(tmp, "LABEL_");
    strcat(tmp, itoa(maxLableId));
    return tmp;
}

int varReferStackEmpty() {
    return varReferStackTop == NULL;
}

char *popVarReferStack() {
    char *var = NULL;
    varReferStackNode *tmp;
    if(varReferStackTop == NULL) {
        return NULL;
    }
    var = strcpy2(varReferStackTop->var);
    tmp = varReferStackTop;
    varReferStackTop = tmp->prev;
    free(tmp);
    if(MODE_DEBUG) {
        printf("pop %s from var stack\n", var);
    }
    return var;
}

void pushVarReferStack(char *var) {
    varReferStackNode *newNode
        = (varReferStackNode *)malloc(sizeof(varReferStackNode));
    newNode->var = strcpy2(var);
    newNode->prev = varReferStackTop;
    varReferStackTop = newNode;
    if(MODE_DEBUG) {
        printf("push %s into var stack\n", var);
    }
}

#endif
