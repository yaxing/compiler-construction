//
//  symboltable.h
//  compiler-lexer
//
//  Created by Yaxing Chen on 10/8/12.
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

long registerSymbol(char *symbolVal, char *attribute) {
    entry *tmpCursor = head;
    while(tmpCursor != NULL) {
        if(strcmp(tmpCursor->symbolVal, symbolVal) == 0
           && strcmp(tmpCursor->attribute, attribute) == 0) {
            return tmpCursor->address;
        }
        tmpCursor = tmpCursor->next;
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
