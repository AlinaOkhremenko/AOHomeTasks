//
//  AOEnterprise.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOEnterprise.h"

@implementation AOEnterprise

- (BOOL)washTheVehicle:(AOCar *)vehicle {
    
    if (AOCarIsDirty == vehicle.condition && self.washer.busy == NO) {
        vehicle.condition = AOCarIsClean;
        
            return YES;
        
        } else {
    
            return NO;
        }
}

- (AOWasher *)washer {
    return [[AOWasher alloc] initWithName:@"name" andExperience:@"experience" andBuilding:]
}




@end
