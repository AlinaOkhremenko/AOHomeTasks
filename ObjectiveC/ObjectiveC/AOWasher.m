//
//  AOWasher.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOWasher.h"


@implementation AOWasher

- (BOOL)washVehicle:(AOCar*)vehicle {
    if (0 != vehicle.money && AOCarIsDirty == vehicle.condition) {
        vehicle.condition = AOCarIsClean;
        
        return YES;
  
    }
    else
    {
        return NO;
    }
}

- (void)getCashFromVeicle:(AOCar*)vehicle {
    
    
}

@end
