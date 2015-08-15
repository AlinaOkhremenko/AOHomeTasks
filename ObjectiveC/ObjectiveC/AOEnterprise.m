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
@property(nonatomic, retain)    AOQueue             *carsQueue;

- (void)hireEmployee:(AOStaff *)employee;

@end

@implementation AOEnterprise

#pragma mark -
#pragma mark Deallocation and Initialization Methods

- (void)dealloc {
    self.employees = nil;
    self.carsQueue = nil;
  
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (nil != self) {
        self.employees = [[[NSMutableArray alloc] init] autorelease];
        self.carsQueue = [[[AOQueue alloc] init] autorelease];
    }
    return self;
}

#pragma mark -
#pragma mark Public Methods


- (BOOL)washTheCar:(AOCar *)car {
    if (car.condition == AOCarIsDirty){
        AOWasher *washer = (AOWasher *)[self freeEmployeeOfClass:[AOWasher class]];
        if (nil != washer) {
            [washer performSelectorInBackground:@selector(performSpecificJobWithCar:)
                                     withObject:car];
            //[washer performSpecificJobWithCar:car];
            
            return YES;
        } else {
            [self.carsQueue enqueue:car];
        }
    }
    return NO;
}

- (AOStaff *)freeEmployeeOfClass:(Class)employeeOfType {
    for (AOStaff *employee in self.employees) {
        if ([employee isKindOfClass:employeeOfType] &&
            (employee.currentState == AOStaffStateFree))
        {
            return employee;
        }
    }
    
    return nil;
}

- (void)hireEmployee:(AOStaff *)employee {
    [self.employees addObject:employee];
}

- (BOOL)workDone {
    BOOL foundBusyStaff = NO;
    for (AOStaff *employee in self.employees) {
        if ((employee.currentState == AOStaffStateBusy))
        {
            foundBusyStaff = YES;
            break;
        }
    }
    
    return self.carsQueue.length == 0 && !foundBusyStaff;
}

#pragma mark -
#pragma mark Protocol CarWashObserver Methods

- (void)objectDidChangeState:(AOObservable *)observableObject {
    if ([observableObject isKindOfClass:[AOWasher class]]) {
        AOWasher *washer = (AOWasher*)observableObject;
        [self handleWasherChangedValue:washer];
    }
    else if ([observableObject isKindOfClass:[AOAccountant class]]) {
        AOAccountant *accountant = (AOAccountant*)observableObject;
        [self handleAccountantChangedValue:accountant];
    }
    else if ([observableObject isKindOfClass:[AOManager class]]) {
        AOManager *manager = (AOManager *)observableObject;
        [self handleManagerChangedValue:manager];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)handleWasherChangedValue:(AOWasher*)washer {
    if (washer.state == AOStateFinishWork) {
        [washer getMoneyByPrice:kWashPrice fromObject:washer.currentCar];
        AOAccountant *freeAccountant = (AOAccountant*)[self freeEmployeeOfClass:[AOAccountant class]];
        if (nil != freeAccountant) {
            [washer giveMoneyByPrice:kWashPrice toObject:freeAccountant];
        }
        if ([self.carsQueue length] != 0) {
            [washer performSpecificJobWithCar:(AOCar *)[self.carsQueue dequeue]];
        }
        
    }
}

- (void)handleAccountantChangedValue:(AOAccountant*)accountant {
    if (accountant.state == AOStateFinishWork) {
        AOManager *freeManager = (AOManager *)[self freeEmployeeOfClass:[AOManager class]];
        [accountant giveMoneyByPrice:kWashPrice toObject:freeManager];
    }
    
}

- (void)handleManagerChangedValue:(AOManager*)manager {
    if (manager.state == AOStateFinishWork) {
    }
}

@end
