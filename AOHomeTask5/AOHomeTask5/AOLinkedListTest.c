//
//  AOLinkedListTest.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 27.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOLinkedListTest.h"
#include "AOLinkedList.h"
#include "AOObject.h"
#include "AOEnumerator.h"



static
void AOLinkedListObjectsTest(void);

static
void AOLinkedListEnumeratorTest(void);

void AOLinkedListBehaviorTest(void){
    AOLinkedListObjectsTest();
    AOLinkedListEnumeratorTest();
    
}

void AOLinkedListEnumeratorTest(){
    
    //  after list was created with 10 objects
    AOLinkedList *newLinkedList = AOObjectCreateOfType(AOLinkedList);
    for (int index; index< 10; index++) {
        AOObject *object = AOObjectCreateOfType(AOObject);
        AOLinkedListAddObject(newLinkedList, object);
        AOObjectRelease(object);
    }
    
    //  list reference count must be 1
    assert(1 == AOObjectGetReferenceCount(newLinkedList));
    
    // list count must be equal 10
    assert(10 == AOLinkedListGetCount(newLinkedList));
    
    //after enumerator was created
    AOLinkedListEnumerator *newEnumerator = AOLinkedListEnumeratorFromList(newLinkedList);
    
    //  list reference count must be 2
     assert(2 == AOObjectGetReferenceCount(newLinkedList));
    
    //  enumerator reference count must be 1
    assert(1 == AOObjectGetReferenceCount(newEnumerator));
    
    // enumerator iterations count must be equal to 10
    AOObjectRelease(newEnumerator);
    AOObjectRelease(newLinkedList);
    

    
}

void AOLinkedListObjectsTest(void){
     //  after list was created
    AOLinkedList *newLinkedList = AOObjectCreateOfType(AOLinkedList);
    
    //      list should be empty
    assert(false == AOLinkedListIsNotEmpty(newLinkedList));
    
    //  after object was created
    AOObject *object = AOObjectCreateOfType(AOObject);
    
    //  after object was added to list
    AOLinkedListAddObject(newLinkedList, object);
    
    //      list must contain object
    assert(true == AOLinkedListContainsObject(newLinkedList, object));
    
    //      object referenceCount must be 2
    assert(2 == AOObjectGetReferenceCount(object));
    
    //      list must not be empty
    assert(true == AOLinkedListIsNotEmpty(newLinkedList));
    
     //      list must contain object
    assert(true == AOLinkedListContainsObject(newLinkedList, object));
    
    //  after object was removed from list
    AOLinkedListRemoveFirstObject(newLinkedList);
    
    //      list should be empty
    assert(false == AOLinkedListIsNotEmpty(newLinkedList));
    
    //      list must not contain object
    assert(false == AOLinkedListContainsObject(newLinkedList, object));
    
    //      object referenceCount must be 1
    assert(1 == AOObjectGetReferenceCount(object));
    
    // after object was added 300 times
    for(uint64_t i = 0; i < 300; i++) {
        AOLinkedListAddObject(newLinkedList, object);
    }
    
    //      list must not be empty
    assert(true == AOLinkedListIsNotEmpty(newLinkedList));
    
    //      list must contain object
    assert(true == AOLinkedListContainsObject(newLinkedList, object));
    
    //      object referenceCount must be 301
    assert(301 == AOObjectGetReferenceCount(object));
    
    // after object was removed from list
    AOLinkedListRemoveFirstObject(newLinkedList);
    
    //      object referenceCount must be 300
    assert(300 == AOObjectGetReferenceCount(object));
    
    // after object was removed from list
    AOLinkedListRemoveAllObjects(newLinkedList);
    
    //      object referenceCount must be 1
    assert(1 == AOObjectGetReferenceCount(object));
    
     //      list should be empty
    assert(false == AOLinkedListIsNotEmpty(newLinkedList));
    
    //      list must not contain object
    assert(false == AOLinkedListContainsObject(newLinkedList, object));
    
    AOObjectRelease(object);
    AOObjectRelease(newLinkedList);

}