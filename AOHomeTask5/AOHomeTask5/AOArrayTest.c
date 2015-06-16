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

static
void AOArrayMultipleObjectBehaviourTest(void);

void AOArrayTest(void){
    AOArrayBehaviourTestMethod();
    AOArrayMultipleObjectBehaviourTest();
}

void AOArrayBehaviourTestMethod(){
    
    //  after array was created
    AOArray *array = AOArrayCreatewithCapacity(20);
    
    //      array must not be NULL
    assert(NULL != array);
    
    //      array retain count must be equal 1
    assert(1 == AOObjectGetReferenceCount(array));
    
    //      array objects count must be equal 0
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
    assert(3 == AOObjectGetReferenceCount(human));
    
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
    assert(3 == AOObjectGetReferenceCount(human));
    
    //      array must not contain an object
    assert(false == AOArrayContainsObject(array, human));

}

void AOArrayMultipleObjectBehaviourTest(void) {
    
    AOHuman *human = AOHumanCreateMan("Nikita", 24, AOHumanGenderMale);
    AOHuman *human2 = AOHumanCreateMan("Lilya", 26, AOHumanGenderFemale);
    AOArray *array = AOArrayCreatewithCapacity(20);
    
    
    //  after one origin object was added 5 times in array
    for(int index = 0; index < 5; index++){
     AOArrayAddObject(array, human);
    }
    
    //      array count must be equal to 5
    assert(5 == AOArrayGetCount(array));
    
    //      objects at indices 0 - 4 must be equal to object
    assert(AOArrayGetObjectAtIndex(array, 1) == AOArrayGetObjectAtIndex(array, 2));
    assert(AOArrayGetObjectAtIndex(array, 2) == AOArrayGetObjectAtIndex(array, 3));
    assert(AOArrayGetObjectAtIndex(array, 3) == AOArrayGetObjectAtIndex(array, 4));
    
    //  after added another object2 (not equal to origin object)
    AOArrayAddObject(array, human2);
    
    
    //      array count must be equal to 6
    assert(6 == AOArrayGetCount(array));
    
    //      objects at indices 0 - 4 must be equal to origin object
    
    //      added object2 must be at index 5
    assert(5 == AOArrayGetIndexOfObject(array, human2));
    
    // after object at index 3 was removed
    AOArrayRemoveObjectAtIndex(array, 3);
    
    //      array count must be equal to 5
    assert(5 == AOArrayGetCount(array));
    
    //      objects at indices 0 - 3 must be equal to origin object
    for(int index = 0; index < 4; index ++){
    assert(human == AOArrayGetObjectAtIndex(array, index));
    }
    
    
    //      added object2 must be at index 4
    assert(human2 == AOArrayGetObjectAtIndex(array, 4));
    
    
    // after removing all object from array
    AOArrayRemoveAllObjects(array);
    
    //      array must be empty
    assert(0 == AOArrayGetCount(array));
    
    //      array must no contain origin object ang object2
    assert(false == AOArrayContainsObject(array, human));
    assert(true == AOArrayContainsObject(array, human2));
}
