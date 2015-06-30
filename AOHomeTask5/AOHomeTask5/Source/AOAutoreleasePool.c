//
//  AOAutoreleasePool.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 29.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOAutoreleasePool.h"


void __AOAutoreleasePoolDeallocate(void *object) {
    AOAutoreleaseDrainPool(object);

    __AOObjectDeallocate(object);
}

AOAutoreleasePool *AOAutoreleasePoolCreateEmptyPool() {
    AOAutoreleasePool *pool = AOObjectCreateOfType(AOAutoreleasePool);
    AOLinkedList *list = AOLinkedListCreateEmptyList();
    pool->_list = list;
    
    return pool;
}

void AOAutoreleasePoolAddObjectToRelease(AOAutoreleasePool *pool,void *object) {
    if (NULL != pool && NULL != object) {
        
        AOLinkedListAddObject(pool->_list, object);
        
    }
}

void AOAutoreleaseDrainPool(AOAutoreleasePool *pool){
    if (NULL != pool) {
        while (AOLinkedListIsNotEmpty(pool->_list)) {
            void *object = AOLinkedListGetFirstObject(pool->_list);
            AOObjectRelease(object);
            AOLinkedListRemoveFirstObject(pool->_list);
        }
    }
}

