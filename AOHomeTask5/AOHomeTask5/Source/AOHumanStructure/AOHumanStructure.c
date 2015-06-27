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
#include "AOArray.h"

#define AOHumanAssignGetter(var,_iVar){\
    if (var != NULL) {\
    return var->_iVar;\
    }\
    return 0;\
}

#define AOHumanAssignSetter(var,_iVar, newValue){\
    if(var != NULL){\
    var->_iVar = newValue;\
    }\
}


# pragma mark -
# pragma mark Private Accessors

struct AOHuman {
    AOObject _super;
    
    AOString *_name;
    uint _age;
    AOHumanGender _gender;
    AOArray *_children;
    int _childrenCount;
    AOHuman *_partner;
    AOHuman *_mother;
    AOHuman *_father;
};

static
void AOHumanSetPartner(AOHuman *man, AOHuman *woman);

static
AOHuman *AOHumanGetPartner(AOHuman *man);

static
void AOHumanSetName(AOHuman *man, char *newName);

static
char *AOHumanGetName(AOHuman *man);

static
void AOHumanSetGender(AOHuman *man, AOHumanGender gender);

static
AOHumanGender AOHumanGetGender(AOHuman *man);

static
void AOHumanSetAge(AOHuman *man, uint age);

static
int AOHumanGetAge(AOHuman *man);

//static
//void AOHumanSetFather(AOHuman *man, AOHuman *father);
//
//static
//void AOHumanSetMother(AOHuman *man, AOHuman *mother);


void __AOHumanDeallocate(AOHuman *object){
    
    AOHumanDivorce(object, AOHumanGetPartner(object));
   
    __AOObjectDeallocate(object);
    
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
                if (AOHumanGetPartner(woman) != man) {
                    AOHumanDivorce(AOHumanGetPartner(man), man);
                    AOHumanDivorce(AOHumanGetPartner(woman), woman);
                    AOObjectRetain(man);
                    man->_partner = woman;
                    woman->_partner = man;
                }
                AOObjectRelease(man);
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
        AOArrayAddObject(AOHumanGetChildren(parent), child);
    }
}

void AOHumanSetChildAtIndex(AOHuman *man, AOHuman *child, uint index){
        AOArraySetObjectAtIndex(AOHumanGetChildren(man), child, index);
}

AOHuman *AOHumanGetChildAtIndex(AOHuman *man, uint index){
        return AOArrayGetObjectAtIndex(AOHumanGetChildren(man), index);

}

void AOHumanRemoveChildAtIndex(AOHuman *parent, uint index){
        AOArrayRemoveObjectAtIndex(AOHumanGetChildren(parent), index);
}

void AOHumanRemoveAllChildren(AOHuman *parent){
        AOArrayRemoveAllObjects(AOHumanGetChildren(parent));
}

AOHuman *AOHumanGetChildren(AOHuman *man){
    return NULL != man ? man->_children : NULL;
}

void AOHumanSetPartner(AOHuman *man, AOHuman *partner){
    AOHumanAssignSetter(man,_partner, partner);

}

AOHuman *AOHumanGetPartner(AOHuman *man){
    AOHumanAssignGetter(man,_partner);
}
    
void AOHumanSetName(AOHuman *man,char *newName){
    if(man != NULL){
        AOObjectRelease(man->_name);
        AOString *string = AOStringCreateWithString(newName);
        man->_name = string;
        
    }
}

char *AOHumanGetName(AOHuman *man){
    if (man != NULL) {
        return AOStringGetString(man->_name);
    }
    
    return NULL;
}

void AOHumanSetGender(AOHuman *man, AOHumanGender gender){
    AOHumanAssignSetter(man,_gender, gender);
}

AOHumanGender AOHumanGetGender(AOHuman *man) {
    AOHumanAssignGetter(man, _gender);
}

void AOHumanSetAge(AOHuman *man, uint age) {
    AOHumanAssignSetter(man, _age, age);
}

int AOHumanGetAge(AOHuman *man) {
    AOHumanAssignGetter(man, _age);
}

void AOHumanSetFather(AOHuman *child, AOHuman *father) {
    AOHumanAssignSetter(child, _father, father);
}

void AOHumanSetMother(AOHuman *child, AOHuman *mother) {
    AOHumanAssignSetter(child, _mother, mother);
}

AOHuman *AOHumanGetMother(AOHuman *man) {
    AOHumanAssignGetter(man, _mother);
}

AOHuman *AOHumanGetFather(AOHuman *man) {
     AOHumanAssignGetter(man, _father);
}

bool AOHumanGetIsMarried(AOHuman *man) {
    return (man != NULL && man->_partner != NULL);
    
}

