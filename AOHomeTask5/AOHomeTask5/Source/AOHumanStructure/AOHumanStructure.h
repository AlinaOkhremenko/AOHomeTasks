//
//  AOHumanStructure.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOHumanStructure__
#define __AOHomeTask5__AOHumanStructure__

#include <stdio.h>
#include <stdbool.h>
#include "AOObject.h"
#include "AOString.h"
#include "AOArray.h"

typedef enum AOHumanGender{
    AOHumanGenderUndefined,
    AOHumanGenderMale,
    AOHumanGenderFemale
} AOHumanGender;

typedef struct AOHuman AOHuman;



extern
AOHuman *AOHumanCreateMan(char *name, uint age, AOHumanGender gender);

extern
AOHuman *AOHumanChildCreate(AOHuman *man, AOHuman *woman, char *name, AOHumanGender gender);

extern
void AOHumanMarriage(AOHuman *human, AOHuman *partner);

extern
void AOHumanAddChild(AOHuman *parent, AOHuman *child);

extern
void AOHumanRemoveChildAtIndex(AOHuman *parent, uint index);

extern
void AOHumanRemoveAllChildren(AOHuman *parent);

extern
void AOHumanDivorce(AOHuman *human, AOHuman *partner);


# pragma mark -
# pragma mark Accessors
extern
AOArray *AOHumanGetChildren(AOHuman *man);

extern
AOHuman *AOHumanGetMother(AOHuman *man);

extern
AOHuman *AOHumanGetFather(AOHuman *man);

extern
bool AOHumanGetIsMarried(AOHuman *man);

extern
void AOHumanSetChildAtIndex(AOHuman *man, AOHuman *child, uint index);

extern
AOHuman *AOHumanGetChildAtIndex(AOHuman *man, uint index);

#endif /* defined(__AOHomeTask5__AOHumanStructure__) */
