//
//  AOQueue.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 14.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOQueue.h"
@interface AOQueue ()

@property(nonatomic, retain)    NSMutableArray  *array;

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
        self.array = [[[NSMutableArray alloc] init] autorelease];
    }
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (id)dequeue {
    id headObject = [[self.array objectAtIndex:0] retain];
    if (nil != headObject) {
        [self.array removeObjectAtIndex:0];
    }
    return [headObject autorelease];
}

- (void)enqueue:(id)object {
    [self.array addObject:object];
}

- (NSUInteger)length {
    return self.array.count;
}
@end
