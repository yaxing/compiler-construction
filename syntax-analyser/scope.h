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
    global->parent = global;
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


/**
 *get the entry id of a predefined data type
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getType(char *name) {
    char *type = name;
    struct SymbolEntry *symbol;
    symboltable *curSymboltable = getCurSymboltable();
    if(type == NULL) {
        return -1;
    }
    symbol = getSymbolbyName(curSymboltable, name);
    if(symbol != NULL
       && symbol->typedesc != NULL
       && symbol->typedesc->type != NULL) {
        type = symbol->typedesc->type;
    }
    symbol = getSymbolbyName(predefinedIdTable, type);
    if(symbol != NULL && symbol->typedesc != NULL) {
        type = symbol->typedesc->type;
    }
    if(type != NULL && strcmp(type, "TYPE") == 0) {
        return symbol->address;
    }
    return -1;
}

int getTypeInParentScope(char *type) {
    scope *scope = getCurScope()->parent;
    printf("checking type %s in scope %d\n", type, scope->scopeId);
    symboltable *table = scope->symboltable;
    printSymbolTable(table);
    struct SymbolEntry *symbol;
    if(type == NULL) {
        return -1;
    }
    symbol = getSymbolbyName(table, type);
    if(symbol != NULL
       && symbol->typedesc != NULL
       && symbol->typedesc->type != NULL) {
        type = symbol->typedesc->type;
    }
    symbol = getSymbolbyName(predefinedIdTable, type);
    if(symbol->typedesc != NULL) {
        type = symbol->typedesc->type;
    }
    if(type != NULL && strcmp(type, "TYPE") == 0) {
        return symbol->address;
    }
    return -1;
}

int getDefInParentScope(char *name) {
    scope *scope = getCurScope()->parent;
    symboltable *table;
    int entry;
    char *type;
    if(scope == NULL) {
        return -1;
    }
    printf("checking var %s in parent scope %d\n", name, scope->scopeId);
    table = scope->symboltable;
    entry = getSymbolEntry(table, name);
    type = getIdType(table, entry);
    if(type != NULL) {
        return entry;
    }
    return -1;
}

int getPredefType(char *name) {
    char *type = name;
    struct SymbolEntry *symbol;
    symbol = getSymbolbyName(predefinedIdTable, type);
    if(symbol != NULL && symbol->typedesc != NULL) {
        type = symbol->typedesc->type;
    }
    if(type != NULL && strcmp(type, "TYPE") == 0) {
        return symbol->address;
    }
    return -1;
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



#endif
