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

//set type and attr for all current idlist ids
void setIdListTypeAttr(int typeEntryAddr, char * attr) {
    idlist * cursor = idlisthead;
    while(cursor != NULL) {
        setSymbolEntyTypeAttr(cursor->identryAddr, typeEntryAddr, attr);
        cursor = cursor->next;
    }
    destroyCurIdList();
}

#endif
