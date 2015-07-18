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
#import "AOCreatureFemale.h"
#import "AOCreatureMale.h"

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
    //creating of firstMale
    AOCreatureMale *firstMale = [[[AOCreatureMale alloc]initWithWeight:65 andAge:25]autorelease];
    
    //      'firstMale' should belong to the AOCreature class
    NSAssert([firstMale isKindOfClass:[AOCreature class]], @"wrong class%@", NSStringFromClass([firstMale class]));
    
    //      'firstMale''s reference count must be equal to 1
    NSAssert(1 == [firstMale retainCount], @"wrong count");
    
    //          set value for property 'firstMale'
    firstMale.name = @"Oleg";
    
    // after 'secondMale' was created
    AOCreatureMale *secondMale = [[[AOCreatureMale alloc]initWithWeight:78 andAge:26]autorelease];
    
    //      'secondMale' should belong to AOCreature class
    NSAssert([secondMale isKindOfClass:[AOCreature class]], @"wrong class%@", NSStringFromClass([secondMale class]));
    
    //      'secondMale''s reference count must be equal to 1
    NSAssert(1 == [secondMale retainCount], @"wrong count");
    
    //          set value for property 'secondMale'
    secondMale.name = @"Alex";
    
    // after 'female' was created
    AOCreatureFemale *female = [[[AOCreatureFemale alloc]initWithWeight:55 andAge:27]autorelease];
    
    //      'female' should belong to AOCreature class
    NSAssert([female isKindOfClass:[AOCreature class]], @"wrong class%@", NSStringFromClass([female class]));
    
    //      'female''s reference count must be equal to 1
    NSAssert(1 == [female retainCount], @"wrong count");
    
    //          set value for property 'female'
    female.name = @"Polina";
    
    // 'firstMale' and 'secondMale' must not be equal
    NSAssert(firstMale != secondMale, @"");
    
    // after 'thirdMale' was created
    AOCreatureMale *thirdMale = [[[AOCreatureMale alloc]initWithWeight:58 andAge:22]autorelease];
    
    //      'thirdMale' should belong to AOCreature class
    NSAssert([thirdMale isKindOfClass:[AOCreature class]], @"wrong class%@", NSStringFromClass([thirdMale class]));
    
    //      'thirdMale''s reference count must be equal to 1
    NSAssert(1 == [thirdMale retainCount], @"wrong count");
    
    // after array from all objects was created
    NSArray *creatures = @[firstMale ,female , secondMale, thirdMale];
    for (AOCreature *creature in creatures) {
        [creature sayHello];
        if ([creature isKindOfClass:[AOCreatureMale class]]) {
            AOCreatureMale *male = (AOCreatureMale *)creature;
            
            NSLog(@"%@ gender = male", male);
        }
        
        if ([creature isKindOfClass:[AOCreatureFemale class]]) {
            AOCreatureFemale *female = (AOCreatureFemale *)creature;
            
            NSLog(@"%@ gender = female", female);
        }
        [creature performGenderSpecificOperation];
        NSLog(@"\n");
    }

    
//    AOCreature *olya = [[AOCreature alloc]initWithWeight:48
//                                                  andAge:27];
//    AOCreature *nikita = [[AOCreature alloc]initWithWeight:48
//                                                   andAge:27];
//    
//    NSString *name = @"Olya";
//    olya.name = name;
//    NSString *newName = @"Nikita";
//    nikita.name = newName;
//    
//    [olya sayHello];
//    [nikita sayHello];
//    
//    AOCreature *childFirst = [[AOCreature alloc]initWithWeight:4
//                                                        andAge:0];
//    [olya addChild:childFirst];
//    NSString *childNameFirst = @"Vova";
//    childFirst.name = childNameFirst;
//    
//    AOCreature *childSecond = [[AOCreature alloc]initWithWeight:5
//                                                         andAge:0];
//    
//    [olya addChild:childSecond];
//    NSString *childNameSecond = @"Polina";
//    childSecond.name = childNameSecond;
//    
//    NSArray *children = [olya children];
//    NSLog(@"Olya's children %@", children);
//    
//    
//    
//    //NSMutableArray *array = @[@"Polina", @"Vova"];
//    
//
//    
//    [olya removeChild:childFirst];
//
    
    

}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
