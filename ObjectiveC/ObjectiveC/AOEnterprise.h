//
//  AOEnterprise.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOEmployeeStateDelegateProtocol.h"
@class AOStaff;
@class AOCar;
@class AOWasher;
@class AOQueue;
@class AOAccountant;
@class AOManager;

@interface AOEnterprise : NSObject <AOEmployeeStateDelegateProtocol>

@property (nonatomic, readonly)     BOOL    workDone;

- (void)washCar:(AOCar *)car;
- (void)hireAccountant:(AOAccountant*)accountant;
- (void)hireWasher:(AOWasher *)washer;
- (void)hireManager:(AOManager *)manager;

@end
