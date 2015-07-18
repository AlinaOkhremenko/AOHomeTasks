//
//  AOCreature.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 13.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCreature.h"

@interface AOCreature ()
@property(nonatomic, retain)    NSMutableArray  *mutableChildren;

@end

@implementation AOCreature

-(void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}


- (void)performGenderSpecificOperation {
    
};

@dynamic children;

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
}

- (id)initWithWeight:(uint)weight
              andAge:(uint)age
{
    self = [super init];
    if (self != nil) {
        self.age = age;
        self.weight = weight;
        self.mutableChildren = [NSMutableArray object];
    }
    return self;
    
}

- (void)addChild:(AOCreature *)child {
    if (nil == child) {
        [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(AOCreature *)child {
    [self.mutableChildren removeObject:child];
}

- (void)sayHello {
    NSLog(@"HELLO");
    NSArray *children = self.children;
    if([children count] > 0) {
        NSLog(@"Children let's say HELLO");
        for (AOCreature *creature in children) {
            [creature sayHello];
        }
    }
}


@end
