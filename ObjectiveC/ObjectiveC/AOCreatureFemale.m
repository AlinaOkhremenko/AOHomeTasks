//
//  AOCreatureFemale.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 18.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCreatureFemale.h"
#import "AOCreatureMale.h"

@implementation AOCreatureFemale


- (void)performGenderSpecificOperation {
    [super performGenderSpecificOperation];
    AOCreatureGender gender = arc4random() % 2;
    AOCreature *child;
    if (gender == AOCreatureMaleGender) {
        child = [[[AOCreatureMale alloc]initWithWeight:3200
                                               andAge:0]autorelease];
    } else {
        child = [[[AOCreatureFemale alloc]initWithWeight:3200
                                                 andAge:0]autorelease];
                                                      
    }
    [self addChild:child];
                             
}

@end
