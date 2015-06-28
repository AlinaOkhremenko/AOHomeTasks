//
//  AOEnumerator.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 27.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOEnumerator__
#define __AOHomeTask5__AOEnumerator__

#include <stdio.h>
#include <stdbool.h>
#include "AOObject.h"

typedef struct AOLinkedListNode AOLinkedListNode;
typedef struct AOLinkedList AOLinkedList;

struct AOLinkedListEnumerator{
    AOObject *_super;
    
    AOLinkedList *_list;
    AOLinkedListNode *_currentNode;
    uint64_t _mutationsCount;
    bool _isValid;    
};

typedef struct AOLinkedListEnumerator AOLinkedListEnumerator;

extern
AOLinkedListEnumerator *AOLinkedListEnumeratorCreateWithList(AOLinkedList *list);

extern
void *AOLinkedListEnumeratorGetNextObject(AOLinkedListEnumerator *enumerator);

extern
void __AOLinkedListEnumeratorDeallocate(void *object);

extern
bool AOLinkedListEnumeratorIsValid(AOLinkedListEnumerator *enumerator);





#endif /* defined(__AOHomeTask5__AOEnumerator__) */
