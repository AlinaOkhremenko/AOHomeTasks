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

# pragma mark -
# pragma mark Private


void __AOHumanStructDeallocate(void *object){
    __AOObjectDeallocate(object);
    
}
# pragma mark -
# pragma mark Public

AOHumanStruct* AOHumanStructCreateMan (char *name, uint age, AOHumanGender gender){
    
    AOHumanStruct* man = AOObjectCreateOfType(AOHumanStruct);
    
    AOHumanSetGender(man, gender);
    AOHumanSetAge(man, age);
    AOHumanSetName(man, name);
    
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

void AOHumanStructMarriage(AOHumanStruct *partner1, AOHumanStruct *partner2) {
    if (partner1 != NULL && partner2 != NULL){
        if (AOHumanGetGender(partner1) != AOHumanGetGender(partner2)) {
        
            AOHumanStruct *woman = (AOHumanGetGender(partner1) == AOHumanGenderFemale)
                                    ? partner1
                                    : partner2;
            AOHumanStruct *man = (woman != partner1) ? partner1 : partner2;
        
            if (woman->_partner != NULL && woman->_partner != man) {
            AOHumanStructDivorce(woman, woman->_partner);
            }
            if (man->_partner != NULL && man->_partner != woman) {
              AOHumanStructDivorce(man, man->_partner);
            }
            if (woman->_partner != man){
                AOObjectRetain(man);
                woman->_partner = man;
            }
            if (man->_partner != woman){
                man->_partner = woman;
            }

        }
        else { printf("Spiritual clamps in action");
        }
    }

    else {
        printf("AOHumanStructDivorce: man and woman can't be NULL\n");
    }
}


/*

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

*/

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
        man->_partner = partner;
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

