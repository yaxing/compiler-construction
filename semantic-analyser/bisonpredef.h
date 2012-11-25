//
//  bisonpredef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/24/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_bisonpredef_h
#define compiler_debugging_bisonpredef_h

typedef struct TypeInfo {
    int typeEntry;
    int defScopeId;//which scope is this type defined in
    int tag;//VAR or TYPE
    union SymbolEntryAttr attrInfo;
} typeinfost;

typedef struct IDLIST {
    int identryAddr;
    struct IDLIST * next;
} idlist;

typedef struct PARAMTYPELIST {
    struct TypeInfo *typeInfo;
    struct PARAMTYPELIST *next;
} paramTypeList;

typedef struct ActiveRecordHashStack {
    int hash;
    struct ActiveRecordHashStack *prev;
} recordHashStack;

// idlist
idlist * idlisthead = NULL;
idlist * idlisttail = NULL;

// func/proc call parameters type stack
paramTypeList *paramTypeListHead = NULL;
paramTypeList *paramTypeListTail = NULL;

// record reference stack
recordHashStack *recordStackHead = NULL;
recordHashStack *recordStackTail = NULL;

//int latestSetEntries[100] = {};
int maxSetEntryId = -1;

int funcProcParamCount = 0;

#endif
