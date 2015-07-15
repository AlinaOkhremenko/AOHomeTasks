//
//  AOCreatureTests.m
//  AOCreatureTests
//
//  Created by Alina Okhremenko on 15.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "AOCreature.h"

@interface AOCreatureTests : XCTestCase

@end

@implementation AOCreatureTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testAOCreature {
    AOCreature *olya = [[AOCreature alloc]initWithWeight:48
                                                  andAge:27
                                               andGender:(AOCreatureGenderFemale)
                                                andArray:];
    AOCreature *nikita = [AOCreature alloc]initWithWeight:48
                                                   andAge:27
                                                andGender:(AOCreatureGenderMale)
                                                 andArray:];
    
    NSString *name = @"Olya";
    olya.name = name;
    NSString *name = @"Nikita";
    nikita.name = name;
    
    [olya sayHello];
    [nikita sayHello];
    [olya goneMakeWar];
    [nikita goneMakeWar];
    
    NSMutableArray *array = @[@"Polina", @"Vova"];
    
    AOCreature *childFirst = [[AOCreature alloc]initWithWeight:4
                                                        andAge:0
                                                     andGender:(AOCreatureGenderMale)
                                                      andArray:]];
    [olya addChild:childFirst];
    NSString *name = @"Vova";
    childFirst.name = name;
    
    AOCreature *childSecond = [[AOCreature alloc]initWithWeight:5
                                                         andAge:0
                                                      andGender:(AOCreatureGenderFemale)
                                                       andArray:]];
    
    [olya addChild:childSecond];
    NSString *name = @"Polina";
    childSecond.name = name;
    
    NSArray *children = [olya children];
    NSLog(@"Olya's children %@", children);
    
    
    
    NSMutableArray *array = @[@"Polina", @"Vova"];
    

    
    [olya removeChild:childFirst fromArray:children];
    
    

}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
