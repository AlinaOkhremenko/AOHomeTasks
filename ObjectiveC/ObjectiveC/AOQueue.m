//
//  AOQueue.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 14.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOQueue.h"
@interface AOQueue ()

@property (nonatomic, retain)    NSMutableArray  *array;

@end

@implementation AOQueue
#pragma mark-
#pragma mark Deallocations and Initializations

- (void)dealloc {
    self.array = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (nil != self) {
        self.array = [[NSMutableArray alloc] init];
    }
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (id)dequeue {
    @synchronized(self.array) {
        id headObject = [[self.array firstObject] retain];
        if (nil != headObject) {
            [self.array removeObject:headObject];
        }
        
        return [headObject autorelease];
    }
}

- (void)enqueue:(id)object {
    @synchronized(self.array){
        [self.array addObject:object];
    }
}

- (NSUInteger)length {
    @synchronized(self.array){
        return self.array.count;
    }
}

@end
