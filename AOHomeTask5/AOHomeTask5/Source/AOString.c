//
//  AOString.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <string.h>
#include "AOString.h"

static
void __AOStringDeallocate(void *object);

static
void AOStringSetString(AOString *object, char *data);


static
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
        object->_data = strdup((const char*)data);
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

int AOStringGetLength(AOString *object) {
    if (NULL != object) {
        char *string = AOStringGetString(object);
        return (int)strlen(string);
    }
    return 0;
}
