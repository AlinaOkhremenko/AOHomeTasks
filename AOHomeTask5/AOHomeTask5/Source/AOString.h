//
//  AOString.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOString__
#define __AOHomeTask5__AOString__

#include <stdio.h>
#include <stdbool.h>
#include "AOObject.h"

typedef struct {
    AOObject _super;
    
    size_t _length;
    char *_data;
    
} AOString;

void __AOStringDeallocate(void *object);

AOString *AOStringCreateWithString(char *string);

bool AOStringIsEmpty(AOString *object);

size_t AOStringGetLength(AOString *object);

char *AOStringGetString(AOString *object);

void AOStringSetString(AOString *object, char *data);

#endif /* defined(__AOHomeTask5__AOString__) */
