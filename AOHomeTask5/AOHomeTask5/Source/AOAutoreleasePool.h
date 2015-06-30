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
#include "AOObject.h"

typedef struct AOAutoreleasePool AOAutoreleasePool;
typedef struct AOAutoreleasingLinkedListNode AOAutoreleasingLinkedListNode;

struct AOAutoreleasePool{
    AOObject _super;
    
    AOAutoreleasingLinkedListNode *_listHead;
};

extern
void __AOAutoreleasePoolDeallocate(void *object);

extern
AOAutoreleasePool *AOAutoreleasePoolCreateEmptyPool();

extern
void AOAutoreleasePoolAddObjectToRelease(AOAutoreleasePool *pool,void *object);

extern
void AOAutoreleaseDrainPool(AOAutoreleasePool *pool);



#endif /* defined(__AOHomeTask5__AOAutoreleasePool__) */
