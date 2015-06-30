//
//  AOObject.c
//  AOHomeTask5
//
//  Created by Student 104 on 5/27/15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOObject.h"



void *__AOObjectCreate(size_t objectSize, AOObjectDeallocatorCallback deallocateCallback) {
    
    assert(0 != objectSize);
    
    AOObject *object = calloc(1, objectSize);
    
    assert(NULL != object);
    
    object->_referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *AOObjectRetain(void *object) {
    if (NULL != object) {
        ((AOObject *)object)->_referenceCount++;
    }
    
    return object;
}

void AOObjectRelease(void *object) {
    if (NULL != object) {
        uint64_t count = ((AOObject *)object)->_referenceCount - 1;
        ((AOObject *)object)->_referenceCount = count;
        
        if (0 == count) {
            ((AOObject *)object)->_deallocator(object);
        }
    }
}

uint64_t AOObjectGetReferenceCount(void *object) {
    return object ? ((AOObject*)object)->_referenceCount : 0;
}

void __AOObjectDeallocate(void *object) {
    free(object);
}
