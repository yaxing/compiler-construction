//
//  symboltabledef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/15/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_symboltabledef_h
#define compiler_debugging_symboltabledef_h
#include "typedescriptor.h"

typedef struct SymbolEntry {
    int address;
    char *symbolVal;
    struct TypeDescriptor *typedesc;
} entry;

typedef struct SymbolTable {
    int size;
    int maxId;
    entry entries[500];
} symboltable;

symboltable *predefinedIdTable;

int const ATTR_TYPE = 0;
int const ATTR_VAR = 1;
int const ATTR_DEFAULT = -1;

//===function declarations===//

symboltable *createSymbolTable();

int checkIndex(symboltable *table, int i);

entry *getSymbolbyName(symboltable *table, char *name);

entry *getSymbolbyEntryId(symboltable *table, int addr);

int getSymbolEntry(symboltable *table, char *symbolVal);

char *getIDName(symboltable *table, int entry);

int extendTable();

char *getIdType(symboltable *table, int entry);

void setTypeAttribute(symboltable *table, int idAddr, char *type,
                      entryAttr attribute, int tag);

entryAttr getCleanAttr(char *type);

void removeTailSymbol(symboltable *table);

int registerSymbol(symboltable *table, char *symbolVal, char *type);

void registerPredefinedIds(symboltable *table, char *ids[], char * type, int size);

void registerKeywordsTypes(symboltable *table);

void initPredefinedSymboltable();

int setSymbolTypeAttrDirec(symboltable *table, int address,
                           char * type, entryAttr attribute, int tag);

int setSymbolEntyTypeAttr(symboltable *table, int idAddr, int typeAddr,
                          entryAttr attribute, int tag);

int getKeyword(char *name);

int getPredefineVar(char *name);

int symbolTableEntryCmp(entry *entry1, entry *entry2);

int symboltableCmp(symboltable *table1, symboltable *table2);



#endif
