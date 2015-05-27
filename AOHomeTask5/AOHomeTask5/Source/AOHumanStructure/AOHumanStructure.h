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

typedef enum AOHumanGender{
    AOHumanGenderUndefined,
    AOHumanGenderMale,
    AOHumanGenderFemale
} AOHumanGender;

typedef struct AOHumanStruct AOHumanStruct;

struct AOHumanStruct {
    AOObject _super;
       
    char _humanName[64];
    uint _age;
    AOHumanGender _gender;
     AOHumanStruct *_children[20];
    int _childrenCount;
    AOHumanStruct *_partner;
    AOHumanStruct *_mother;
    AOHumanStruct *_father;
    
};


extern
AOHumanStruct *AOHumanStructCreateMan(char *name, uint age, AOHumanGender gender);

extern
void AOHumanStructMarriage(AOHumanStruct *human, AOHumanStruct *partner);

extern
void AOHumanAddChild(AOHumanStruct *parent, AOHumanStruct *child);

extern
AOHumanStruct *AOHumanStructChildBirth(AOHumanStruct *man, AOHumanStruct* woman, char *name, AOHumanGender gender);

extern
void AOHumanStructDivorce(AOHumanStruct *man, AOHumanStruct *woman);

# pragma mark -
# pragma mark Accessors


extern
AOHumanStruct *AOHumanGetFirstBaby(AOHumanStruct *man);

extern
void AOHumanSetPartner(AOHumanStruct *man, AOHumanStruct *woman);

extern
void AOHumanGetPartner(AOHumanStruct *man);

extern
void AOHumanSetName(AOHumanStruct *man, char *newName);

extern
char AOHumanGetName(AOHumanStruct *man);

extern
void AOHumanSetGender(AOHumanStruct* man, AOHumanGender gender);

extern
AOHumanGender AOHumanGetGender(AOHumanStruct *man);

extern
void AOHumanSetAge(AOHumanStruct *man, uint age);

extern
int AOHumanGetAge(AOHumanStruct *man);

extern
void AOHumanSetFather(AOHumanStruct *man, AOHumanStruct *father);

extern
void AOHumanSetMother(AOHumanStruct *man, AOHumanStruct *mother);

extern
AOHumanStruct *AOHumanGetMother(AOHumanStruct *man);

extern
AOHumanStruct *AOHumanGetFather(AOHumanStruct *man);





#endif /* defined(__AOHomeTask5__AOHumanStructure__) */
