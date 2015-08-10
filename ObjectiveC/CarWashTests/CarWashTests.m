//
//  CarWashTests.m
//  CarWashTests
//
//  Created by Alina Okhremenko on 09.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "AOEnterprise.h"
#import "AOStaff.h"
#import "Defines.h"


@interface CarWashTests : XCTestCase


@end

@implementation CarWashTests

- (void)setUp {
    
    
    [super setUp];
    
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
     //after washer was created
    AOWasher *washer = [[AOWasher alloc] initWithName:@"Alex" andExperience:nil];
    
    //after accountant was created
    AOAccountant *accountant = [[AOAccountant alloc] initWithName:@"Olga" andExperience:nil];
    
    //after manager was created
    AOManager *manager = [[AOManager alloc] initWithName:@"Konstantin Ivanovich" andExperience:nil];
    
    //after enterprise was created
    AOEnterprise *enterprise = [[AOEnterprise alloc] init];
    
    //hire washer
    [enterprise hireEmployee:washer];
    
    //hire accountant
    [enterprise hireEmployee:accountant];
    
    //hire manager
    [enterprise hireEmployee:manager];
    
    //add enterprise to observers of employees
    [washer addObserver:enterprise];
    [accountant addObserver:enterprise];
    [manager addObserver:enterprise];
    
    //after car was created
    AOCar *car1 = [[AOCar alloc]initWithMoney:kWashPrice];
    
    //car's account should be equal to kWashPrice
    XCTAssert(car1.account == kWashPrice);
    
    //washer's account should be equal to 0
    XCTAssert(washer.account == 0);
    
    //add car to enterprise
    [enterprise washTheCar:car1];
    
    //after car was washed car's account should be empty  washer's account should be debited with price
    XCTAssert(car1.account == 0);
    
    //after washer finished his job accountant's account should be equal to kWashPrice
    XCTAssert(accountant.account == kWashPrice);
    
    //after ccountant made his job
    [accountant performSpecificJob];
    
    //manager's account should be equal to kWashPrice
    XCTAssert(manager.account == kWashPrice);
    
    //accountat's account should be equal to 0
    XCTAssert(accountant.account == 0);
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
