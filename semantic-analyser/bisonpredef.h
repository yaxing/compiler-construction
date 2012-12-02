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
    char *code; //var/func/proc name for reference
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

typedef struct ActiveArrayStack {
    idresp *idInfo;
    struct ActiveArrayStack *prev;
} arrayStack;

arrayStack *arrayStackHead = NULL;
arrayStack *arrayStackTail = NULL;

idlist * idlisthead = NULL;
idlist * idlisttail = NULL;

paramTypeList *paramTypeListHead = NULL;
paramTypeList *paramTypeListTail = NULL;

recordHashStack *recordStackHead = NULL;
recordHashStack *recordStackTail = NULL;

//===function declarations===//

int maxSetEntryId = -1;

int funcProcParamCount = 0;

int pushRecordHashInStack(int hash);

int popRecordHashFromStack();

void addCurFuncProcParamCallCounter(int delta);

void cleanCurFuncProcCallParamCounter();

idlist *appendToIdList(int entry);

paramTypeList *appendToParamTypeList(typeinfost *typeInfo);

void destroyCurIdListRec(idlist * p);

void destroyCurIdList();

void destroyParamTypeListRec(paramTypeList *p);

void destroyParamTypeList();

void appendToLatestSetList(int entry);

void cleanLatestSetList();

char *setIdListTypeAttr(int typeEntryAddr, entryAttr attr, int tag);

void registerFunc(int idEntry, int retTypeEntry,
                  entryAttr retTypeAttr, int paramQty);
void setFuncVarInScope(char *funcName, int funcId, int retTypeEntry, entryAttr attr);

void registerProc(int idEntry, int paramQty);

int registerSymbolInCurScope(char *symbolVal);

int setSymbolTypeAttrInCurScope(int idAddr, int typeAddr, entryAttr attribute, int tag);

char *getIDTypeStr(int idEntry);

void removeTailSymbolFromCurScope();

int typeCheck(struct TypeInfo *typeInfo1, struct TypeInfo *typeInfo2);

void constructTypeInfoForCertainSimpleType(struct TypeInfo **typeinfo, char *type);

void constructTypeInfoFromTableEntry(struct TypeInfo **typeinfo, entry *tableEntry);

void constructTypeInfoFromArrayTypeInfo(struct TypeInfo **typeinfo,
                                        struct CURArrayType *arrayTypeInfo);

void constructTypeInfoFromIdResp(struct TypeInfo **typeinfo, struct IdResp *idResp);

char *getDirecTypeName(struct TypeInfo *typeInfo);

char *checkFuncProcCallParamType(struct IdResp *idResp);

int handleRecordStart(struct IdResp *id);

int handleRecordEnd();

int isTypeConstructor(struct IdResp *curIdResp, char *typeConstructor);

void setReduceTypeInfo(struct TypeInfo **typeInfoReduce, struct TypeInfo *typeInfoOp1, struct TypeInfo *typeInfoOp2, int eq);

int isSimpleType(int typeAddr);

char *getTypeName(struct TypeInfo *typeInfo);

void handleArrayVar(struct IdResp **idResp, struct CURArrayType **arrayTypeInfo);

#endif
