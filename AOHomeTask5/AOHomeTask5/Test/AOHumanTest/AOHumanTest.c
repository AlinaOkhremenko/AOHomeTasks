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
    
    AOHumanStruct *nikita = AOHumanStructCreateMan("Nikita", 24, AOHumanGenderMale);
    assert(1 == AOObjectGetReferenceCount(nikita));
    
    
    AOHumanStruct *olya = AOHumanStructCreateMan("Olya", 24, AOHumanGenderFemale);
    assert(1 == AOObjectGetReferenceCount(olya));
    
    AOHumanStructMarriage(nikita, olya);
    
    
    printf("Nikita's partner is: %s", nikita->_partner->_humanName);
    
}
