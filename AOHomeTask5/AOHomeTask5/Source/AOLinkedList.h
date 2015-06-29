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
extern
void __AOLinkedListDeallocate(void *object);

extern
AOLinkedListEnumerator *AOLinkedListEnumeratorFromList(AOLinkedList *list);

extern
AOLinkedList *AOLinkedListCreateEmptyList();

extern
AOLinkedList *AOLinkedListCreateWithObject(void *object);

extern
uint AOLinkedListGetCount(AOLinkedList *list);

extern
AOObject *AOLinkedListGetObjectBeforeObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error);

extern
AOObject *AOLinkedListGetObjectAfterObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error);

extern
void AOLinkedListAddObject(AOLinkedList *list, void *object);

extern
void *AOLinkedListGetFirstObject(AOLinkedList *list);

extern
void AOLinkedListRemoveFirstObject(AOLinkedList *list);

extern
void AOLinkedListRemoveAllObjects(AOLinkedList *list);

extern
bool AOLinkedListIsNotEmpty(AOLinkedList *list);

extern
bool AOLinkedListContainsObject(AOLinkedList *list, void *object);

extern
uint64_t AOLinkedListGetMutationsCount(AOLinkedList *list);

#endif /* defined(__AOHomeTask5__AOLinkedList__) */
