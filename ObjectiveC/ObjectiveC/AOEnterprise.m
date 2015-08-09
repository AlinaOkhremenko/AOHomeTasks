//
//  AOEnterprise.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOEnterprise.h"
#import "Defines.h"


@interface AOEnterprise ()

@property(nonatomic, retain)    NSMutableArray      *employees;

- (void)hireEmployees:(AOStaff *)employee;

@end

@implementation AOEnterprise

#pragma mark - Deallocation and Initialization Methods

- (void)dealloc {
    self.employees = nil;
  
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (nil != self) {
        self.employees = [[[NSMutableArray alloc] init] autorelease];
    }
    return self;
}

#pragma mark -  Public Methods

- (BOOL)washTheCar:(AOCar *)car {
    if (car.condition == AOCarIsDirty){
        AOWasher *washer = (AOWasher *)[self getFreeEmployeeOfType:[AOWasher class]];
        if (nil != washer) {
            washer.currentCar = car;
            [washer performSpecificJob];
            
            return YES;
        }
    }
    return NO;
}

- (AOStaff *)getFreeEmployeeOfType:(Class)employeeOfType {
    for(AOStaff *employee in self.employees) {
        if ([employee isKindOfClass:employeeOfType] &&
            (employee.currentState == AOStaffStateFree))
        {
            return employee;
        }
    }
    
    return nil;
}

- (void)hireEmployees:(AOStaff *)employee {
    [self.employees addObject:employee];
}

#pragma mark - Protocol CarWashObserver Methods

- (void)valueOfStateChanged:(AOObservable *)observableObject {
    
    if ([observableObject isKindOfClass:[AOWasher class]]) {
        if (observableObject.state == AOStateFinishWork) {
            AOWasher *washer = (AOWasher *)observableObject;
            [washer getMoneyByPrice:kWashPrice fromObject:washer.currentCar];
            [washer giveMoneyByPrice:kWashPrice toObject:[self getFreeEmployeeOfType:[AOAccountant class]]];
        }
    }
    else if ([observableObject isKindOfClass:[AOAccountant class]]) {
        if (observableObject.state == AOStateFinishWork) {
            AOAccountant *accountant = (AOAccountant*)observableObject;
            [accountant giveMoneyByPrice:kWashPrice toObject:[self getFreeEmployeeOfType:[AOManager class]]];
        }
    }
    
}

@end
