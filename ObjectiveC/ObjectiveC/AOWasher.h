//
//  AOWasher.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOStaff.h"
#import "AOCar.h"
#import "AOCarWashBuilding.h"

@interface AOWasher : AOStaff

- (id)initWithName: (NSString*)name
     andExperience: (NSString*)experience
       andBuilding: (AOBuilding*)office;
- (BOOL)washVehicle:(AOCar*)vehicle;

@end
