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
#import "AODispatcher.h"
#import "AOManager.h"
#import "AOAccountant.h"
#import "AOWasher.h"


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
    
    srand((unsigned)time(NULL));
    
    // after enterprise was created
    AOEnterprise *enterprise = [[AOEnterprise alloc] init];
    
    // after manager was created
    AOManager *manager = [[AOManager alloc] initWithName:@"Konstantin Ivanovich" andExperience:nil];
    
    // after manager was hired
    [enterprise hireManager:manager];

    
    // after 5 accountants were hired
    NSMutableArray *accountants = [[NSMutableArray alloc]init];
    for (int index = 0; index < 5; index++) {
        NSString *name = [NSString stringWithFormat:@"Accountant%d", index];
        AOAccountant *accountant = [[AOAccountant alloc]initWithName:name andExperience:nil];
        [enterprise hireAccountant:accountant];
        [accountants addObject:accountant];
    }
    
    
    // after 5 washers were created and hired
    NSMutableArray *washers = [[NSMutableArray alloc] init];
    for (int index = 0; index < 5; index++) {
    NSString *name = [NSString stringWithFormat:@"Washer%d", index];
    AOWasher *washer = [[AOWasher alloc] initWithName:name andExperience:nil];
        [enterprise hireWasher:washer];
        [washers addObject:washer];
       
    }
    
    //   washer's account should be equal to 0
    for(int i = 0; i < washers.count; i++) {
        AOWasher *washer = [washers objectAtIndex:i];
        XCTAssert(washer.account == 0);
    }
    
    // after 10 cars were created and added to enterprise
    NSMutableArray *cars = [[NSMutableArray alloc] init];
    for (int index = 0; index < 100; index++) {
        NSString *carName = [NSString stringWithFormat:@"Car%d", index];
        AOCar *car = [[AOCar alloc]initWithMoney:kWashPrice];
        car.name = carName;
        [cars addObject:car];
    }
    
    //   cars' account should be equal to kWashPrice
    for (int i = 0; i < cars.count; i++) {
        AOCar *car = [cars objectAtIndex:i];
        XCTAssert(car.account == kWashPrice);
    }
    
    // after enterprise washed the car
    for (int i = 0; i < cars.count; i++) {
        [NSThread sleepForTimeInterval:0.5f];
        
        AOCar *car = cars[i];
        NSLog(@"Start washing car: %@", car.name);
        [enterprise washCar:car];
    }
    
    do {
        [[NSRunLoop mainRunLoop] runUntilDate:[[NSDate date] dateByAddingTimeInterval:1.0]];
    } while (!enterprise.workDone);

    
    //   car's account should be empty  washer's account should be debited with price
    for (int i = 0; i < cars.count; i++) {
        AOCar *car = [cars objectAtIndex:i];
        XCTAssert(car.account == 0);
    }
    
    float totalRevenue = kWashPrice * [cars count];

    // after washer finished his job accountant's account should be equal to kWashPrice
    //XCTAssert(accountant.account == totalRevenue);
    
    // after accountants made their job
    for (int i = 0; i< [accountants count]; i++){
        [[accountants objectAtIndex:i] performSpecificJob];
        
    }
    //  manager's account should be equal to kWashPrice
    XCTAssert(manager.account == totalRevenue);
    
    //  accountat's account should be equal to 0
    for (int i = 0; i< [accountants count]; i++){
        AOAccountant *accountant = [accountants objectAtIndex:i];
        XCTAssert(accountant.account == 0);
    
    }
}

//- (void)testPerformanceExample {
//    // This is an example of a performance test case.
//    [self measureBlock:^{
//        // Put the code you want to measure the time of here.
//    }];
//}

@end
