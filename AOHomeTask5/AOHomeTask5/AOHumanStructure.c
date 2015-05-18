//
//  AOHumanStructure.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <string.h>
#include "AOHumanStructure.h"


AOHumanStruct* AOHumanStructCreateMan (char *name, int age, AOHumanGender gender){
    
    AOHumanStruct *man;
    
    man = (AOHumanStruct*) calloc (1, sizeof(AOHumanStruct));
    
    AOHumanSetGender(man, gender);
    AOHumanSetAge(man, age);
    AOHumanSetName(man, name);
    
    return man;
    
}

AOHumanStruct *AOHumanStructChildBirth (AOHumanStruct *mother, AOHumanStruct *father){

    AOHumanStruct *child;
    
    child = (AOHumanStruct*) calloc (1, sizeof(AOHumanStruct));
    
    AOHumanSetMother(child, mother);
    AOHumanSetFather(child, father);
    
    return child;
    
}


void AOHumanStructMarriage(AOHumanStruct *man, AOHumanStruct *woman) {
    if(man != NULL && woman != NULL){
        AOHumanSetPartner(man, woman);
        AOHumanSetPartner(woman, man);
        AOHumanSetMarried(man, 1);
        AOHumanSetMarried(woman, 1);
    }
    else{
        printf("AOHumanStructDivorce: man and woman can't be NULL\n");
    }
}


void AOHumanStructDivorce(AOHumanStruct *man, AOHumanStruct *woman){
    if(man != NULL && woman != NULL){
        AOHumanSetPartner(man, NULL);
        AOHumanSetPartner(woman, NULL);
        AOHumanSetMarried(man, 0);
        AOHumanSetMarried(woman, 0);
    }
    else{
        printf("AOHumanStructDivorce: man and woman can't be NULL\n");
    }
}

void AOHumanSetPartner(AOHumanStruct *man, AOHumanStruct *partner){
    if (man != NULL){
        man->_partner = partner;
    }
}

void AOHumanSetMarried(AOHumanStruct *man, bool married){
    if (man != NULL){
        man->_isMarried = married;
    }
}


void AOHumanSetGender(AOHumanStruct *man, AOHumanGender gender){
    if (man != NULL){
        man->_gender = gender;
    }
    
}

AOHumanGender AOHumanGetGender(AOHumanStruct *man){
    if (man != NULL){
        return man->_gender;
}
};

void AOHumanSetAge(AOHumanStruct *man, int age){
     if (man != NULL){
         man->_age = age;
     }
}
    
void AOHumanSetName(AOHumanStruct *man, char *newName){
    if (man != NULL){
        strcpy (man->_humanName, newName);
    }
}

void AOHumanSetFather(AOHumanStruct *child, AOHumanStruct *father){
    if (child != NULL){
        child->_father = father;
    }
}

void AOHumanSetMother(AOHumanStruct *child, AOHumanStruct *mother){
    if (child != NULL){
        child->_mother = mother;
    }
}

