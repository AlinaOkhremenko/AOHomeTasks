//
//  AOWasher.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOWasher.h"



@implementation AOWasher

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience
       andBuilding:(AOBuilding *)office
{
    self = [super initWithName:name andExperience:experience andBuilding:office];
    if (AOBuildingCarWash != office.type) {
        NSAssert(AOBuildingCarWash == office.type, @"initialize with CarWash type");
    }
    
    return self;
}

- (void)performSpecificJob {
    [self beginJob];
    [self doJob];
    [self finishJob];
    
}

- (void)doJob {
     self.currentCar.condition = AOCarIsClean;
}

- (void)finishJob {

}


@end
