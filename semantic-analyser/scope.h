//
//  scope.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/14/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_scope_h
#define compiler_debugging_scope_h

int const SCOPEID_GLOBAL = -1;
int const SCOPEID_PREDEF = -2;

typedef struct Scope {
    int scopeId; //hash value, in this part, scopeId equals to corresponding procedure id address
    int symboltableSize;
    int maxSymbolId;
    int subScopeQty;
    struct SymbolTable *symboltable;
    struct Scope *parent;
    UT_hash_handle hh;
} scope;

typedef struct ScopeStack {
    int size;
    struct Scope *top;
} stack;

stack scopestack;
scope *global;
scope *predef;
scope *scopeHashTable = NULL;
int hashSeed = 1;

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
    global->parent = global;
    scopestack.size = 1;
    add_scope(global);
    scopestack.top = global;
    
    predef = (scope *)malloc(sizeof(scope));
    predef->scopeId = -2;
    predef->symboltable = predefinedIdTable;
    predef->parent = NULL;
    add_scope(predef);
}

scope *newScope(int procedureAddress) {
    scope *newScope = (scope *)malloc(sizeof(scope));
    newScope->scopeId = procedureAddress;
    newScope->symboltable = createSymbolTable();
    add_scope(newScope);
    return newScope;
}

scope *pushScopeStack(scope *curScope) {
    curScope->parent = scopestack.top;
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

int getCurScopeId() {
    return scopestack.top->scopeId;
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
        scopestack.top = curTop->parent;
    }
    scopestack.size --;
    printf("scope changed to: %d\n", scopestack.top->scopeId);
    return scopestack.top;
}

symboltable *getCurSymboltable() {
    scope *curScope = getCurScope();
    return curScope->symboltable;
}

char *getNameInCurScope(int entry) {
    return getIDName(getCurSymboltable(), entry);
}

int getTypeDefAddrInScope(scope *scope, char *name) {
    char *type = name;
    struct SymbolEntry *symbol;
    symboltable *curSymboltable = scope->symboltable;
    int tag = ATTR_DEFAULT;
    if(type == NULL) {
        return -1;
    }
    symbol = getSymbolbyName(curSymboltable, name);
    if(symbol == NULL
       || symbol->typedesc->tag != ATTR_TYPE
       || symbol->typedesc->type == NULL) {
        symbol = getSymbolbyName(predefinedIdTable, type);
    }
    if(symbol != NULL) {
        type = symbol->typedesc->type;
        tag = symbol->typedesc->tag;
    }
    if(type != NULL
       && (tag == ATTR_TYPE
           || strcmp(type, "TYPE") == 0)) {
        return symbol->address;
    }
    return -1;
}

/**
 *get the entry id of a predefined data type
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getTypeDefAddr(char *name) {
    printf("checking type %s in cur scope %d\n", name, getCurScope()->scopeId);
    return getTypeDefAddrInScope(getCurScope(), name);
}

int getTypeDefInParentScope(char *type) {
    scope *scope = getCurScope()->parent;
    printf("checking type %s in scope %d\n", type, scope->scopeId);
    return getTypeDefAddrInScope(scope, type);
}

int getDefInParentScope(char *name, int tag) {
    scope *scope = getCurScope()->parent;
    symboltable *table;
    entry *tableEntry;
    if(scope == NULL) {
        return -1;
    }
    printf("checking symbol %s in parent scope %d\n", name, scope->scopeId);
    table = scope->symboltable;
    tableEntry = getSymbolbyName(table, name);
    if(tableEntry != NULL
       && tableEntry->typedesc->tag == tag
       && tableEntry->typedesc->type != NULL) {
        return tableEntry->address;
    }
    return -1;
}

int getFuncProcDefInParentScope(char *name) {
    scope *scope = getCurScope()->parent;
    symboltable *table;
    entry *tableEntry;
    if(scope == NULL) {
        return -1;
    }
    printf("checking symbol %s in parent scope %d\n", name, scope->scopeId);
    table = scope->symboltable;
    tableEntry = getSymbolbyName(table, name);
    if(tableEntry != NULL
       && tableEntry->typedesc->tag == ATTR_DEFAULT
       && tableEntry->typedesc->type != NULL) {
        if(strcmp(tableEntry->typedesc->type, "function") == 0
           || strcmp(tableEntry->typedesc->type, "procedure") == 0) {
            return tableEntry->address;
        }
    }
    return -1;
}

int getPredefType(char *name) {
    char *type = name;
    char *predefSymbolType = NULL;
    struct SymbolEntry *symbol;
    symbol = getSymbolbyName(predefinedIdTable, type);
    if(symbol != NULL && symbol->typedesc != NULL) {
        predefSymbolType = symbol->typedesc->type;
        if(predefSymbolType != NULL && strcmp(predefSymbolType, "TYPE") == 0) {
            return symbol->address;
        }
    }
    return -1;
}

int recordIdHashCode() {
    return abs(getCurScope()->scopeId * 1000) + hashSeed ++;
}

#endif
