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

@dynamic children;

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
}

- (id)initWithWeight:(uint)weight
              andAge:(uint)age
           andGender:(AOCreatureGender)gender
            andArray:(NSMutableArray*)array
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

- (id)childCreateWithWeight:(uint)weight
                     andAge:(uint)age
                  andGender:(AOCreatureGender)gender
                   andArray:(NSMutableArray*)array
{
    
    AOCreature *child = [[[AOCreature alloc]initWithWeight:0
                                                    andAge:0
                                                 andGender:AOCreatureGenderMale
                                                  andArray:array]autorelease];
    
    return child;
}


- (void)addChild:(AOCreature *)child {
    if (nil == child) {
        [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(AOCreature *)child
          fromArray:(NSMutableArray *)arrayOfChildren
{
    [self.mutableChildren removeObject:child];
}

- (void)sayHello {
    NSLog(@"HELLO");
    NSArray *children = self.children;
    if([children count]) {
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
