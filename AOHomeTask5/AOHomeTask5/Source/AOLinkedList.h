//
//  AOLinkedList.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOLinkedList__
#define __AOHomeTask5__AOLinkedList__

#include <stdio.h>
#include <stdbool.h>
#include "AOObject.h"
#include "AOLinkedListNode.h"

typedef struct AOLinkedListEnumerator AOLinkedListEnumerator;
typedef struct AOLinkedList AOLinkedList;

typedef enum {
    AOLinkedListSearchErrorNoError = 0,
    AOLinkedListSearchErrorObjectIsHead,
    AOLinkedListSearchErrorObjectNotFound,
    AOLinkedListErrorLinkedListIsEmpty
    
} AOLinkedListSearchError;


struct AOLinkedList {
    AOObject _super;
    
    AOLinkedListNode *_head;
    uint _count;
    uint64_t _mutationsCount;
    
};

void __AOLinkedListDeallocate(void *object);

AOLinkedListEnumerator *AOLinkedListEnumeratorFromList(AOLinkedList *list);

AOLinkedList *AOLinkedListCreateWithObject(void *object);

void AOLinkedListSetCount(AOLinkedList *list, uint count);

uint AOLinkedListGetCount(AOLinkedList *list);

AOObject *AOLinkedListGetObjectBeforeObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error);

AOObject *AOLinkedListGetObjectAfterObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error);

void AOLinkedListAddObject(AOLinkedList *list, void *object);

void AOLinkedListRemoveFirstObject(AOLinkedList *list);

void AOLinkedListRemoveAllObjects(AOLinkedList *list);

bool AOLinkedListIsNotEmpty(AOLinkedList *list);

bool AOLinkedListContainsObject(AOLinkedList *list, void *object);



#endif /* defined(__AOHomeTask5__AOLinkedList__) */
