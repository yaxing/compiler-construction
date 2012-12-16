//
//  util.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/19/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_util_h
#define compiler_debugging_util_h

void printSymbolTable(symboltable *table, int lineSpaceQty);

int lineNo = 1;

char *strcpy2(char *str) {
    char *strTarget;
    if(str == NULL) {
        return NULL;
    }
    strTarget = (char *)malloc(sizeof(str));
    strcpy(strTarget, str);
    return strTarget;
}

char *strcat2(char *str1, char *str2) {
    char *buf;
    if(str1 == NULL) {
        return strcpy2(str2);
    }
    if(str2 == NULL) {
        return strcpy2(str1);
    }
    buf = (char *)malloc(sizeof(str1) + sizeof(str2));
    strcpy(buf, str1);
    strcat(buf, str2);
    return buf;
}

char *itoa(int a) {
    char * buf = (char *)malloc(sizeof(a + 1) * sizeof(char));
    sprintf(buf, "%d", a);
    return buf;
}

void printArg(arg *argx, int format) {
    scope *symbolScope;
    symboltable *table;
    char *symbol;
    if(argx == NULL) {
        char *t = "(null)";
        if(format) {
            printf("%-8s ", t);
        }
        else {
            printf("%s", t);
        }
        return;
    }
    if(argx->argType == ARGTYPE_VAR_STR) {
        if(format) {
            printf("%-8s ", argx->argInfo.strInfo);
        }
        else {
            printf("%s ", argx->argInfo.strInfo);
        }
    }
    else {
        symbolScope = find_scope(argx->argInfo.idInfo->scopeId);
        table = symbolScope->symboltable;
        symbol = getIDName(table, argx->argInfo.idInfo->address);
        if(format) {
            printf("%-8s ", symbol);
        }
        else {
            printf("%s ", symbol);
        }
    }
}

void printQuadrupleTable(quadrupleTable *table) {
    int i = 0;
    for(; i <= table->maxIndex; i ++) {
        quad tmp = table->quads[i];
        printf("OP: %-10s ", tmp.op);
        printf("ARG1: ");
        printArg(tmp.arg1, 1);
        printf("ARG2: ");
        printArg(tmp.arg2, 1);
        printf("RES: ");
        printArg(tmp.result, 1);
        printf("\n");
    }
    printf("\n");
}

void printHang() {
    printf("  ");
}

void printAllQuadTable() {
    printf("All quadTables: \n");
    int i = 0;
    symboltable *table = global->symboltable;
    scope *tmpScope;
    printf("quad table of scope -1 (global): \n");
    printQuadrupleTable(global->quadrupletable);
    for(i = 0; i <= table->maxId; i ++) {
        if(table->entries[i].typedesc != NULL
           && table->entries[i].typedesc->type != NULL
           && (strcmp("function", table->entries[i].typedesc->type) == 0
               || strcmp("procedure", table->entries[i].typedesc->type) == 0)) {
               tmpScope = find_scope(i);
               printf("quad table of scope %d (sub-scope of %d): \n", tmpScope->scopeId, tmpScope->parent->scopeId);
               quadrupleTable *quads = tmpScope->quadrupletable;
               if(quads->maxIndex >= 0) {
                   printQuadrupleTable(quads);
               }
           }
    }
}

void printQuadTableAsCommand(quadrupleTable *table) {
    int i = 0;
    for(; i <= table->maxIndex; i ++) {
        quad tmp = table->quads[i];
        quad prevTmp = tmp;
        if(i > 0) {
            prevTmp = table->quads[i - 1];
        }
        if(strcmp(tmp.op, QUAD_OP_LABEL) == 0
           || strcmp(tmp.op, QUAD_OP_PROG) == 0) {
            printf("%s ", tmp.op);
            printArg(tmp.arg1, 0);
            printf("\n");
            continue;
        }
        if(strcmp(tmp.op, QUAD_OP_FUNCALL) == 0) {
            printHang();
            printArg(tmp.result, 0);
            printf(":= %s ", tmp.op);
            printArg(tmp.arg1, 0);
        }
        else if(strcmp(tmp.op, QUAD_OP_CALL) == 0
                || strcmp(tmp.op, QUAD_OP_GOTO) == 0
                || strcmp(tmp.op, QUAD_OP_PARAM) == 0
                || strcmp(tmp.op, QUAD_OP_FUNRETURN) == 0) {
            printHang();
            printf("%s ", tmp.op);
            printArg(tmp.arg1, 0);
        }
        else if(strcmp(tmp.op, QUAD_OP_RETURN) == 0) {
            printHang();
            printf("%s ", tmp.op);
        }
        else if(strcmp(tmp.op, "-") == 0
                    && tmp.arg2 == NULL) {
                    printHang();
                    printArg(tmp.result, 0);
                    printf(":= %s ", tmp.op);
                    printArg(tmp.arg1, 0);
                }
        else if(strcmp(tmp.op, ":=") == 0) {
            printHang();
            printArg(tmp.result, 0);
            printf("%s ", tmp.op);
            printArg(tmp.arg1, 0);
        }
        else if(strcmp(tmp.op, QUAD_OP_IF) == 0) {
            printHang();
            printf("%s ", tmp.op);
            printArg(prevTmp.result, 0);
            printf("= TRUE ");
            printf("goto ");
            printArg(tmp.result, 0);
        }
        else {
            if(!argIsNull(tmp.result)) {
                printHang();
                printArg(tmp.result, 0);
                printf(":= ");
                printArg(tmp.arg1, 0);
                printf("%s ", tmp.op);
                printArg(tmp.arg2, 0);
            }
            else {
                continue;
            }
        }
        printf("\n");
    }
//    printf("\n");
}

void printAllQuadTableAsCommand() {
    //printf("intermediate code: \n");
    int i = 0;
    symboltable *table = global->symboltable;
    scope *tmpScope;
    for(i = 0; i <= table->maxId; i ++) {
        if(table->entries[i].typedesc != NULL
           && table->entries[i].typedesc->type != NULL
           && (strcmp("function", table->entries[i].typedesc->type) == 0
               || strcmp("procedure", table->entries[i].typedesc->type) == 0)) {
               tmpScope = find_scope(i);
               quadrupleTable *quads = tmpScope->quadrupletable;
               if(quads->maxIndex >= 0) {
                   printQuadTableAsCommand(quads);
                   printf("\n");
               }
           }
    }
    printQuadTableAsCommand(global->quadrupletable);
}


void printArrayInfo(struct ArrayInfo array) {
    char *type;
    scope *defScope = find_scope(array.typeDefScopeId);
    type = getIDName(defScope->symboltable, array.typeEntry);
    printf("\n    ArrayType: %-10s(scope %d) BoundLow: %d BoundUp: %d",
           type, defScope->scopeId, array.boundLow, array.boundUp);
}

void printRecordInfo(struct RecordInfo recordInfo, int spaceCnt, int spaceCntBuf) {
    scope *tmpScope;
    symboltable *tmpTable;
    printf("RecordMembers: \n\n");
    tmpScope = find_scope(recordInfo.scopeHashCode);
    if(tmpScope != NULL) {
        tmpTable = tmpScope->symboltable;
        printSymbolTable(tmpTable, spaceCnt + spaceCntBuf);
    }
}

void printFuncInfo(struct FuncInfo funcInfo) {
    char *retType = getIDName(predefinedIdTable, funcInfo.retTypeEntry);
    printf("ParamQty: %d ReturnType: ", funcInfo.paramQty);
    if(funcInfo.retTypeEntry == getPredefType("array")) {
        printf("\n    ");
        printArrayInfo(funcInfo.retTypeAttr.retArrayAttr);
    }
    else if(funcInfo.retTypeEntry == getPredefType("record")) {
        printf("\n    ");
        printRecordInfo(funcInfo.retTypeAttr.retRecordAttr, 0, 4);
    }
    else {
        printf("%-10s", retType);
    }
}

void printProcInfo(struct FuncInfo funcInfo) {
    printf("ParamQty: %d", funcInfo.paramQty);
}

void printTagAttr(int tag) {
    char *attr = NULL;
    switch(tag) {
        case -1:
            break;
        case 0:
            attr = "type";
            break;
        case 1:
            attr = "var";
            break;
    }
    if(attr != NULL) {
        printf("Attr: %s ", attr);
    }
}

void printSymbolTable(symboltable *table, int lineSpaceQty) {
    int i = 0;
    int spaceCnt = 0;
    char *curType = NULL;
    entryAttr curAttr;
    int spaceCntBuf = 4;
    if(table == NULL) {
        return;
    }
    for(i = 0; i <= table->maxId; i ++) {
        curType = NULL;
        curType = table->entries[i].typedesc->type;
        curAttr = table->entries[i].typedesc->attribute;
        for(spaceCnt = 0; spaceCnt < lineSpaceQty; spaceCnt ++) {
            printf(" ");
        }
        printf("Address: %-3d ID: %-15s Type: %-10s ",
               table->entries[i].address, table->entries[i].symbolVal, curType);
        printTagAttr(table->entries[i].typedesc->tag);
        if(curType != NULL) {
            if(strcmp(curType, "array") == 0) {
                printArrayInfo(curAttr.arrayInfo);
            }
            else if(strcmp(curType, "record") == 0) {
                printRecordInfo(curAttr.recordInfo, spaceCnt, spaceCntBuf);
            }
            else if(strcmp(curType, "function") == 0) {
                printFuncInfo(curAttr.funcInfo);
            }
            else if(strcmp(curType, "procedure") == 0) {
                printProcInfo(curAttr.funcInfo);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printSymbolTableRec(int idEntry, int parentId, symboltable *table) {
    int i = 0;
    printf("symboltable of scope %d (sub-scope of %d): \n", idEntry, parentId);
    if(table->maxId == -1) {
        return;
    }
    printSymbolTable(table, 0);
    scope *scopeP = NULL;
    for(i = 0; i <= global->symboltable->maxId; i ++) {
        if(table->entries[i].typedesc != NULL
           && table->entries[i].typedesc->type != NULL
           && (strcmp("function", table->entries[i].typedesc->type) == 0
               || strcmp("procedure", table->entries[i].typedesc->type) == 0)) {
               scopeP = find_scope(i);
               printSymbolTableRec(i, idEntry, scopeP->symboltable);
           }
    }
}

void printAllSymbolTable() {
    printf("All symboltables: \n");
    printSymbolTableRec(-1, -1, global->symboltable);
}

int attrIsEmpty(union SymbolEntryAttr attr, char *type) {
    if(type == NULL) {
        return 1;
    }
    if(strcmp(type, "array") == 0) {
        if(attr.arrayInfo.typeEntry == 0
           && attr.arrayInfo.boundLow == 0
           && attr.arrayInfo.boundUp == 0) {
            return 1;
        }
    }
    else if(strcmp(type, "record") == 0) {
        if(attr.recordInfo.scopeHashCode == -1) {
            return 1;
        }
    }
    return 0;
}

void addLineNo() {
    lineNo ++;
}

int getLineNo() {
    return lineNo;
}

#endif
