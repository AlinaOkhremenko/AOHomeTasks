//
//  AOCreature.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 13.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCreature.h"

@implementation AOCreature

-(id)initWithWeight:(uint)weight andAge :(uint)age andGender: (AOCreatureGender)gender {
    self = [super init];
    if (self != nil) {
        self.age = age;
        self.weight = weight;
        self.gender = gender;
    }
    return self;
}

-(id)childCreateWithWeight:(uint)weight andAge :(uint)age
               andGender :(AOCreatureGender)gender {
    
    AOCreature *child = [[AOCreature alloc]initWithWeight:0 andAge:0 andGender:AOCreatureGenderMale];
    
    return child;
}

-(void)addChild:(AOCreature *)child {
    NSMutableArray *arrayOfChildren = [[NSMutableArray alloc]init];
    [arrayOfChildren addObject:_children];
    
}

-(void)removeChild:(AOCreature *)child fromArray: (NSMutableArray *)arrayOfChildren {
    [arrayOfChildren removeObject:_children];
}

-(void)sayHello {
    NSLog(@"HELLO");
}

-(void)goneMakeWar {
    NSLog(@"Gone make war");
}

@end
