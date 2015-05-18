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

typedef enum AOHumanGender{
    Male,
    Female,
    Undefined,
} AOHumanGender;

typedef struct AOHumanStruct{
    char _humanName[64];
    int _age;
    AOHumanGender _gender;
    struct AOHumanStruct* _children[20];
    bool _isMarried;
    struct AOHumanStruct* _partner;
    struct AOHumanStruct* _mother;
    struct AOHumanStruct* _father;
    
} AOHumanStruct;

extern
AOHumanStruct* AOHumanStructCreateMan (char *name, int age, AOHumanGender gender);

extern
void AOHumanStructMarriage (AOHumanStruct *man, AOHumanStruct *woman);

extern
void AOHumanStructDivorce (AOHumanStruct *man, AOHumanStruct *woman);

extern
AOHumanStruct* AOHumanStructChildBirth (AOHumanStruct *man, AOHumanStruct *woman);

extern
void AOHumanSetPartner(AOHumanStruct *man, AOHumanStruct *woman);

extern
void AOHumanSetMarried(AOHumanStruct *man, bool married);

extern
void AOHumanSetGender(AOHumanStruct *man, AOHumanGender gender);

extern
AOHumanGender AOHumanGetGender(AOHumanStruct *man);

extern
void AOHumanSetAge(AOHumanStruct *man, int age);

extern
void AOHumanSetName(AOHumanStruct *man, char *newName);

extern
void AOHumanSetFather(AOHumanStruct *man, AOHumanStruct *father);

extern
void AOHumanSetMother(AOHumanStruct *man, AOHumanStruct *mother);






#endif /* defined(__AOHomeTask5__AOHumanStructure__) */
