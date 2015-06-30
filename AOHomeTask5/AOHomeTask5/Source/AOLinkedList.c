//
//  AOLinkedList.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOLinkedList.h"
#include "AOLinkedListNode.h"
#include "AOEnumerator.h"

static
void AOLinkedListSetHead(AOLinkedList *list, AOLinkedListNode *head);

static
AOLinkedListNode *AOLinkedListGetHead(AOLinkedList *list);

static
void AOLinkedListSetCount(AOLinkedList *list, uint count);


void __AOLinkedListDeallocate(void *object) {
    AOLinkedListRemoveAllObjects(object);
    

    __AOObjectDeallocate(object);
}

struct AOLinkedListEnumerator *AOLinkedListEnumeratorFromList(AOLinkedList *list) {
    return AOLinkedListEnumeratorCreateWithList(list);
}

AOLinkedList *AOLinkedListCreateEmptyList(){
    AOLinkedList *newLinkedList = AOObjectCreateOfType(AOLinkedList);
    
    return newLinkedList;
}

AOLinkedList *AOLinkedListCreateWithObject(void *object) {
    
    AOLinkedList *newLinkedList = AOObjectCreateOfType(AOLinkedList);
    AOLinkedListNode *newLinkedListNode = AOLinkedListNodeCreateWithData(object);
    AOLinkedListSetHead(newLinkedList, newLinkedListNode);
    
    return newLinkedList;
    
}

void AOLinkedListSetHead(AOLinkedList *list, AOLinkedListNode *head) {
    if (NULL != list) {
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
    list->_count = count;
}

uint AOLinkedListGetCount(AOLinkedList *list) {
    if (NULL != list) {
        return list->_count;
    }
    return 0;
}

void AOLinkedListAddObject(AOLinkedList *list, void *object) {
    if (NULL != list) {
        
        AOLinkedListNode *newLinkedListNodeWithObject = AOLinkedListNodeCreateWithData(object);
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        if (NULL == head) {
            AOLinkedListSetHead(list, newLinkedListNodeWithObject);
        }
        else {
            AOLinkedListNodeSetNextNode(newLinkedListNodeWithObject, head);
            AOLinkedListSetHead(list, newLinkedListNodeWithObject);
            
        }
    
        AOLinkedListSetCount(list, (AOLinkedListGetCount(list) + 1));
    }
}

void *AOLinkedListGetFirstObject(AOLinkedList *list) {
    if (NULL != list) {
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        void *object = AOLinkedListNodeGetData(head);
        
        return object;
    }
    
    return NULL;
}

void AOLinkedListRemoveFirstObject(AOLinkedList *list) {
    if (NULL != list) {
        
        AOLinkedListNode *head = AOLinkedListGetHead(list);
        AOLinkedListNode *nextNode = AOLinkedListNodeGetNextNode(head);
        
        AOLinkedListSetHead(list, nextNode);
        AOObjectRelease(head);
        AOLinkedListSetCount(list, (AOLinkedListGetCount(list) - 1));
       
    }
}

void AOLinkedListRemoveAllObjects(AOLinkedList *list) {
    while (AOLinkedListIsNotEmpty(list)) {
        AOLinkedListRemoveFirstObject(list);
    }
}

AOObject *AOLinkedListGetObjectBeforeObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error) {
    if (NULL != list && NULL != object) {
        
        AOLinkedListNode *node = AOLinkedListGetHead(list);
        if (NULL == node) {
            if (NULL != error) {
            *error = AOLinkedListErrorLinkedListIsEmpty;
            }
            
            return NULL;
        }
        
        AOObject *currentObject = NULL;
        AOObject *previousObject;
        int count = 0;
        while (NULL != node) {
            previousObject = currentObject;
            currentObject = AOLinkedListNodeGetData(node);
            
            if (currentObject == object) {
                if (count == 0) {
                    if (NULL != error) {
                    *error = AOLinkedListSearchErrorObjectIsHead;
                    }
                }
                else {
                    if (NULL != error) {
                    *error = AOLinkedListSearchErrorNoError;
                    }
                }
                
                return previousObject;
            }
            count++;
            node = AOLinkedListNodeGetNextNode(node);
        }
          *error = AOLinkedListSearchErrorObjectNotFound;
    }
    
  
    
    return NULL;
}

AOObject *AOLinkedListGetObjectAfterObject(AOLinkedList *list, void *object, AOLinkedListSearchError *error) {
    if (NULL != list && NULL != object) {
        
        AOLinkedListNode *node = AOLinkedListGetHead(list);
        if (NULL == node) {
            *error = AOLinkedListErrorLinkedListIsEmpty;
            
            return NULL;
        }
        AOObject *nextObject = NULL;
        AOObject *currentObject;
        int count = 0;
        while (NULL != node) {
            currentObject  = nextObject;
            nextObject = AOLinkedListNodeGetData(node);
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
            node = AOLinkedListNodeGetNextNode(node);
        }
    
        if(NULL != error) {
            *error = AOLinkedListSearchErrorObjectNotFound;
        }
    }
    return NULL;
}

bool AOLinkedListContainsObject(AOLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
      AOLinkedListNode *node = AOLinkedListGetHead(list);
        if (NULL == node){
            return false;
        }
        AOObject *currentObject;
        while (NULL != node) {
            currentObject = AOLinkedListNodeGetData(node);
            if (currentObject == object) {
                
                return true;
            }
            node = AOLinkedListNodeGetNextNode(node);
        }
    }
    return false;
}

bool AOLinkedListIsNotEmpty(AOLinkedList *list) {
    return (NULL != list) && (NULL != AOLinkedListGetHead(list));
}

uint64_t AOLinkedListGetMutationsCount(AOLinkedList *list) {
    if (NULL != list) {
        return list->_mutationsCount;
    }
    return 0;
}

