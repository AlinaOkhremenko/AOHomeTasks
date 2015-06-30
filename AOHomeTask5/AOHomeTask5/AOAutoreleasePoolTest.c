//
//  AOAutoreleasePoolTest.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 30.06.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <assert.h>

#include "AOAutoreleasePoolTest.h"
#include "AOAutoreleasePool.h"
#include "AOHumanStructure.h"
#include "AOObject.h"

static
void AOAutoreleasePoolOneObjectTest(void);


static
void AOAutoreleasePoolFullTest(void);


void AOAutoreleasePoolTests(void) {
    AOAutoreleasePoolOneObjectTest();
    AOAutoreleasePoolFullTest();
}

void AOAutoreleasePoolOneObjectTest(void) {
    //    After AutoreleasePool was created
    AOAutoreleasePool *pool = AOAutoreleasePoolCreateEmptyPool();
    
    //    pool must not be NULL
    assert(NULL != pool);
    
    //    after Human was created and retained
    AOHuman *human = AOHumanCreateMan("Nikita", 24, AOHumanGenderMale);
    AOObjectRetain(human);
    
    //    after Human was added to AutoreleasePool
    AOAutoreleasePoolAddObjectToRelease(pool, human);
    
    //    human's reference count must be equal to 3
    assert(3 == AOObjectGetReferenceCount(human));
    
    // after AutoreleasePool was drained
    AOAutoreleaseDrainPool(pool);
    
    //  human's reference count must be 1
    assert(1 == AOObjectGetReferenceCount(human));
    
    AOObjectRelease(pool);
    
}
void AOAutoreleasePoolFullTest(void) {
    
    //    After AutoreleasePool was created
    AOAutoreleasePool *pool = AOAutoreleasePoolCreateEmptyPool();
    
    //    create as many pointers as possible, and add them to the pool
    uint64_t count = UINT32_MAX >> 12;
    
    for (uint64_t i = 0; i < count; i++) {
        AOAutoreleasePoolAddObjectToRelease(pool, AOObjectCreateOfType(AOObject));
    }
    
    //    drain pool
    AOAutoreleaseDrainPool(pool);
    
    //    repeat...
    pool = AOAutoreleasePoolCreateEmptyPool();
    for (uint64_t i = 0; i < count; i++) {
        AOAutoreleasePoolAddObjectToRelease(pool, AOObjectCreateOfType(AOObject));
    }
    //    drain pool again
   AOAutoreleaseDrainPool(pool);
    
    AOObjectRelease(pool);
    
}