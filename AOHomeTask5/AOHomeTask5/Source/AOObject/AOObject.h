//
//  AOObject.h
//  AOHomeTask5
//
//  Created by Student 104 on 5/27/15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOObject__
#define __AOHomeTask5__AOObject__

#include <stdio.h>
#include <stdlib.h>

typedef void (*AOObjectDeallocatorCallback)(void *);

typedef struct {
    uint64_t _referenceCount;
    AOObjectDeallocatorCallback _deallocator;
} AOObject;

extern
void *__AOObjectCreate(size_t objectSize, AOObjectDeallocatorCallback deallocateCallback);

#define AOObjectCreateOfType(type) \
__AOObjectCreate(sizeof(type), (AOObjectDeallocatorCallback)__##type##Deallocate)

extern
void *AOObjectRetain(void *object);

extern
void AOObjectRelease(void *object);

extern
uint64_t AOObjectGetReferenceCount(void *object);

extern
void __AOObjectDeallocate(void *object);

#endif /* defined(__AOHomeTask5__AOObject__) */
