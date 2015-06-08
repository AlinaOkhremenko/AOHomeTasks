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

typedef struct AOHuman AOHuman;

struct AOHuman {
    AOObject _super;
       
    char _humanName[64];
    uint _age;
    AOHumanGender _gender;
    AOHuman *_children[20];
    int _childrenCount;
    AOHuman *_partner;
    AOHuman *_mother;
    AOHuman *_father;
};

extern
AOHuman *AOHumanCreateMan(char *name, uint age, AOHumanGender gender);

extern
AOHuman *AOHumanChildCreate(AOHuman *man, AOHuman *woman, char *name, AOHumanGender gender);

extern
void AOHumanMarriage(AOHuman *human, AOHuman *partner);

extern
void AOHumanAddChild(AOHuman *parent, AOHuman *child);

extern
void AOHumanRemoveChildAtIndex(AOHuman *parent, int index);

extern
void AOHumanDivorce(AOHuman *human, AOHuman *partner);


# pragma mark -
# pragma mark Accessors


extern
void AOHumanSetPartner(AOHuman *man, AOHuman *woman);

extern
AOHuman *AOHumanGetPartner(AOHuman *man);

extern
void AOHumanSetName(AOHuman *man, char *newName);

extern
char *AOHumanGetName(AOHuman *man);

extern
void AOHumanSetGender(AOHuman *man, AOHumanGender gender);

extern
AOHumanGender AOHumanGetGender(AOHuman *man);

extern
void AOHumanSetAge(AOHuman *man, uint age);

extern
int AOHumanGetAge(AOHuman *man);

extern
void AOHumanSetFather(AOHuman *man, AOHuman *father);

extern
void AOHumanSetMother(AOHuman *man, AOHuman *mother);

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
