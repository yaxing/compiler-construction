//
//  bisonheader.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 10/26/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_bisonheader_h
#define compiler_debugging_bisonheader_h

typedef struct IDLIST {
    int identryAddr;
    struct IDLIST * next;
} idlist;

idlist * idlisthead = NULL;
idlist * idlisttail = NULL;

int latestSetEntries[100] = {};
int maxPos = -1;

//append a new id to current id list
idlist * appendToIdList(int entry) {
    idlist * newnode = (idlist *)malloc(sizeof(idlist));
    newnode->identryAddr = entry;
    if(idlisthead == NULL) {
        idlisthead = newnode;
        idlisttail = idlisthead;
        return idlisttail;
    }
    idlisttail->next = newnode;
    idlisttail = idlisttail->next;
    newnode = NULL;
    return idlisthead;
}

//recursive destroy
void destroyCurIdListRec(idlist * p) {
    if(p != idlisttail || p->next != NULL) {
        destroyCurIdListRec(p->next);
    }
    p = NULL;
}

//clear current idlist
void destroyCurIdList() {
    destroyCurIdListRec(idlisthead);
    idlisthead = NULL;
    idlisttail = idlisthead;
}

void appendToLatestSetList(int entry) {
    if(maxPos >= 99) {
        return;
    }
    latestSetEntries[maxPos] = entry;
    maxPos ++;
}

void cleanLatestSetList() {
    for(int i = 0; i < maxPos; i ++) {
        latestSetEntries[i] = -1;
    }
    maxPos = -1;
}

//set type and attr for all current idlist ids
char * setIdListTypeAttr(int typeEntryAddr, entryAttr attr) {
    scope *curScope;
    idlist * cursor = idlisthead;
    int setResp = 0;
    curScope = getCurScope();
    while(cursor != NULL) {
        printf("setting: %d %d\n", cursor->identryAddr, typeEntryAddr);
        setResp = setSymbolEntyTypeAttr(curScope->symboltable, cursor->identryAddr, typeEntryAddr, attr);
        if(setResp == -1) {
            char * idN = getIDName(curScope->symboltable, cursor->identryAddr);
            char * info = "Redefinition of variable: ";
            char * buf = (char *)malloc(strlen(info) + strlen(idN) + 4);
            sprintf(buf, "%s%s\n", info, idN);
            return buf;
        }
        appendToLatestSetList(cursor->identryAddr);
        cursor = cursor->next;
    }
    destroyCurIdList();
    return NULL;
}

#endif
