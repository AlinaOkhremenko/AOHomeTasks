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

+ (id)creatureWithWeight:(uint)weight
                  andAge:(uint)age
               andGender:(AOCreatureGender)gender
{
    
    AOCreature *creature = [[[AOCreature alloc]initWithWeight:0
                                                       andAge:0
                                                    andGender:AOCreatureGenderMale]autorelease];
    
    return creature;
}

@dynamic children;

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
}

- (id)initWithWeight:(uint)weight
              andAge:(uint)age
           andGender:(AOCreatureGender)gender
{
    
    self = [super init];
    if (self != nil) {
        self.age = age;
        self.weight = weight;
        self.gender = gender;
        self.mutableChildren = [[NSMutableArray alloc] init];
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

- (void)goneMakeWar {
    if (AOCreatureGenderMale == self.gender) {
        NSLog(@"Gone make war");
    } else {
        NSLog(@"I will not make war");
    }
}

@end
