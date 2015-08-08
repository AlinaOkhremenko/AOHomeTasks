//
//  AOWasher.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOWasher.h"

@implementation AOWasher

#pragma -
#pragma mark Initializations

- (instancetype)init {
    return self = [super initWithName:nil andExperience:nil andBuilding:nil];
}

- (instancetype)initWithName:(NSString *)name
     andExperience:(NSString *)experience
       andBuilding:(AOBuilding *)office
{
    self = [super initWithName:name andExperience:experience andBuilding:office];
    if (AOBuildingCarWash != office.type) {
        NSAssert(AOBuildingCarWash == office.type, @"initialize with CarWash type");
    }
    
    return self;
}

#pragma -
#pragma Public

- (void)doJob {
    [super doJob];
    self.currentCar.condition = AOCarIsClean;
    
}
- (void)finishJob {
    [super finishJob];
    NSLog(@"I've washed the car");
}

@end
