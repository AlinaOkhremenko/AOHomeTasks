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
    
    // after a human was created -> the reference count must be equal to 1
    assert(1 == AOObjectGetReferenceCount(nikita));
    
    //creation of a human with "Female" gender
    AOHuman *olya = AOHumanCreateMan("Olya", 24, AOHumanGenderFemale);
    
    // after a human was created -> the reference count must be equal to 1
    assert(1 == AOObjectGetReferenceCount(olya));
    
    // marriage for previously created humans;
    AOHumanMarriage(nikita, olya);
    
    // the reference count of Male human must be incremented after the marriage, as the Female human retains our Male human
    assert(2 == AOObjectGetReferenceCount(nikita));
    
    // the reference count of Female human must be equal to its reference count before the procedure of Marriage
    assert(1 == AOObjectGetReferenceCount(olya));
    
    //creating child for previously created humans
    AOHuman *child = AOHumanChildCreate(nikita, olya, "Masya", AOHumanGenderMale);
    
    //the reference count for just created child must be 3
    assert(3 == AOObjectGetReferenceCount(child));
    
    
    AOHumanGetChildAtIndex(nikita, 0);

    
    AOHumanDivorce(nikita, olya);
    
    
    //printf("Nikita's partner is: %s", nikita->_partner->_humanName);
    //printf("Nikita's child is: %s", nameOfChild);
    
}
