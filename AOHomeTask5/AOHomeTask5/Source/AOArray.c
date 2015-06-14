//
//  AOArray.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOArray.h"
#include "AOObject.h"

#define AOHumanAssignGetter(var,_iVar) {\
        if (var != NULL) {\
        return var->_iVar;\
        }\
        return 0;\
    }

static const uint64_t kAOIndexNotFound = UINT64_MAX;

static
void __AOArrayDeallocate(void *object);

static
void AOArraySetCapacity(AOArray *array, uint capacity);

static
void AOArrayResizeIfNeeded(AOArray *array);

static
void AOArraySetCount(AOArray *array, uint count);

static
void AOArraySetObjectAtIndex(AOArray *array, AOArray *object, uint index);

static
void AOArrayRemoveAllObjects(AOArray *array);


void __AOArrayDeallocate(void *object) {

    AOArray *array = object;
    AOArrayRemoveAllObjects(array);
    
    if (NULL != array->_data) {
        free(array->_data);
        array->_data = NULL;
    }
    
    __AOObjectDeallocate(object);
}


AOArray *AOArrayCreatewithCapacity(uint arrayCapacity) {
    
    AOArray *newArray = AOObjectCreateOfType(AOArray);
    
    AOArraySetCapacity(newArray, arrayCapacity);
    
    return newArray;
    
}

void AOArrayAddObject(AOArray *array, void *object) {
    if (NULL != array && NULL != object) {
        uint currentCount = AOArrayGetCount(array);
        AOArraySetCount(array, currentCount + 1);
        AOArraySetObjectAtIndex(array, object, currentCount);
        AOObjectRetain(object);
    }
}

void AOArrayRemoveAllObjects(AOArray *array) {
    if (NULL != array) {
        uint currentCount = AOArrayGetCount(array);
        for (int i = 0; i < currentCount; i++) {
            AOArraySetObjectAtIndex(array, NULL, i);
        }
        AOArraySetCount(array, 0);
    }
}

void AOArrayRemoveObjectAtIndex(AOArray *array, uint index) {
    if (NULL != array) {
        uint currentCount = AOArrayGetCount(array);
        if (index < currentCount) {
            void *objectToRemove = AOArrayGetObjectAtIndex(array, index);
            AOObjectRelease(objectToRemove);
            AOArraySetObjectAtIndex(array, NULL, index);
            
            AOArraySetCount(array, currentCount - 1);
            AOObjectRelease(objectToRemove);
            
            for (int i = index; i < (currentCount - 1); i++) {
                array->_data[i] = array->_data[i+1];
            }
            array->_data[currentCount -1] = NULL;
        }
    }
}

void AOArraySetObjectAtIndex(AOArray *array, AOArray *object, uint index) {
    if (NULL != array && NULL != object) {
        AOArray *existedObject = array->_data[index];
        if (existedObject != object) {
            AOObjectRetain(object);
            AOObjectRelease(object);
            
            array->_data[index] = object;
        }
    }
}

void *AOArrayGetObjectAtIndex(AOArray *array, uint index) {
    if (NULL != array) {
        return array->_data[index];
    }
    return NULL;
}

uint64_t AOArrayGetIndexOfObject(AOArray *array, void *object) {
    if (NULL != array) {
        uint currentCount = AOArrayGetCount(array);
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


void AOArraySetCapacity(AOArray *array, uint capacity) {
    
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
        
        uint currentCount = AOArrayGetCount(array);
        uint currentCapacity = AOArrayGetCapacity(array);
        
        if (currentCount > currentCapacity) {
            
            uint newCapacity = currentCapacity * 2;
            size_t size = newCapacity*(sizeof(*array->_data));
            array->_data = realloc(array->_data, size);
        }
    }
}

uint AOArrayGetCapacity(AOArray *array) {
    AOHumanAssignGetter(array, _arrayCapacity);
}

void AOArraySetCount(AOArray *array, uint count) {
    if (NULL != array) {
        array->_arrayCount = count;
        AOArrayResizeIfNeeded(array);
    }
}

uint AOArrayGetCount(AOArray *array) {
    AOHumanAssignGetter(array, _arrayCount);
}
