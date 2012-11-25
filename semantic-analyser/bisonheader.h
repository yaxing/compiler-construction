//
//  bisonheader.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 10/26/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_bisonheader_h
#define compiler_debugging_bisonheader_h
#include "bisonpredef.h"

int pushRecordHashInStack(int hash) {
    recordHashStack *node = (recordHashStack *)malloc(sizeof(recordHashStack));
    node->hash = hash;
    if(recordStackHead == NULL) {
        recordStackHead = node;
        node->prev = node;
        recordStackTail = recordStackHead;
    }
    else {
        node->prev = recordStackTail;
        recordStackTail = node;
    }
    if(MODE_DEBUG == 1) {
        printf("push record %d in stack\n", hash);
    }
    return hash;
}

int popRecordHashFromStack() {
    recordHashStack *tmp;
    if(recordStackTail == NULL) {
        return 0;
    }
    else {
        tmp = recordStackTail->prev;
    }
    
    if(recordStackTail == tmp) {
        if(MODE_DEBUG == 1) {
            printf("pop record %d out stack, stack empty\n", tmp->hash);
        }
        free(recordStackTail);
        recordStackTail = NULL;
        recordStackHead = NULL;
        popScopeStack();
        return 0;
    }
    if(MODE_DEBUG == 1) {
        printf("pop record %d out stack\n", recordStackTail->hash);
    }
    free(recordStackTail);
    recordStackTail = tmp;
    popScopeStack();
    return tmp->hash;
}

void addCurFuncProcParamCallCounter(int delta) {
    funcProcParamCount += delta;
}

void cleanCurFuncProcCallParamCounter() {
    funcProcParamCount = 0;
}

//append a new id to current id list
idlist *appendToIdList(int entry) {
    idlist * newnode = (idlist *)malloc(sizeof(idlist));
    newnode->identryAddr = entry;
    newnode->next = NULL;
    if(idlisthead == NULL) {
        idlisthead = newnode;
        idlisttail = idlisthead;
        return idlisttail;
    }
    idlisttail->next = newnode;
    idlisttail = idlisttail->next;
    return idlisthead;
}

//append new typeinfo node to cur param list
paramTypeList *appendToParamTypeList(typeinfost *typeInfo) {
    paramTypeList *newNode = (paramTypeList *)malloc(sizeof(paramTypeList));
    newNode->typeInfo = typeInfo;
    newNode->next = NULL;
    if(paramTypeListHead == NULL) {
        paramTypeListHead = newNode;
        paramTypeListTail = newNode;
        return paramTypeListTail;
    }
    paramTypeListTail->next = newNode;
    paramTypeListTail = newNode;
    newNode = NULL;
    return paramTypeListTail;
}

//recursive destroy
void destroyCurIdListRec(idlist * p) {
    if(p != idlisttail || p->next != NULL) {
        destroyCurIdListRec(p->next);
    }
    free(p);
}

//clear current idlist
void destroyCurIdList() {
    destroyCurIdListRec(idlisthead);
    idlisthead = NULL;
    idlisttail = idlisthead;
}

//clear current paramTypeList
void destroyParamTypeListRec(paramTypeList *p) {
    if(p == NULL) {
        return;
    }
    destroyParamTypeListRec(p->next);
    free(p);
}

void destroyParamTypeList() {
    destroyParamTypeListRec(paramTypeListHead);
    paramTypeListHead = NULL;
    paramTypeListTail = paramTypeListHead;
}

void appendToLatestSetList(int entry) {
    if(maxSetEntryId >= 99) {
        return;
    }
    //latestSetEntries[maxSetEntryId] = entry;
    maxSetEntryId ++;
}

void cleanLatestSetList() {
    int i = 0;
    for(i = 0; i < maxSetEntryId; i ++) {
      //  latestSetEntries[i] = -1;
    }
    maxSetEntryId = -1;
}

//set type and attr for all current idlist ids
char *setIdListTypeAttr(int typeEntryAddr, entryAttr attr, int tag) {
    symboltable *table;
    idlist * cursor = idlisthead;
    int setResp = 0;
    table = getCurSymboltable();
    char *info = "Redefinition of variable: ";
    char *buf = NULL;
    char *idN = NULL;
    while(cursor != NULL) {
        if(MODE_DEBUG == 1) {
            printf("setting: %d %d\n", cursor->identryAddr, typeEntryAddr);
        }
        setResp = setSymbolEntyTypeAttr(table, cursor->identryAddr, typeEntryAddr, attr, tag);
        if(setResp == -1) {
            idN = getIDName(table, cursor->identryAddr);
            if(buf == NULL) {
                buf = (char *)malloc(sizeof(char) * 500);
                strcat(buf, info);
            }
            strcat(buf, idN);
            strcat(buf, " ");
        }
        appendToLatestSetList(cursor->identryAddr);
        cursor = cursor->next;
    }
    return buf;
}

void registerFunc(int idEntry, int retTypeEntry,
                  entryAttr retTypeAttr, int paramQty) {
    popScopeStack();
    symboltable *curTable = getCurSymboltable();
    entryAttr funcAttr;
    funcAttr.funcInfo.paramQty = paramQty;
    funcAttr.funcInfo.retTypeEntry = retTypeEntry;
    if(retTypeEntry == getPredefType("array")) {
        funcAttr.funcInfo.retTypeAttr.retArrayAttr = retTypeAttr.arrayInfo;
    }
    else if(retTypeEntry == getPredefType("record")) {
        funcAttr.funcInfo.retTypeAttr.retRecordAttr = retTypeAttr.recordInfo;
    }
    setSymbolEntyTypeAttr(curTable, idEntry, getPredefType("function"), funcAttr, ATTR_DEFAULT);
    if(MODE_DEBUG == 1) {
        printf("set func: %d in scope %d\n", idEntry, getCurScope()->scopeId);
    }
    pushScopeStack(find_scope(idEntry));
}

// register func name as a variable w/ type as return type in the
// first entry of it's own symboltable
void setFuncVarInScope(char *funcName, int funcId, int retTypeEntry, entryAttr attr) {
    scope *funcScope = find_scope(funcId);
    symboltable *table = funcScope->symboltable;
    setSymbolEntyTypeAttr(table, 0, retTypeEntry, attr, ATTR_VAR);
    if(MODE_DEBUG == 1) {
        printf("set func var %s\n", table->entries[0].typedesc->type);
        printSymbolTable(table, 0);
    }
}

// register proc
void registerProc(int idEntry, int paramQty) {
    scope *curScope = getCurScope();
    popScopeStack();
    symboltable *curTable = getCurSymboltable();
    entryAttr attr;
    attr.funcInfo.paramQty = paramQty;
    setSymbolTypeAttrDirec(curTable, idEntry, "procedure", attr, ATTR_DEFAULT);
    if(MODE_DEBUG == 1) {
        printf("set proc: %d in scope %d \n", idEntry, getCurScope()->scopeId);
    }
    pushScopeStack(curScope);
}

// register symbol in cur scope
int registerSymbolInCurScope(char *symbolVal) {
    int ret = registerSymbol(getCurSymboltable(), symbolVal, NULL);
    return ret;
}

// set attr
int setSymbolTypeAttrInCurScope(int idAddr, int typeAddr, entryAttr attribute, int tag) {
    int ret;
    ret = setSymbolEntyTypeAttr(getCurSymboltable(), idAddr, typeAddr, attribute, tag);
    return ret;
}

// 
char *getIDTypeStr(int idEntry) {
    scope *scope = getCurScope();
    if(MODE_DEBUG == 1) {
        printf("checking %d in scope %d (%d)\n", idEntry, scope->scopeId, scope->parent->scopeId);
        printSymbolTable(getCurSymboltable(), 0);
    }
    return getIdType(getCurSymboltable(), idEntry);
}

void removeTailSymbolFromCurScope() {
    removeTailSymbol(getCurSymboltable());
}

// check two typeInfo, return 0 if not eq, 1 if eq
int typeCheck(struct TypeInfo *typeInfo1, struct TypeInfo *typeInfo2) {
    union SymbolEntryAttr attrInfo1 = typeInfo1->attrInfo;
    union SymbolEntryAttr attrInfo2 = typeInfo2->attrInfo;
    int type1 = typeInfo1->typeEntry;
    int type2 = typeInfo2->typeEntry;
    int res = 0;
    int funcAddr = getPredefType("function");
    int procAddr = getPredefType("procedure");
    int arrayAddr = getPredefType("array");
    int recordAddr = getPredefType("record");
    if(MODE_DEBUG == 1) {
        printf("type checking: %d %d\n", typeInfo1->typeEntry, typeInfo2->typeEntry);
    }
    if(typeInfo1->tag != typeInfo2->tag) {
        if(MODE_DEBUG == 1) {
            printf("Incompatible tag: %d %d\n", typeInfo1->tag, typeInfo2->tag);
        }
        return 0;
    }
    else if(type1 != type2) {
        if(type1 == funcAddr
           || type1 == procAddr) {
            type1 = attrInfo1.funcInfo.retTypeEntry;
        }
        else if(type2 == funcAddr
                || type2 == procAddr) {
            type2 = attrInfo2.funcInfo.retTypeEntry;
        }
        if(MODE_DEBUG == 1) {
            printf("actual types: %d %d\n", type1, type2);
        }
        return type1 == type2 ? 1 : 0;
    }
    else {
        if(type1 == funcAddr
                || type1 == procAddr) {
            if(MODE_DEBUG == 1) {
                printf("actual types: %d %d\n", attrInfo1.funcInfo.retTypeEntry, attrInfo2.funcInfo.retTypeEntry);
            }
            res = funcCmp(attrInfo1.funcInfo, attrInfo2.funcInfo);
        }
        else if(type1 == arrayAddr) {
            if(MODE_DEBUG == 1) {
                printf("actual types: %d %d\n", attrInfo1.arrayInfo.typeEntry, attrInfo2.arrayInfo.typeEntry);
            }
            res = arrayCmp(typeInfo1->attrInfo.arrayInfo, typeInfo2->attrInfo.arrayInfo);
        }
        else if(type1 == recordAddr) {
            if(MODE_DEBUG == 1) {
                printf("actual types: %d %d\n", recordAddr, recordAddr);
            }
            res = recordCmp(typeInfo1->attrInfo.recordInfo, typeInfo2->attrInfo.recordInfo);
        }
        else {
            res = 0;
        }
    }
    return res == 0 ? 1 : 0;
}

void constructTypeInfoForCertainSimpleType(struct TypeInfo **typeinfo, char *type) {
    *typeinfo = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
    (*typeinfo)->typeEntry = getPredefType(type);
    (*typeinfo)->tag = ATTR_VAR;
    if(MODE_DEBUG == 1) {
        printf("constructed TypeInfo as %d(tag: %d)\n", (*typeinfo)->typeEntry, (*typeinfo)->tag);
    }
}

void constructTypeInfoFromTableEntry(struct TypeInfo **typeinfo, entry *tableEntry) {
    char *idType = tableEntry->typedesc->type;
    *typeinfo = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
    (*typeinfo)->typeEntry = getPredefType(idType);
    (*typeinfo)->tag = tableEntry->typedesc->tag;
    (*typeinfo)->attrInfo = tableEntry->typedesc->attribute;
    if(MODE_DEBUG == 1) {
        printf("constructed TypeInfo as %d(tag: %d) from entry %s(%s)\n", (*typeinfo)->typeEntry, (*typeinfo)->tag, tableEntry->symbolVal, tableEntry->typedesc->type);
    }
}

void constructTypeInfoFromIdResp(struct TypeInfo **typeinfo, struct IdResp *idResp) {
    scope *curScope  = getCurScope();
    entry *tableEntry;
    char *idType;
    *typeinfo = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
    if(idResp == NULL) {
        (*typeinfo)->typeEntry = getPredefType("undefined");
        (*typeinfo)->defScopeId = -2;
        if(MODE_DEBUG == 1) {
            printf("constructed TypeInfo(pred) as %d from undefined\n", (*typeinfo)->typeEntry);
        }
        return;
    }
    if(idResp->idRespStatus == IDRESP_PREDEF_KEYW
       || idResp->idRespStatus == IDRESP_PREDEF_TYPE) {
        (*typeinfo)->typeEntry = idResp->idEntry;
        (*typeinfo)->defScopeId = -2;
        if(MODE_DEBUG == 1) {
            printf("constructed TypeInfo(pred) as %d from %s(%d)\n", (*typeinfo)->typeEntry, idResp->idStr, idResp->idEntry);
        }
        return;
    }
    if(idResp->idRespStatus == IDRESP_DEF_IN_PARENT) {
        curScope = curScope->parent;
    }
    tableEntry = getSymbolbyEntryId(curScope->symboltable, idResp->idEntry);
    if(tableEntry == NULL || tableEntry->typedesc->type == NULL) {
        (*typeinfo)->typeEntry = getPredefType("undefined");
        (*typeinfo)->tag = ATTR_DEFAULT;
        (*typeinfo)->defScopeId = -10;
        if(MODE_DEBUG == 1) {
            printf("constructed TypeInfo(undef) as %d from %s(%d)\n", (*typeinfo)->typeEntry, idResp->idStr, idResp->idEntry);
        }
        return;
    }
    idType = tableEntry->typedesc->type;
    (*typeinfo)->typeEntry = getPredefType(idType);
    (*typeinfo)->tag = tableEntry->typedesc->tag;
    (*typeinfo)->attrInfo = tableEntry->typedesc->attribute;
    (*typeinfo)->defScopeId = -2;
    if(MODE_DEBUG == 1) {
        printf("constructed TypeInfo(normal) as %d from %s(%d) %s\n", (*typeinfo)->typeEntry, idResp->idStr, idResp->idEntry, idType);
    }
}

// get type name
// return func ret type or array ele type
char *getDirecTypeName(struct TypeInfo *typeInfo) {
    int typeEntry = typeInfo->typeEntry;
    if(typeEntry == getPredefType("function")) {
        typeEntry = typeInfo->attrInfo.funcInfo.retTypeEntry;
    }
    else if(typeEntry == getPredefType("array")) {
        typeEntry = typeInfo->attrInfo.arrayInfo.typeEntry;
    }
    return getIDName(predefinedIdTable, typeEntry);
}

char *checkFuncProcCallParamType(struct IdResp *idResp) {
    char *info = NULL;
    symboltable *funcTable;
    paramTypeList *cursor;
    struct TypeInfo *tmp;
    char *tmpInfoBuf = NULL;
    int i;
    int j = 0;
    int paramQty = global->symboltable->entries[idResp->idEntry].typedesc->attribute.funcInfo.paramQty;
    if(paramQty != funcProcParamCount) {
        info = (char *)malloc(150 * sizeof(char));
        sprintf(info, "Incorrect parameter quantity for func/proc call: %s", idResp->idStr);
        return info;
    }
    if(paramQty == 0) {
        return info;
    }
    funcTable = find_scope(idResp->idEntry)->symboltable;
    cursor = paramTypeListHead;
    info = (char *)malloc(sizeof(char) * 300);
    strcpy(info, "Incompatible parameter types: ");
    for(i = 1; i <= paramQty && i <= funcTable->maxId && cursor != NULL; i ++) {
        tmp = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
        constructTypeInfoFromTableEntry(&tmp, getSymbolbyEntryId(funcTable, i));
        if(typeCheck(cursor->typeInfo, tmp) == 0) {
            tmpInfoBuf = itoa(i);
            strcat(info, tmpInfoBuf);
            strcat(info, " ");
            free(tmpInfoBuf);
            j ++;
        }
        free(tmp);
        cursor = cursor->next;
    }
    if(j == 0) {
        free(info);
        info = NULL;
    }
    return info;
}

int handleRecordStart(struct IdResp *id) {
    symboltable *table;
    char *type;
    int hash;
    scope *tmpScope;
    if(id->idRespStatus == IDRESP_DEF_IN_PARENT) {
        table = getCurScope()->parent->symboltable;
    }
    else {
        table = getCurSymboltable();
    }
    type = table->entries[id->idEntry].typedesc->type;
    hash = table->entries[id->idEntry].typedesc->attribute.recordInfo.scopeHashCode;
    if(type == NULL
       || strcmp(type, "record") != 0) {
        return 0;
    }
    if(MODE_DEBUG == 1) {
        printf("pushing record: %d into stack\n", hash);
    }
    tmpScope = find_scope(hash);
    pushScopeStack(tmpScope);
    pushRecordHashInStack(hash);
    return hash;
}

int handleRecordEnd() {
    return popRecordHashFromStack();
}

// judge whether a curidresp is a type constructor
int isTypeConstructor(struct IdResp *curIdResp, char *typeConstructor) {
    scope *curScope = getCurScope();
    char *type;
    if(curIdResp->idRespStatus == IDRESP_DEF_IN_PARENT) {
        curScope = curScope->parent;
    }
    type = getIdType(curScope->symboltable, curIdResp->idEntry);
    if(strcmp(type, typeConstructor) == 0) {
        return 1;
    }
    return 0;
}

void setReduceTypeInfo(struct TypeInfo **typeInfoReduce, struct TypeInfo *typeInfoOp1, struct TypeInfo *typeInfoOp2, int eq) {
    if(eq) {
        *typeInfoReduce = typeInfoOp1;
    }
    else {
        if(typeInfoOp1->typeEntry != getPredefType("undefined")) {
            *typeInfoReduce = typeInfoOp1;
        }
        else if(typeInfoOp2->typeEntry != getPredefType("undefined")) {
            *typeInfoReduce = typeInfoOp2;
        }
        else {
            *typeInfoReduce = typeInfoOp1;
        }
    }
    if(MODE_DEBUG == 1) {
        printf("reduce as type: %d\n", (*typeInfoReduce)->typeEntry);
    }
}

int isSimpleType(int typeAddr) {
    return typeAddr != getPredefType("array")
            && typeAddr != getPredefType("record")
            && typeAddr != getPredefType("function")
            && typeAddr != getPredefType("procedure");
}

char *getTypeName(struct TypeInfo *typeInfo) {
    int type = typeInfo->typeEntry;
    if(typeInfo->typeEntry == getPredefType("function")) {
        type = typeInfo->attrInfo.funcInfo.retTypeEntry;
    }
    return getIDName(predefinedIdTable, type);
}

void handleArrayVar(struct IdResp **idResp) {
    scope *curScope;
    entry *tmp;
    if((*idResp) == NULL || !isTypeConstructor((*idResp), "array")) {
        if(MODE_DEBUG == 1) {
            printf("handling array: not array\n");
        }
        return;
    }
    curScope = getCurScope();
    if((*idResp)->idRespStatus == IDRESP_DEF_IN_PARENT) {
        curScope = curScope->parent;
    }
    tmp = getSymbolbyEntryId(curScope->symboltable, (*idResp)->idEntry);
    (*idResp)->idEntry = tmp->typedesc->attribute.arrayInfo.typeEntry;
    (*idResp)->idStr = getIDName(find_scope(tmp->typedesc->attribute.arrayInfo.typeDefScopeId)->symboltable, tmp->typedesc->attribute.arrayInfo.typeEntry);
    if(MODE_DEBUG == 1) {
        printf("handling array: cur idresp changed to %s\n", (*idResp)->idStr);
    }
}

#endif
