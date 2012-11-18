//
//  scope.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/14/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_scope_h
#define compiler_debugging_scope_h


typedef struct Scope {
    int scopeId; //hash value, in this part, scopeId equals to corresponding procedure id address
    int symboltableSize;
    int maxSymbolId;
    int subScopeQty;
    struct SymbolTable *symboltable;
    struct Scope *parent;
    struct Scope *stackParent;
    UT_hash_handle hh;
} scope;

typedef struct ScopeStack {
    int size;
    struct Scope *top;
} stack;

stack scopestack;
scope * global;
scope *scopeHashTable = NULL;

int add_scope(scope *s) {
    scope *tmp;
    HASH_FIND_INT( scopeHashTable, &(s->scopeId), tmp );
    if(tmp != NULL) {
        return 0;
    }
    else {
        HASH_ADD_INT( scopeHashTable, scopeId, s );
        return 1;
    }
}

scope *find_scope(int procedureAddress) {
    scope *s;
    
    HASH_FIND_INT( scopeHashTable, &procedureAddress, s );
    return s;
}

void delete_scope(scope *scopeP) {
    HASH_DEL( scopeHashTable, scopeP);
}

void initScope() {
    global = (scope *)malloc(sizeof(scope));
    global->scopeId = -1;
    global->symboltable = createSymbolTable();
    scopestack.size = 1;
    add_scope(global);
    scopestack.top = global;
}

scope *newScope(int procedureAddress) {
    scope *newScope = (scope *)malloc(sizeof(scope));
    newScope->scopeId = procedureAddress;
    newScope->symboltable = createSymbolTable();
    add_scope(newScope);
    return newScope;
}

scope *pushScopeStack(scope *curScope) {
    curScope->stackParent = scopestack.top;
    scopestack.top = curScope;
    scopestack.size ++;
    printf("scope changed to: %d\n", curScope->scopeId);
    return scopestack.top;
}

void newScopeAndPush(int procedureAddress) {
    pushScopeStack(newScope(procedureAddress));
}

scope *getCurScope() {
    return scopestack.top;
}

scope *getParentScope() {
    if(scopestack.top->parent != NULL) {
        return scopestack.top->parent;
    }
    return scopestack.top;
}

scope *popScopeStack() {
    scope *curTop;
    curTop = scopestack.top;
    if(scopestack.top != global && scopestack.size > 1) {
        scopestack.top = curTop->stackParent;
        curTop->stackParent = NULL;
    }
    scopestack.size --;
    printf("scope changed to: %d\n", scopestack.top->scopeId);
    return scopestack.top;
}

symboltable *getCurSymboltable() {
    scope *curScope = getCurScope();
    return curScope->symboltable;
}

/**
 *get the entry id of a predefined data type
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getType(char *name) {
    char *type = name;
    struct SymbolEntry *symbol;
    symboltable *curSymboltable = getCurSymboltable();
    symbol = getSymbolbyName(curSymboltable, name);
    if(symbol != NULL && symbol->type != NULL) {
        type = symbol->type;
    }
    symbol = getSymbolbyName(predefinedIdTable, type);
    type = symbol->type;
    if(type != NULL && strcmp(type, "TYPE") == 0) {
        return symbol->address;
    }
    return -1;
}

char *getNameInCurScope(int entry) {
    return getIDName(getCurSymboltable(), entry);
}

void printSymbolTableRec(int idEntry, int parentId, symboltable *table) {
    int i = 0;
    printf("symboltable of scope %d (sub-scope of %d): \n", idEntry, parentId);
    if(table->maxId == -1) {
        return;
    }
    printSymbolTable(table);
    scope *scopeP = NULL;
    for(i = 0; i <= global->symboltable->maxId; i ++) {
        if(table->entries[i].type != NULL
           && (strcmp("function", table->entries[i].type) == 0 || strcmp("procedure", table->entries[i].type) == 0)) {
            scopeP = find_scope(i);
            printSymbolTableRec(i, idEntry, scopeP->symboltable);
        }
    }
}

void printAllSymbolTable() {
    printf("All symboltables: \n");
    printSymbolTableRec(-1, -1, global->symboltable);
}



#endif
