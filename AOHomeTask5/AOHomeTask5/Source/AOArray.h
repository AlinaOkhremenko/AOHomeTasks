//
//  AOArray.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOArray__
#define __AOHomeTask5__AOArray__

#include <stdio.h>
#include "AOObject.h"
#include "AOHumanStructure.h"

typedef struct {
    AOObject _super;
    
    uint _arrayCapacity;
    uint _arrayCount;
    void **_data;
    
} AOArray;


AOArray *AOArrayCreatewithCapacity(uint arrayCapacity);

void AOArrayAddObject(AOArray *array, void *object);

void AOArrayRemoveObjectAtIndex(AOArray *array, uint index);

AOArray *AOArrayAddObjectAtIndex(AOArray *array, void *object, uint index);

uint AOArrayGetCapacity(AOArray *array);

uint AOArrayGetCount(AOArray *array);

bool AOArrayContainsObject (AOArray *array, void *object);

void *AOArrayGetObjectAtIndex(AOArray *array, uint index);

uint64_t AOArrayGetIndexOfObject(AOArray *array, void *object);
















#endif /* defined(__AOHomeTask5__AOArray__) */
