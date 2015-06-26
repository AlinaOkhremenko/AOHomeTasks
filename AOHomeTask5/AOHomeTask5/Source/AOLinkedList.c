//
//  AOLinkedList.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOLinkedList.h"
#include "AOLinkedListNode.h"

static
void AOLinkedListSetHead(AOLinkedList *list, AOLinkedListNode *head);

static
AOLinkedListNode *AOLinkedListGetHead(AOLinkedList *list);


void __AOLinkedListDeallocate(AOLinkedList *object) {

    AOLinkedListSetHead(object, NULL);
    

    __AOObjectDeallocate(object);
}

AOLinkedList *AOLinkedListCreateWithObject(void *object) {
    
    AOLinkedList *newLinkedList = AOObjectCreateOfType(AOLinkedList);
    AOLinkedListNode *newLinkedListNode = AOLinkedListNodeCreateWithData(object);
    AOLinkedListSetHead(newLinkedList, newLinkedListNode);
    
    return newLinkedList;
    
}

void AOLinkedListSetHead(AOLinkedList *list, AOLinkedListNode *head) {
    if (NULL != list && NULL != head) {
        AOObjectRetain(head);
        AOObjectRetain(list->_head);
        
         list->_head = head;
    }
}

AOLinkedListNode *AOLinkedListGetHead(AOLinkedList *list) {
    if (NULL != list) {
        return list->_head;
    }
    return NULL;
}

void AOLinkedListSetCount(AOLinkedList *list, uint count) {
    if (count == 0) {
        AOLinkedListSetHead(list, NULL);
    }
    list->_count = count;
    
}

uint AOLinkedListGetCount(AOLinkedList *list) {
    if (NULL != list) {
        return list->_count;
    }
    return 0;
}

void AOLinkedListAddObject(AOLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
        
        AOLinkedListNode *newLinkedListNodeWithObject = AOLinkedListNodeCreateWithData(object);
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        AOLinkedListNodeSetNextNode(newLinkedListNodeWithObject, head);
        AOLinkedListSetHead(list, newLinkedListNodeWithObject);
        AOLinkedListSetCount(list, (AOLinkedListGetCount(list) + 1));
                             
    }
}

void AOLinkedListRemoveFirstObject(AOLinkedList *list) {
    if (NULL != list) {
        
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        AOLinkedListNode *nextNode = AOLinkedListNodeGetNextNode(head);
        AOLinkedListSetHead(list, nextNode);
        AOLinkedListSetCount(list, (AOLinkedListGetCount(list) - 1));
        
    }
}

void AOLinkedListRemoveAllObjects(AOLinkedList *list) {
    if (NULL != list) {
        
        AOLinkedListSetCount(list, 0);
    }
}


AOObject *AOLinkedListGetObjectBeforeObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error) {
    if (NULL != list && NULL != object) {
        
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        if (NULL == head) {
            *error = AOLinkedListErrorLinkedListIsEmpty;
            
            return NULL;
        }
        
        AOObject *currentObject = NULL;
        AOObject *previousObject;
        int count = 0;
        while (NULL != head) {
            previousObject = currentObject;
            currentObject = AOLinkedListNodeGetData(head);
            
            if (currentObject == object) {
                if (count == 0) {
                    *error = AOLinkedListSearchErrorObjectIsHead;
                }
                else {
                    *error = AOLinkedListSearchErrorNoError;
                }
                
                return previousObject;
            }
            count++;
            head = AOLinkedListNodeGetNextNode(head);
        }
    }
    
    *error = AOLinkedListSearchErrorObjectNotFound;
    
    return NULL;
}

AOObject *AOLinkedListGetObjectAfterObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error) {
    if (NULL != list && NULL != object) {
        
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        if (NULL == head) {
            *error = AOLinkedListErrorLinkedListIsEmpty;
            
            return NULL;
        }
        AOObject *nextObject = NULL;
        AOObject *currentObject;
        int count = 0;
        while (NULL != head) {
            currentObject  = nextObject;
            nextObject = AOLinkedListNodeGetData(head);
            if (currentObject == object) {
                if (count == 0) {
                    *error = AOLinkedListSearchErrorObjectIsHead;
                }
                
                else {
                    *error = AOLinkedListSearchErrorNoError;
                }
                
                return nextObject;
            }
            count++;
            head = AOLinkedListNodeGetNextNode(head);
        }
    }
    
    *error = AOLinkedListSearchErrorObjectNotFound;
    
    return NULL;
}

bool AOLinkedListContainsObject(AOLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
      AOLinkedListNode *head = AOLinkedListGetHead(list);
        if (NULL == head){
            return false;
        }
        AOObject *currentObject;
        while (NULL != head) {
            currentObject = AOLinkedListNodeGetData(head);
            if (currentObject == object) {
                
                return true;
            }
            head = AOLinkedListNodeGetNextNode(head);
        }
    }
    return false;
}

bool AOLinkedListIsNotEmpty(AOLinkedList *list) {
    return (NULL != list) && (NULL != AOLinkedListGetHead(list));
}

