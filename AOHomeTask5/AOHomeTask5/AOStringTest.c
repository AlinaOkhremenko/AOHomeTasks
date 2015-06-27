//
//  AOStringTest.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOStringTest.h"
#include "AOStringTest.h"
#include "AOString.h"

static
void AOStringBehaviourTest(void);

void AOStringTests(void) {
    AOStringBehaviourTest();
}

void AOStringBehaviourTest(void){
    // after string was created
    AOString *string = AOStringCreateWithString("Alina");
   
    //      string must not be NULL
    assert(NULL != string);
  
    //      string reference count must be equal 1
    assert(1 == AOObjectGetReferenceCount(string));
   
    //      length of created string must be equal 6 (5 + '/0')
    assert(5 == AOStringGetLength(string));
    
    // after emptyString was created
    AOString *emptyString = AOStringCreateWithString("");
   
    //      emptyString must not be NULL
    assert(NULL != emptyString);
 
    //      emptyString reference count must be equal 1
    assert(1 == AOObjectGetReferenceCount(emptyString));
  
    //      length of string must be equal 0
    assert(0 == AOStringGetLength(emptyString));
    
    // our string and emptyString are not equal
    assert(string != emptyString);

    // string must not be empty
    assert(false == AOStringIsEmpty(string));
    
    // emptyString must be empty
    assert(true == AOStringIsEmpty(emptyString));
    
    
    // after releasing our string
    AOObjectRelease(string);
  
    //      string after releasing has reference count = 0;
    assert(0 == AOObjectGetReferenceCount(string));

    
    // after releasing our emptystring
    AOObjectRelease(emptyString);
    
    //      emptyString after releasing has reference count = 0;
    assert(0 == AOObjectGetReferenceCount(emptyString));
 
    AOObjectRelease(string);
    AOObjectRelease(emptyString);
}
