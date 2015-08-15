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

- (void)dealloc {
    self.currentCar = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name
               andExperience:(NSString *)experience
{
    return self = [super initWithName:name andExperience:experience];
    
}

#pragma mark -
#pragma mark Public Methods

- (void)performSpecificJobWithCar:(AOCar*)car {
    self.currentCar = car;
    [super performSpecificJob];
}

- (void)doJob {
    [super doJob];

    float z = ((float)rand() / RAND_MAX);
    float randomNumber = 2.f + z * 3.f;
    [NSThread sleepForTimeInterval:randomNumber];
    
    self.currentCar.condition = AOCarIsClean;
}
- (void)finishJob {
    [super finishJob];
    NSLog(@"I've washed the car");
    
    self.currentCar = nil;
}

@end
