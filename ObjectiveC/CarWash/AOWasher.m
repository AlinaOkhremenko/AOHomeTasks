//
//  AOWasher.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOWasher.h"

@implementation AOWasher

#pragma mark -
#pragma mark Initialization Methods

- (instancetype)initWithName:(NSString *)name
               andExperience:(NSString *)experience
{
    return self = [super initWithName:name andExperience:experience];
    
}

#pragma mark -
#pragma mark Public Methods

- (void)doJob {
    [super doJob];
    self.currentCar.condition = AOCarIsClean;
    
}
- (void)finishJob {
    [super finishJob];
    NSLog(@"I've washed the car");
}

@end
