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
            [washer performSpecificJobWithCar:car];
            
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
        
        if (washer.currentCar == nil) {
            NSLog(@"Error");
        }
        
        [washer getMoneyByPrice:kWashPrice fromObject:washer.currentCar];
        NSLog(@"Washer %@ takes money %d from Car %@",washer.name, kWashPrice,washer.currentCar.name);
        NSLog(@"Washer's account = %f", washer.account);
        AOAccountant *freeAccountant = (AOAccountant*)[self freeEmployeeOfClass:[AOAccountant class]];
        if (nil != freeAccountant) {
            NSLog(@"Washer %@ gives money %d to Accountant %@",washer.name,kWashPrice,freeAccountant.name);
            [washer giveMoneyByPrice:kWashPrice toObject:freeAccountant];
            NSLog(@"Accountants account = %f", freeAccountant.account);
        }
        
        [self performSelector:@selector(checkCarsQueueWithWasher:) withObject:washer afterDelay:0.01];
    }
}

- (void)checkCarsQueueWithWasher:(AOWasher*)washer {
    if (self.carsQueue.length > 0) {
        AOCar *nextCar = [self.carsQueue dequeue];
        [washer  performSpecificJobWithCar:nextCar];
    }
}

- (void)handleAccountantChangedValue:(AOAccountant*)accountant {
    if (accountant.state == AOStateFinishWork) {
        AOManager *freeManager = (AOManager *)[self freeEmployeeOfClass:[AOManager class]];
        [accountant giveMoneyByPrice:accountant.account toObject:freeManager];
        NSLog(@"Accountant %@ gives money %f to manager %@", accountant.name, accountant.account, freeManager.name);
        NSLog(@"Manager's account = %f", freeManager.account);
    }
    
}

- (void)handleManagerChangedValue:(AOManager*)manager {
    if (manager.state == AOStateFinishWork) {
    }
}

@end
