//
//  context.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/21/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_context_h
#define compiler_debugging_context_h

int const CONTEXT_NORMAL = 0;
int const CONTEXT_ARRAY = 1;
int const CONTEXT_RECORD = 2;

int curContext = 0;

typedef struct Context {
    int contextType;
    int contextAttr;//hash code or type entry
} context;

int getContext() {
    return curContext;
}

//switch between normal, record, array context
void contextSwitch(struct IdResp *idInfo) {
    if(idInfo == NULL
       || idInfo->idEntry) {
        context = CONTEXT_NORMAL;
    }
    if(strcmp(idInfo->additionType, "array") == 0) {
        context = CONTEXT_ARRAY;
    }
    else if(strcmp(idInfo->additionType, "record") == 0) {
        context = CONTEXT_RECORD;
    }
    else {
        context = CONTEXT_NORMAL;
    }
    printf("context switched to: %d\n", context);
}

#endif
