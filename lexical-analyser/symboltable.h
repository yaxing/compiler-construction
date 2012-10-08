//
//  symboltable.h
//  compiler-lexer
//
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_lexer_symboltable_h
#define compiler_lexer_symboltable_h
#include "stdlib.h"
#include "string.h"
typedef struct SymbolEntry {
    long address;
    char *symbolVal;
    char *attribute;
    struct SymbolEntry *next;
} entry;

//head points to the first entry in the table
entry *head = NULL;
//tail points to the last entry in the table
entry *tail = NULL;
long maxId = 0;

void initTable () {
    tail = head;
}

entry *getSymbolTableHead() {
    return head;
}

entry *getSymbolTableTail() {
    return tail;
}

long getSymbolTableMaxId() {
    return maxId;
}

//get a symbol table entry by symbol value and attribute
//@return entry pointer
entry *getSymbolEntry(char *symbolVal, char *attribute) {
    entry *tmpCursor = head;
    while(tmpCursor != NULL) {
        if(strcmp(tmpCursor->symbolVal, symbolVal) == 0
           && strcmp(tmpCursor->attribute, attribute) == 0) {
            return tmpCursor;
        }
        tmpCursor = tmpCursor->next;
    }
    return NULL;
}

//get a symbol table entry by address
//@return entry pointer
entry *getSymbolEntryByAddr(long address) {
    entry *tmpCursor = head;
    while(tmpCursor != NULL) {
        if(tmpCursor->address == address) {
            return tmpCursor;
        }
        tmpCursor = tmpCursor->next;
    }
    return NULL;
}

//register a symbol into symbol table
//@return long the address of registered entry
long registerSymbol(char *symbolVal, char *attribute) {
    entry *tmpCursor = getSymbolEntry(symbolVal, attribute);
    if(tmpCursor != NULL) {
        return tmpCursor->address;
    }
    if(tail == NULL) {
        tail = (entry *)(malloc(sizeof(entry)));
        head = tail;
    }
    else {
        tail->next = (entry *)(malloc(sizeof(entry)));
        tail = tail->next;
    }
    tail->address = maxId ++;
    tail->symbolVal = (char *)malloc(strlen(symbolVal) + 1);
    tail->attribute = (char *)malloc(strlen(attribute) + 1);
    strcpy(tail->symbolVal, symbolVal);
    strcpy(tail->attribute, attribute);
    tail->next = NULL;
    return tail->address;
}

#endif
