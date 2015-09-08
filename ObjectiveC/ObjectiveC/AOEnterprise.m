//
//  AOEnterprise.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOEnterprise.h"
#import "AOQueue.h"
#import "AOWasher.h"
#import "AODispatcher.h"
#import "AOAccountant.h"
#import "AOManager.h"
@interface AOEnterprise ()

@property (nonatomic, retain)    NSMutableArray      *employees;
@property (nonatomic, assign)    AODispatcher        *washersDispatcher;
@property (nonatomic, assign)    AODispatcher        *accountantsDispatcher;
@property (nonatomic, assign)    AODispatcher        *managersDispatcher;

@end

@implementation AOEnterprise

#pragma mark -
#pragma mark Deallocation and Initialization Methods

- (void)dealloc {
    self.employees = nil;
    self.washersDispatcher = nil;
    self.accountantsDispatcher = nil;
    self.managersDispatcher = nil;
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (nil != self) {
        self.employees = [[NSMutableArray alloc] init];
        self.accountantsDispatcher = [[AODispatcher alloc] init];
        self.washersDispatcher = [[AODispatcher alloc] init];
        self.managersDispatcher = [[AODispatcher alloc] init];
        self.washersDispatcher.delegate = self;
        self.accountantsDispatcher.delegate = self;
        self.managersDispatcher.delegate = self;
    }
    
    return self;
}


#pragma mark -
#pragma mark Public Methods

- (void)washCar:(AOCar *)car {
    if (car.condition == AOCarIsDirty) {
        [self.washersDispatcher processWithObject:car];
    }
}

- (void)hireAccountant:(AOAccountant*)accountant {
    [self.accountantsDispatcher addHandler:accountant];
}

- (void)hireWasher: (AOWasher *)washer {
    [self.washersDispatcher addHandler:washer];
}

- (void)hireManager: (AOManager *)manager {
    [self.managersDispatcher addHandler:manager];
}

#pragma mark -
#pragma mark Accessors Methods

- (BOOL)workDone {
    return (self.washersDispatcher.workDone) && (self.accountantsDispatcher.workDone) && (self.managersDispatcher.workDone);
}

#pragma mark -
#pragma mark Protocol AOEmployeeDelegate Methods

- (void)object:(id)object wasHandledByHandler:(AOStaff *)handler {
    
    if ([object isKindOfClass:[AOCar class]] && [handler isKindOfClass:[AOWasher class]]) {
        
        AOWasher *washer = (AOWasher*)handler;
        AOCar *car = (AOCar*)object;
        NSLog(@"Washer %@ has taken money %f from Car %@",handler.name, kWashPrice,car.name);
        NSLog(@"Washer's account = %f", washer.account);
        
        [self.accountantsDispatcher processWithObject:handler];
    }
    
    else if ([object isKindOfClass:[AOWasher class]] && [handler isKindOfClass:[AOAccountant class]]) {
        
        AOAccountant *accountant =(AOAccountant*)handler;
        NSLog(@"Accountant %@ has taken money %f from Washer",accountant.name, kWashPrice);
        
        [self.managersDispatcher processWithObject:handler];
    }
    
    else if ([object isKindOfClass:[AOAccountant class]] && [handler isKindOfClass:[AOManager class]]) {
        
        AOAccountant *accountant = (AOAccountant*)object;
        AOManager *manager = (AOManager*)handler;
        NSLog(@"Manager has taken money from %@ account = %f",accountant.name, manager.account);
    }
}

@end
