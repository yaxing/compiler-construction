//
//  scopepredef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/29/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_scopepredef_h
#define compiler_debugging_scopepredef_h

int const SCOPEID_GLOBAL = -1;
int const SCOPEID_PREDEF = -2;

// scope node
typedef struct Scope {
    int scopeId; //hash value, in this part, scopeId equals to corresponding procedure id address
    int symboltableSize;
    int maxSymbolId;
    int subScopeQty;
    struct SymbolTable *symboltable;
    struct QUADRUPLES *quadrupletable;
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

//===function declarations===//
int add_scope(scope *s);

scope *find_scope(int procedureAddress);

void delete_scope(scope *scopeP);

void initScope();

scope *newScope(int procedureAddress);

scope *pushScopeStack(scope *curScope);

void newScopeAndPush(int procedureAddress);

scope *getCurScope();

int getCurScopeId();

int getParentScopeId();

scope *getParentScope();

scope *popScopeStack();

symboltable *getCurSymboltable();

char *getNameInCurScope(int entry);

int getTypeDefAddrInScope(scope *scope, char *name);

int getTypeDefAddr(char *name);

int getTypeDefInParentScope(char *type);

int getDefInParentScope(char *name, int tag);

int getFuncProcDefInParentScope(char *name);

int getPredefType(char *name);

int recordIdHashCode();

#endif
