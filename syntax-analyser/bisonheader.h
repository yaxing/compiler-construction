//
//  bisonheader.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 10/26/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_bisonheader_h
#define compiler_debugging_bisonheader_h

typedef struct TypeInfo {
    int typeEntry;
    char *additionType;
    union SymbolEntryAttr attrInfo;
} typeinfost;

typedef struct IDLIST {
    int identryAddr;
    struct IDLIST * next;
} idlist;

idlist * idlisthead = NULL;
idlist * idlisttail = NULL;

int latestSetEntries[100] = {};
int maxSetEntryId = -1;

//append a new id to current id list
idlist * appendToIdList(int entry) {
    idlist * newnode = (idlist *)malloc(sizeof(idlist));
    newnode->identryAddr = entry;
    if(idlisthead == NULL) {
        idlisthead = newnode;
        idlisttail = idlisthead;
        return idlisttail;
    }
    idlisttail->next = newnode;
    idlisttail = idlisttail->next;
    newnode = NULL;
    return idlisthead;
}

//recursive destroy
void destroyCurIdListRec(idlist * p) {
    if(p != idlisttail || p->next != NULL) {
        destroyCurIdListRec(p->next);
    }
    p = NULL;
}

//clear current idlist
void destroyCurIdList() {
    destroyCurIdListRec(idlisthead);
    idlisthead = NULL;
    idlisttail = idlisthead;
}

void appendToLatestSetList(int entry) {
    if(maxSetEntryId >= 99) {
        return;
    }
    latestSetEntries[maxSetEntryId] = entry;
    maxSetEntryId ++;
}

void cleanLatestSetList() {
    int i = 0;
    for(i = 0; i < maxSetEntryId; i ++) {
        latestSetEntries[i] = -1;
    }
    maxSetEntryId = -1;
}

//set type and attr for all current idlist ids
char *setIdListTypeAttr(int typeEntryAddr, entryAttr attr) {
    symboltable *table;
    idlist * cursor = idlisthead;
    int setResp = 0;
    table = getCurSymboltable();
    while(cursor != NULL) {
        printf("setting: %d %d\n", cursor->identryAddr, typeEntryAddr);
        setResp = setSymbolEntyTypeAttr(table, cursor->identryAddr, typeEntryAddr, attr);
        if(setResp == -1) {
            char * idN = getIDName(table, cursor->identryAddr);
            char * info = "Redefinition of variable: ";
            char * buf = (char *)malloc(strlen(info) + strlen(idN) + 4);
            sprintf(buf, "%s%s\n", info, idN);
            return buf;
        }
        appendToLatestSetList(cursor->identryAddr);
        cursor = cursor->next;
    }
    destroyCurIdList();
    return NULL;
}

void registerFunc(int idEntry, int retTypeEntry,
                  entryAttr retTypeAttr, int paramQty) {
    scope *curScope = getCurScope();
    popScopeStack();
    symboltable *curTable = getCurSymboltable();
    entryAttr funcAttr;
    char *type = getIDName(predefinedIdTable, retTypeEntry);
    funcAttr.funcInfo.paramQty = paramQty;
    funcAttr.funcInfo.retTypeEntry = retTypeEntry;
    if(type != NULL && strcmp(type, "array")) {
            funcAttr.funcInfo.retTypeAttr.retArrayAttr = retTypeAttr.arrayInfo;
    }
    else if(type != NULL && strcmp(type, "record")) {
            funcAttr.funcInfo.retTypeAttr.retRecordAttr = retTypeAttr.recordInfo;
    }
    setSymbolTypeAttrDirec(curTable, idEntry, "function", funcAttr);
    printf("set func: %d in scope %d\n", idEntry, getCurScope()->scopeId);
    pushScopeStack(curScope);
}

void setFuncVarInScope(char *funcName, int funcId, int retTypeEntry, entryAttr attr) {
    scope *funcScope = find_scope(funcId);
    symboltable *table = funcScope->symboltable;
    setSymbolEntyTypeAttr(table, 0, retTypeEntry, attr);
}

void registerProc(int idEntry, int paramQty) {
    symboltable *curTable = getCurSymboltable();
    entryAttr attr;
    attr.funcInfo.paramQty = paramQty;
    setSymbolTypeAttrDirec(curTable, idEntry, "procedure", attr);
    printf("set proc: %d in scope %d \n", idEntry, getCurScope()->scopeId);
}

int registerSymbolInCurScope(char *symbolVal) {
    int ret = registerSymbol(getCurSymboltable(), symbolVal, NULL);
    return ret;
}

int setSymbolTypeAttrInCurScope(int idAddr, int typeAddr, entryAttr attribute) {
    int ret = setSymbolEntyTypeAttr(getCurSymboltable(), idAddr, typeAddr, attribute);
    return ret;
}

char *getIDTypeStr(int idEntry) {
    scope *scope = getCurScope();
    printf("checking %d in scope %d (%d)\n", idEntry, scope->scopeId, scope->parent->scopeId);
    printSymbolTable(getCurSymboltable());  
    return getIdType(getCurSymboltable(), idEntry);
}

void removeTailSymbolFromCurScope() {
    removeTailSymbol(getCurSymboltable());
}
#endif
