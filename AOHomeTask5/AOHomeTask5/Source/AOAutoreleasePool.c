//
//  AOAutoreleasePool.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 29.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOAutoreleasePool.h"

struct AOAutoreleasingLinkedListNode {
    AOAutoreleasingLinkedListNode *_next;
    AOObject *_objectToRelease;
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
        
        AOAutoreleasingLinkedListNode *newNode = malloc(sizeof(AOAutoreleasingLinkedListNode));
        newNode->_objectToRelease = object;
        newNode->_next = pool->_listHead;
        
        pool->_listHead = newNode;
    }
}

void AOAutoreleaseDrainPool(AOAutoreleasePool *pool){
    if (NULL != pool) {
        while (pool->_listHead != NULL) {
            AOAutoreleasingLinkedListNode *head = pool->_listHead;
            
            AOObject *object = head->_objectToRelease;
            AOObjectRelease(object);
            
            pool->_listHead = head->_next;
            free(head);
        }
    }
}

