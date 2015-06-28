//
//  AOEnumerator.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 27.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <assert.h>
#include "AOEnumerator.h"
#include "AOLinkedList.h"
#include "AOLinkedListNode.h"

static
void AOLinkedListEnumeratorSetList(AOLinkedListEnumerator *enumerator, AOLinkedList *list);

static
AOLinkedList *AOLinkedListEnumeratorGetList(AOLinkedListEnumerator *enumerator);

static
void AOLinkedListEnumeratorSetNode(AOLinkedListEnumerator *enumerator, AOLinkedListNode *node);

static
AOLinkedListNode *AOLinkedListEnumeratorGetNode(AOLinkedListEnumerator *enumerator);

static
void AOLinkedListEnumeratorSetMutationsCount(AOLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t AOLinkedListEnumeratorGetMutationsCount(AOLinkedListEnumerator *enumerator);

static
void AOLinkedListEnumeratorSetValid(AOLinkedListEnumerator *enumerator, bool isValid);

static
bool AOLinkedListEnumeratorMutationsValidate(AOLinkedListEnumerator *enumerator);

                                                      
void __AOLinkedListEnumeratorDeallocate(void *object) {
    
    AOLinkedListEnumeratorSetList(object, NULL);
    AOLinkedListEnumeratorSetNode(object, NULL);
    
    __AOObjectDeallocate(object);
}


AOLinkedListEnumerator *AOLinkedListEnumeratorCreateWithList(AOLinkedList *list) {
    if (NULL != list){
        AOLinkedListEnumerator *enumerator = AOObjectCreateOfType(AOLinkedListEnumerator);
        printf("%d", enumerator->_super->_referenceCount);
        enumerator->_list = NULL;
        AOLinkedListEnumeratorSetList(enumerator, list);
        
        AOLinkedListEnumeratorSetMutationsCount(enumerator,AOLinkedListEnumeratorGetMutationsCount(enumerator));
        
        AOLinkedListEnumeratorSetValid(enumerator, true);
        
        return enumerator;
    }
    return NULL;
}


void *AOLinkedListEnumeratorGetNextObject(AOLinkedListEnumerator *enumerator) {
    if (NULL != enumerator){
        if (true == AOLinkedListEnumeratorMutationsValidate(enumerator)) {
            
            AOLinkedListNode *currentNode = AOLinkedListEnumeratorGetNode(enumerator);
            AOLinkedListNode *nextNode = AOLinkedListNodeGetNextNode(currentNode);
            AOLinkedListEnumeratorSetNode(enumerator, nextNode);
        
        if (NULL == nextNode) {
            
            AOLinkedListEnumeratorSetValid(enumerator, false);
        }
    
            return AOLinkedListNodeGetData(nextNode);
    }
    }
    return NULL;
}


bool AOLinkedListEnumeratorMutationsValidate(AOLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
        AOLinkedList *list = AOLinkedListEnumeratorGetList(enumerator);
        assert(AOLinkedListEnumeratorGetMutationsCount(enumerator) == AOLinkedListGetMutationsCount(list));
        return true;
    }
    return false;
}


bool AOLinkedListEnumeratorIsValid(AOLinkedListEnumerator *enumerator) {
    return (NULL != enumerator)&& (enumerator->_isValid);
}


void AOLinkedListEnumeratorSetValid(AOLinkedListEnumerator *enumerator, bool isValid) {
    if (NULL != enumerator) {
        enumerator->_isValid = isValid;
    }
}

void AOLinkedListEnumeratorSetList(AOLinkedListEnumerator *enumerator, AOLinkedList *list) {
    if (NULL != enumerator && enumerator->_list != list) {
        AOObjectRetain(list);
        AOObjectRelease(enumerator->_list);
        
        enumerator->_list = list;
    }
}

AOLinkedList *AOLinkedListEnumeratorGetList(AOLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
        return enumerator->_list;
    }
    return NULL;
}

void AOLinkedListEnumeratorSetNode(AOLinkedListEnumerator *enumerator, AOLinkedListNode *node) {
    if (NULL != enumerator && enumerator->_currentNode != node) {
        AOObjectRetain(node);
        AOObjectRelease(enumerator->_currentNode);
        
        enumerator->_currentNode = node;
    }
}


AOLinkedListNode *AOLinkedListEnumeratorGetNode(AOLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
        return enumerator->_currentNode;
    }
    return NULL;
}


void AOLinkedListEnumeratorSetMutationsCount(AOLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    if (NULL != enumerator) {
        
        enumerator->_mutationsCount = mutationsCount;
    }
}

uint64_t AOLinkedListEnumeratorGetMutationsCount(AOLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
        return enumerator->_mutationsCount;
    }
    return 0;
}



