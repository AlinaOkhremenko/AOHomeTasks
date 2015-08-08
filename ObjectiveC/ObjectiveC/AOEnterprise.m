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

#pragma -
#pragma mark Deallocations and Initializations

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

#pragma -
#pragma mark Public

- (BOOL)washTheCar:(AOCar *)car {
    if (car.condition == AOCarIsDirty){
        AOStaff *washer = [self getFreeEmployeeOfType:[AOWasher class]];
        if (nil != washer) {
        [washer performSpecificJob];
        
        return YES;
    }
    }
    return NO;
}

- (AOStaff *)getFreeEmployeeOfType:(Class)employeeOfType {
    for(AOStaff *employee in self.employees) {
        if ([employee isKindOfClass:employeeOfType] && (employee.state == AOStaffStateFree)){
                return employee;
        }
    }
    
    return nil;
}


#pragma -
#pragma mark Protocol CarWashObserver

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
    else if ([observableObject isKindOfClass:[AOManager class]]) {
        if (observableObject.state == AOStateFinishWork) {
            
        }
    }
    
}

#pragma -
#pragma mark Private

- (void)hireEmployees:(AOStaff *)employee {
    [self.employees addObject:employee];
}

@end
