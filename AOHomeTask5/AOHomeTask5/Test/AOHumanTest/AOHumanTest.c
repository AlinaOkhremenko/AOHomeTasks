//
//  AOHumanTest.c
//  AOHomeTask5
//
//  Created by Student 104 on 5/27/15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <assert.h>

#include "AOHumanTest.h"

#pragma mark -
#pragma mark Private
static
void AOHumanTestMethod(void);

#pragma mark -
#pragma mark Public Implementation

void AOHumanTest(void){
    AOHumanTestMethod();
}

#pragma mark -
#pragma mark Private Implementation

void AOHumanTestMethod(void){
    // creation of a human with "Male" gender
    AOHuman *nikita = AOHumanCreateMan("Nikita", 24, AOHumanGenderMale);
    
    //      the creaed human must not be NULL
    assert(NULL != nikita);
    
    //      after a human was created -> the reference count must be equal to 1
    assert(1 == AOObjectGetReferenceCount(nikita));
    
    //creation of a human with "Female" gender
    AOHuman *olya = AOHumanCreateMan("Olya", 24, AOHumanGenderFemale);
    
    //      the creaed human must not be NULL
    assert(NULL != olya);
    
    //      after a human was created -> the reference count must be equal to 1
    assert(1 == AOObjectGetReferenceCount(olya));
    
    // before the marriage our humans do not have partners
    assert(false == AOHumanGetIsMarried(nikita));
    assert(false == AOHumanGetIsMarried(olya));
    
    // marriage for previously created humans;
    AOHumanMarriage(nikita, olya);
    
    // the reference count of Male human must be incremented after the marriage, as the Female human retains our Male human
    assert(2 == AOObjectGetReferenceCount(nikita));
    
    // the reference count of Female human must be equal to its reference count before the procedure of Marriage
    assert(1 == AOObjectGetReferenceCount(olya));
    
    //creating child for previously created humans
    AOHuman *child = AOHumanChildCreate(nikita, olya, "Masya", AOHumanGenderMale);
    
    //      the reference count for just created child must be 3
    assert(3 == AOObjectGetReferenceCount(child));
    
    //      the first child must be equal to the created child previously
    assert(child == AOHumanGetChildAtIndex(nikita, 0));

    AOHumanSetChildAtIndex(nikita, child, 4);
    assert(child == AOHumanGetChildAtIndex(nikita, 4));
   
    //before the divorce we making release to woman and checking the reference count
    AOObjectRelease(olya);
    assert(0 == AOObjectGetReferenceCount(olya));
    assert(1 == AOObjectGetReferenceCount(nikita));
    
    //before the divorce we making release for man and checking the refence count for both
    AOObjectRelease(nikita);
    assert(0 == AOObjectGetReferenceCount(olya));
    assert(0 == AOObjectGetReferenceCount(nikita));
    
    // after releasing the woman -> reference count for man decreasing for 1;
    assert(1 == AOObjectGetReferenceCount(nikita));

    //making divorce for our humans
    AOHumanDivorce(nikita, olya);
    
    //  after divorce reference count for man decreasing for 1
     assert(1 == AOObjectGetReferenceCount(nikita));
    
    //printf("Nikita's partner is: %s", nikita->_partner->_humanName);
    //printf("Nikita's child is: %s", nameOfChild);

}
