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

@interface AOWasher : AOStaff

- (void)initWithCarWashBuilding;
- (BOOL)washVehicle:(AOCar*)vehicle;
- (void)getCashFromVehicle:(AOCar*)vehicle;

@end
