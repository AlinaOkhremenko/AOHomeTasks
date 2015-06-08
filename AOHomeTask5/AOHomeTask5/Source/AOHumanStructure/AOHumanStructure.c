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

#define AOHumanAssignGetter(var,_iVar){\
    if (var != NULL) {\
    return var->_iVar;\
    }\
    return NULL;\
}

#define AOHumanAssignSetter(var,_iVar, newValue){\
    if(var != NULL){\
    var->_iVar = newValue;\
    }\
}

static const int kMaxChildrenCount = 20;

# pragma mark -
# pragma mark Private



void __AOHumanDeallocate(void *object){
    
    if (AOHumanGetGender((AOHuman *)object) == AOHumanGenderFemale) {
        AOObjectRelease(AOHumanGetPartner(object));
    }
    
    for (int i = 0; i < ((AOHuman *)object)->_childrenCount; i++) {
        
        AOHuman *child = AOHumanGetChildAtIndex((AOHuman *)object, i);
        AOObjectRelease(child);
    }
    
    free(object);
    
}

# pragma mark -
# pragma mark Public

AOHuman *AOHumanCreateMan (char *name, uint age, AOHumanGender gender){
    
    AOHuman *man = AOObjectCreateOfType(AOHuman);
    
    AOHumanSetGender(man, gender);
    AOHumanSetAge(man, age);
    AOHumanSetName(man, name);
    
    return man;
}

AOHuman *AOHumanChildCreate(AOHuman *mother,
                            AOHuman *father,
                            char *name,
                            AOHumanGender gender){
    
    
    AOHuman *child;
    
    child = AOHumanCreateMan(name,0,gender);
    
    AOHumanAddChild(mother, child);
    AOHumanAddChild(father, child);
    
    
    return child;
}

void AOHumanMarriage(AOHuman *human, AOHuman *partner) {
    if (human!= NULL && partner != NULL) {
        AOHumanGender humanGender = AOHumanGetGender(human);
        AOHumanGender partnerGender = AOHumanGetGender(partner);
        
        if(humanGender != AOHumanGenderUndefined && partnerGender != AOHumanGenderUndefined) {
            
            if(humanGender != partnerGender) {
                
                AOHuman *woman = (humanGender == AOHumanGenderFemale) ? human : partner;
                AOHuman *man = (humanGender == AOHumanGenderMale) ? human : partner;
                AOObjectRetain(man);
                AOObjectRetain(woman);
                if (AOHumanGetPartner(woman) != man) {
                    AOHumanDivorce(AOHumanGetPartner(man), man);
                    AOHumanDivorce(AOHumanGetPartner(woman), woman);
                    AOObjectRetain(man);
                    man->_partner = woman;
                    woman->_partner = man;
                }
                AOObjectRelease(man);
                AOObjectRelease(woman);
            }
            else{
                printf("Spiritual clamps in action");
            }
        }
        else{
            printf("AOHumanMarriage: human and partner can't have gender Undefined\n");
        }
    }
    else{
        printf("AOHumanMarriage: man and woman can't be NULL\n");
    }
}

void AOHumanDivorce(AOHuman *human, AOHuman *partner){
    if (human!= NULL && partner != NULL) {
        
        AOHumanGender humanGender = AOHumanGetGender(human);
        AOHumanGender partnerGender = AOHumanGetGender(partner);
        
        if(humanGender != AOHumanGenderUndefined && partnerGender != AOHumanGenderUndefined) {
            
            if(humanGender != partnerGender) {
                
                AOHuman *woman = (humanGender == AOHumanGenderFemale) ? human : partner;
                AOHuman *man = (humanGender == AOHumanGenderMale) ? human : partner;
                
                if (AOHumanGetPartner(woman) == man){
                    woman->_partner = NULL;
                    man->_partner = NULL;
                    AOObjectRelease(man);
                }
            }
            else{
                printf("Spiritual clamps in action");
            }
        }
        else{
            printf("AOHumanDivorce: human and partner can't have gender Undefined\n");
        }
    }
    else{
        printf("AOHumanDivorce: man and woman can't be NULL\n");
    }
}

void AOHumanAddChild(AOHuman *parent, AOHuman *child){
    if(child != NULL && parent != NULL) {
        
        if ( AOHumanGetGender(parent) == AOHumanGenderFemale) {
            child->_mother = parent;
        }
        else{
            child->_father = parent;
        }
        
        if (parent->_childrenCount < kMaxChildrenCount){
            AOHumanSetChildAtIndex(parent, child, parent->_childrenCount);
            parent->_childrenCount++;
            
            child = AOObjectRetain(child);
        }
    }
}

void AOHumanSetChildAtIndex(AOHuman *man, AOHuman *child, uint index){
    if (man != NULL){
        man->_children[index] = child;
    }
}

AOHuman *AOHumanGetChildAtIndex(AOHuman *man, uint index){
    if (man != NULL){
        return man->_children[index];
    }
    return NULL;
}

void AOHumanRemoveChildAtIndex(AOHuman *parent, int index){
    if (parent != NULL) {
        
        if (index < parent->_childrenCount){
            
            AOHuman *child = AOHumanGetChildAtIndex(parent, index);
            AOHumanSetChildAtIndex(parent, NULL, index);
            AOObjectRelease(child);
            parent->_childrenCount--;
            
            for (int j = index; j < (parent->_childrenCount); j++){
                parent->_children[j] = parent->_children[j+1];
            }
        }
    }
}

void AOHumanSetPartner(AOHuman *man, AOHuman *partner){
    AOHumanAssignSetter(man,_partner, partner);

}

AOHuman *AOHumanGetPartner(AOHuman *man){
    AOHumanAssignGetter(man,_partner);
}
    
void AOHumanSetName(AOHuman *man, char *newName){
    if(man != NULL){
        strcpy (man->_humanName, newName);
    }
}

char *AOHumanGetName(AOHuman *man){
    if (man != NULL) {
        return man->_humanName;
    }
    
    return NULL;
}

void AOHumanSetGender(AOHuman *man, AOHumanGender gender){
    AOHumanAssignSetter(man,_gender, gender);
}

AOHumanGender AOHumanGetGender(AOHuman *man){
    AOHumanAssignGetter(man, _gender);
}

void AOHumanSetAge(AOHuman *man, uint age){
    AOHumanAssignSetter(man, _age, age);
}

int AOHumanGetAge(AOHuman *man){
    AOHumanAssignGetter(man, _age);
}

void AOHumanSetFather(AOHuman *child, AOHuman *father){
    AOHumanAssignSetter(child, _father, father);
}

void AOHumanSetMother(AOHuman *child, AOHuman *mother){
    AOHumanAssignSetter(child, _mother, mother);
}

AOHuman *AOHumanGetMother(AOHuman *man){
    AOHumanAssignGetter(man, _mother);
}

AOHuman *AOHumanGetFather(AOHuman *man){
     AOHumanAssignGetter(man, _father);}

bool AOHumanGetIsMarried(AOHuman *man){
    return (man != NULL && man->_partner != NULL);
    
}



