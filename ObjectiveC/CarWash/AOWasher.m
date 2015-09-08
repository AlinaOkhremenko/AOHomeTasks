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
#pragma mark Public Methods

- (void)doJob {
    float randomNumber = ((float)rand() / RAND_MAX);
    float delay = 2.0f + randomNumber * 3.f;
    [NSThread sleepForTimeInterval:delay];
    
    AOCar *car = self.objectToProcess;
    car.condition = AOCarIsClean;
    [self getMoneyByPrice:kWashPrice fromObject:car];
   
}

@end
