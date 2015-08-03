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
#import "MoneyFlow.h"

@interface AOWasher : AOStaff

@property(nonatomic, readonly)  BOOL    busy;

- (id)initWithName:(NSString*)name
     andExperience:(NSString*)experience;


- (void)performSpecificJob;

@end
