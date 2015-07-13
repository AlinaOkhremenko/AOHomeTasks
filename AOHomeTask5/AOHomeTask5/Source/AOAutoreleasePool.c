//
//  AOAutoreleasePool.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 29.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#define kChunkSize 4096

#include "AOAutoreleasePool.h"

struct AOAutoreleasingLinkedListNode {
    AOAutoreleasingLinkedListNode *_next;
    AOObject* _objectsToRelease[kChunkSize];
    int currentSize;
};



void __AOAutoreleasePoolDeallocate(void *object) {
    AOAutoreleaseDrainPool(object);
    
    __AOObjectDeallocate(object);
}


AOAutoreleasePool *AOAutoreleasePoolCreateEmptyPool() {
    AOAutoreleasePool *pool = AOObjectCreateOfType(AOAutoreleasePool);
    pool->_listHead = NULL;
    
    return pool;
}

void AOAutoreleasePoolAddObjectToRelease(AOAutoreleasePool *pool,void *object) {
    if (NULL != pool && NULL != object) {
        
        AOAutoreleasingLinkedListNode *currentHead = pool->_listHead;
        if (currentHead == NULL || currentHead->currentSize == kChunkSize)
        {
            AOAutoreleasingLinkedListNode *newChunk = malloc(sizeof(AOAutoreleasingLinkedListNode));
            newChunk->currentSize = 0;
            newChunk->_next = currentHead;
            pool->_listHead = newChunk;
            
            currentHead = pool->_listHead;
        }
        
        currentHead->_objectsToRelease[currentHead->currentSize] = object;
        currentHead->currentSize++;
    }
}

void AOAutoreleaseDrainPool(AOAutoreleasePool *pool){
    if (NULL != pool) {
        while (pool->_listHead != NULL) {
            AOAutoreleasingLinkedListNode *head = pool->_listHead;
            
            while (head->currentSize > 0) {
                
                AOObject *object = head->_objectsToRelease[head->currentSize-1];
                AOObjectRelease(object);
                head->currentSize--;
            }
            
            pool->_listHead = head->_next;
            free(head);
        }
    }
}

