//
//  AOArray.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOArray.h"
#include "AOObject.h"

#define AOHumanAssignGetter(var,_iVar) {\
        if (var != NULL) {\
        return var->_iVar;\
        }\
        return 0;\
    }
#define kCapacityDelta 10;

static const uint64_t kAOIndexNotFound = UINT64_MAX;

static
void __AOArrayDeallocate(void *object);

static
void AOArraySetCapacity(AOArray *array, uint64_t capacity);

static
void AOArrayResizeIfNeeded(AOArray *array);

static
bool AOArrayShouldResize(AOArray *array);

static
uint64_t AOArrayPrefferedCapacity(AOArray *array);

static
void AOArraySetCount(AOArray *array, uint64_t count);


void __AOArrayDeallocate(void *object) {

    AOArray *array = object;
    
    AOArrayRemoveAllObjects(array);
    
    __AOObjectDeallocate(object);
}


AOArray *AOArrayCreatewithCapacity(uint64_t arrayCapacity) {
    
    AOArray *newArray = AOObjectCreateOfType(AOArray);
    
    AOArraySetCapacity(newArray, arrayCapacity);
    
    return newArray;
    
}

void AOArrayAddObject(AOArray *array, void *object) {
    if (NULL != array && NULL != object) {
        uint64_t currentCount = AOArrayGetCount(array);
        AOArraySetCount(array, currentCount + 1);
        AOArraySetObjectAtIndex(array, object, currentCount);
        AOObjectRetain(object);
    }
}

void AOArrayRemoveAllObjects(AOArray *array) {
    if (NULL != array) {
        uint64_t currentCount = AOArrayGetCount(array);
        for (int i = 0; i < currentCount; i++) {
            AOArraySetObjectAtIndex(array, NULL, i);
        }
        AOArraySetCount(array, 0);
    }
}

void AOArrayRemoveObjectAtIndex(AOArray *array, uint64_t index) {
    if (NULL != array) {
        uint64_t currentCount = AOArrayGetCount(array);
        if (index < currentCount) {
            AOArraySetObjectAtIndex(array, NULL, index);
            AOArraySetCount(array, currentCount - 1);
           
            
            for (uint64_t i = index; i < (currentCount - 1); i++) {
                array->_data[i] = array->_data[i+1];
            }
            array->_data[currentCount -1] = NULL;
        }
    }
}

void AOArraySetObjectAtIndex(AOArray *array, void *object, uint64_t index) {
    if (NULL != array) {
        AOArray *existedObject = array->_data[index];
        if (existedObject != object) {
            AOObjectRetain(object);
            AOObjectRelease(existedObject);
            
            array->_data[index] = object;
        }
    }
}

void *AOArrayGetObjectAtIndex(AOArray *array, uint64_t index) {
    if (NULL != array) {
        return array->_data[index];
    }
    return NULL;
}

uint64_t AOArrayGetIndexOfObject(AOArray *array, void *object) {
    if (NULL != array) {
        uint64_t currentCount = AOArrayGetCount(array);
        for (int i = 0; i < currentCount; i++) {
            void *currentObject = array->_data[i];
            if (currentObject == object) {
                return i;
            }
        }
    }
    return kAOIndexNotFound;
}

bool AOArrayContainsObject (AOArray *array, void *object) {
    return NULL != array && kAOIndexNotFound != AOArrayGetIndexOfObject(array, object);
}


void AOArraySetCapacity(AOArray *array, uint64_t capacity) {
    
    if (NULL != array && array->_arrayCapacity != capacity) {
        
        size_t size = capacity * (sizeof(*array->_data));
        if (0 == size && NULL != array->_data) {
            free(array);
            array->_data = NULL;
        }
        else{
            array->_data = realloc(array->_data, size);
        }
    }
    
    array->_arrayCapacity = capacity;
}


void AOArrayResizeIfNeeded(AOArray *array){
    
    if (NULL != array) {
        
        uint64_t currentCount = AOArrayGetCount(array);
        uint64_t currentCapacity = AOArrayGetCapacity(array);
        
        if (currentCount > currentCapacity) {
            uint64_t newCapacity = currentCount + kCapacityDelta;
            assert(newCapacity == kAOIndexNotFound);
            AOArraySetCapacity(array, newCapacity);
        }
    }
}

uint AOArrayGetCapacity(AOArray *array) {
    AOHumanAssignGetter(array, _arrayCapacity);
}

void AOArraySetCount(AOArray *array, uint64_t count) {
    if (NULL != array) {
        assert(kAOIndexNotFound >= count);
        array->_arrayCount = count;
        AOArrayResizeIfNeeded(array);
    }
}

uint AOArrayGetCount(AOArray *array) {
    AOHumanAssignGetter(array, _arrayCount);
}
