//
//  bisonpredef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/24/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_bisonpredef_h
#define compiler_debugging_bisonpredef_h

// type info struct for bison in-parse using
typedef struct TypeInfo {
    int typeEntry;
    int defScopeId;//which scope is this type defined in
    int tag;//VAR or TYPE
    union SymbolEntryAttr attrInfo;
} typeinfost;

// for temp storage of id list(e.g. var/type def)
typedef struct IDLIST {
    int identryAddr;
    struct IDLIST * next;
} idlist;

// func/proc calling params' type list
typedef struct PARAMTYPELIST {
    struct TypeInfo *typeInfo;
    struct PARAMTYPELIST *next;
} paramTypeList;

// used to record record calling sequence
// e.g. a.b.c.s
typedef struct ActiveRecordHashStack {
    int hash;
    struct ActiveRecordHashStack *prev;
} recordHashStack;

typedef struct CURArrayType {
    struct ArrayInfo arrayInfo;
} curArrayType;

idlist * idlisthead = NULL;
idlist * idlisttail = NULL;

paramTypeList *paramTypeListHead = NULL;
paramTypeList *paramTypeListTail = NULL;

recordHashStack *recordStackHead = NULL;
recordHashStack *recordStackTail = NULL;

int maxSetEntryId = -1;

int funcProcParamCount = 0;

#endif
