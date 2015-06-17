//
//  AOLinkedListNode.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOLinkedListNode.h"
#include "AOObject.h"

void __AOLinkedListNodeDeallocate(void *object) {
    
    AOLinkedListNodeSetData(object, NULL);
    AOLinkedListNodeSetNextNode(object, NULL);
    
    __AOObjectDeallocate(object);
}

AOLinkedListNode *AOLinkedListNodeCreateWithData(void *data) {
    
    AOLinkedListNode *node = AOObjectCreateOfType(AOLinkedListNode);
    AOLinkedListNodeSetData(node, data);
    
    return node;
    
}

void AOLinkedListNodeSetData(AOLinkedListNode *node, void *data) {
    if (NULL != node && data != node->_nodeData) {
        
        AOLinkedListNode *currentNodeData = node->_nodeData;
        currentNodeData = data;
        AOObjectRetain(data);
        AOObjectRelease(currentNodeData);
    }
}

void *AOLinkedListNodeGetData(AOLinkedListNode * node) {
    if (NULL != node) {
        
        return node->_nodeData;
    } else {
        
        return NULL;
    }
}

void AOLinkedListNodeSetNextNode(AOLinkedListNode *node, AOLinkedListNode *newNextNode) {
    if (NULL != node && node->_nextNode != newNextNode) {
        
        AOLinkedListNode *currentNextNode = node->_nextNode;
        AOObjectRelease(currentNextNode);
        AOObjectRetain(newNextNode);
        
        node->_nextNode = newNextNode;
    }
}

AOLinkedListNode *AOLinkedListGetNextNode(AOLinkedListNode *node){
    if (NULL != node) {
        
        return node->_nextNode;
    } else {
        
        return NULL;
    }
}

