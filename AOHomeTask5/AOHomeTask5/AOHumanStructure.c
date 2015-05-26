//
//  AOHumanStructure.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <string.h>
#include <stdlib.h>
#include "AOHumanStructure.h"


void AOHumanDeallocation(AOHumanStruct* man){
    free((void*)man);
}

AOHumanStruct* AOHumanStructRetain(AOHumanStruct* man){
    if (NULL != man) {
        ((AOHumanStruct *)man)->_referenceCount++;
    }
    return man;
}

void AOHumanStructRelease(AOHumanStruct* man){
    if (NULL != man) {
        uint count = ((AOHumanStruct *)man)->_referenceCount - 1;
        ((AOHumanStruct *)man)->_referenceCount = count;
    
        if (0 == count) {
            ((AOHumanStruct *)man)->_deallocator(man);
        }
    }
}

AOHumanStruct* AOHumanStructCreateMan (char *name, uint age, AOHumanGender gender){
    
    AOHumanStruct* man;
    
    man = (AOHumanStruct*) calloc (1, sizeof(AOHumanStruct));
    
    AOHumanSetGender(man, gender);
    AOHumanSetAge(man, age);
    AOHumanSetName(man, name);
    
    man->_referenceCount = 1;
    man->_deallocator = &AOHumanDeallocation;
    man->_childrenCount = 0;
    
    return man;
}

AOHumanStruct* AOHumanStructChildBirth (AOHumanStruct* mother,
                                        AOHumanStruct* father,
                                        char *name, AOHumanGender gender){

    AOHumanStruct* child;
    
    child = AOHumanStructCreateMan(name,0,gender);
    
    AOHumanSetMother(child, mother);
    AOHumanSetFather(child, father);
    
       return child;
}

void AOHumanAddChild(AOHumanStruct* parent, AOHumanStruct* child){
    if(child != NULL && parent != NULL) {
        parent->_children[parent->_childrenCount] = child;
        parent->_childrenCount++;
        
       child = AOHumanStructRetain(child);
    }
}

void AOHumanRemoveChild(AOHumanStruct* parent, AOHumanStruct* child){
    if (child == NULL) {
        for (int iterator = 0; iterator < (parent->_childrenCount); iterator++) {
            if (parent->_children[iterator] == child) {
                AOHumanStructRelease(child);
                parent->_children[iterator] = NULL;
                parent->_childrenCount--;
                for (int j = iterator; j < (parent->_childrenCount); j++){
                    parent->_children[j] = parent->_children[j+1];

                }
                break;
            }
           
        }
    }
}


AOHumanStruct* AOHumanGetFirstBaby(AOHumanStruct* man){
    AOHumanStruct* firstBaby;
    firstBaby = man;
    man->_childrenCount++;
    return firstBaby;
}


void AOHumanStructMarriage(AOHumanStruct* man, AOHumanStruct* woman) {
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

void AOHumanStructDivorce(AOHumanStruct* man, AOHumanStruct* woman){
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

void AOHumanSetPartner(AOHumanStruct* man, AOHumanStruct* partner){
    if (man != NULL && man->_partner != partner) {
        man->_partner = AOHumanStructRetain(partner);
    }
    
    if (partner == NULL && man != NULL) {
        AOHumanStructRelease(partner);
    }
}

void AOHumanSetMarried(AOHumanStruct* man, bool married){
    if (man != NULL){
        man->_isMarried = married;
    }
}

void AOHumanSetGender(AOHumanStruct* man, AOHumanGender gender){
    if (man != NULL){
        man->_gender = gender;
    }
}

AOHumanGender AOHumanGetGender(AOHumanStruct* man){
    if(man != NULL){
        return man->_gender;
    }
    return AOHumanGenderUndefined;
}

void AOHumanSetAge(AOHumanStruct* man, uint age){
     if(man != NULL){
         man->_age = age;
     }
}
    
void AOHumanSetName(AOHumanStruct* man, char *newName){
    if(man != NULL){
        strcpy (man->_humanName, newName);
    }
}

void AOHumanSetFather(AOHumanStruct* child, AOHumanStruct* father){
    if (child != NULL){
        child->_father = father;
    }
}

void AOHumanSetMother(AOHumanStruct* child, AOHumanStruct* mother){
    if (child != NULL){
        child->_mother = mother;
    }
}

