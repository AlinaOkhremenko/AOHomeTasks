//
//  AOString.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include <string.h>
#include "AOString.h"




void __AOStringDeallocate(void *object) {
    
    AOStringSetString(object, NULL);
    
    __AOObjectDeallocate(object);

}

AOString *AOStringCreateWithString(char *string) {
    
    if (NULL == string) {
        return NULL;
    }
    AOString *newString = AOObjectCreateOfType(AOString);
    
    AOStringSetString(newString,string);
    
    return newString;

}

void AOStringSetString(AOString *object, char *data) {
    if (NULL != object && NULL != data) {
        if (NULL != object->_data){
            free(object->_data);
            object->_data = NULL;
        }
        if (NULL != data){
        object->_data = strdup(data);
        assert(NULL != object->_data);
        }
    }
}

char *AOStringGetString(AOString *object) {
    if (NULL != object) {
        return object->_data;
    }
    return 0;
}

bool AOStringIsEmpty(AOString *object) {
    return (0 == AOStringGetLength(object)) ? true : false;
}

size_t AOStringGetLength(AOString *object) {
    return (NULL != object) ? strlen(AOStringGetString(object)) : 0;
    
}
