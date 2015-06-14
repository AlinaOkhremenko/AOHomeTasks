//
//  AOArrayTest.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 09.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOArrayTest.h"
#include "AOArray.h"
#include "AOHumanStructure.h"
#include "AOObject.h"



static
void AOArrayBehaviourTestMethod(void);

void AOArrayTest(void){
    AOArrayBehaviourTestMethod();
}

void AOArrayBehaviourTestMethod(){
    
    //  after array was created
    
    AOArray *array = AOArrayCreatewithCapacity(20);
    
    //      array must not be NULL
    
    assert(NULL != array);
    
    //      array retain count must be equal 1
    assert(1 == AOObjectGetReferenceCount(array));
    
    //      array objects count muts be equal 0
    assert(0 == AOArrayGetCount(array));
    
    // after object was created
    char *nikita = "Nikita";
    AOHuman *human = AOHumanCreateMan("Nikita", 24, AOHumanGenderMale);
    
    //      object must not be NULL
    assert(NULL != human);
    
    //      object reference count must be equal to 1
    assert(1 == AOObjectGetReferenceCount(human));
    
    //      object index in array must be invalid (object not found)
    assert(kAOIndexNotFount == AOArrayGetIndexOfObject(array, human));
    
    // after object was added to array
    AOArrayAddObject(array, human);
    
    //      array count must be equal to 1
    assert(1 == AOArrayGetCount(array));
    
    //      array reference count must not change
    assert(1 == AOObjectGetReferenceCount(array));
    
    //      object index in array must be 0
    assert(0 == AOArrayGetIndexOfObject(array, human));
    
    //      object reference count must be incremented by 1
    assert(2 == AOObjectGetReferenceCount(human));
    
    //      array object at index 0 must be equal to added object
    assert(AOArrayGetObjectAtIndex(array, 0) == human);
    
    //      array must contain an object
    assert(true == AOArrayContainsObject(array, human));
    
    // after object was removed from array
    AOArrayRemoveObjectAtIndex(array, 0);
    
    //      array count must be equal to 0
    assert(0 == AOArrayGetCount(array));
    
    //      array reference count must not change
    assert(1 == AOObjectGetReferenceCount(array));
    
    //      object index in array must be invalid (object not found)
    assert(kAOIndexNotFount == AOArrayGetIndexOfObject(array, human));
    
    //      object reference count must be decremented by 1
    assert(1 == AOObjectGetReferenceCount(human));
    
    //      array must not contain an object
    assert(false == AOArrayContainsObject(array, human));

}