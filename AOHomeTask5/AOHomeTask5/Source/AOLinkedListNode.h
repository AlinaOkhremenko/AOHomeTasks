//
//  AOLinkedListNode.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOLinkedListNode__
#define __AOHomeTask5__AOLinkedListNode__

#include <stdio.h>
#include "AOObject.h"

typedef struct AOLinkedListNode AOLinkedListNode;

struct AOLinkedListNode{
    AOObject _super;
    
    AOLinkedListNode *_nextNode;
    void *_nodeData;
    
};

extern
void __AOLinkedListNodeDeallocate(void *object);

extern
AOLinkedListNode *AOLinkedListNodeCreateWithData(void *data);

extern
AOLinkedListNode *AOLinkedListNodeGetNextNode(AOLinkedListNode *node);

extern
void AOLinkedListNodeSetNextNode(AOLinkedListNode *node, AOLinkedListNode *newNextNode);

extern
void *AOLinkedListNodeGetData(AOLinkedListNode *node);

extern
void AOLinkedListNodeSetData(AOLinkedListNode *node, void *data);



#endif /* defined(__AOHomeTask5__AOLinkedListNode__) */
