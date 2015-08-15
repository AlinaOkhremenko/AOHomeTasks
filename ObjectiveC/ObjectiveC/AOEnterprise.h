//
//  AOEnterprise.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOStaff.h"
#import "AOCar.h"
#import "AOWasher.h"
#import "AOQueue.h"
#import "AOAccountant.h"
#import "AOManager.h"

@interface AOEnterprise : NSObject <CarWashObserver>

@property (nonatomic, readonly) BOOL workDone;

- (BOOL)washTheCar:(AOCar *)car;
- (AOStaff *)freeEmployeeOfClass:(Class)employeeOfType;
- (void)hireEmployee:(AOStaff *)employee;



@end
