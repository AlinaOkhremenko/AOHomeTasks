//
//  AOAutoreleasePool.h
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 29.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask5__AOAutoreleasePool__
#define __AOHomeTask5__AOAutoreleasePool__

#include <stdio.h>
#include "AOLinkedList.h"
#include "AOObject.h"

typedef struct AOAutoreleasePool AOAutoreleasePool;

struct AOAutoreleasePool{
    AOObject _super;
    
    AOLinkedList *_list;
};

extern
void __AOAutoreleasePoolDeallocate(void *object);

extern
AOAutoreleasePool *AOAutoreleasePoolCreateEmptyPool();

extern
void AOAoutoreleasePoolAddObjectToRelease(AOAutoreleasePool *pool,void *object);

extern
void AOAutoreleaseDrainPool(AOAutoreleasePool *pool);



#endif /* defined(__AOHomeTask5__AOAutoreleasePool__) */
