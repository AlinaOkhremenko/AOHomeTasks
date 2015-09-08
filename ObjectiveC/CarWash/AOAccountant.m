//
//  AOAccountant.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAccountant.h"
#import "AOEnterprise.h"

@implementation AOAccountant

#pragma mark -
#pragma mark Public Methods

- (void)doJob {
    
    float randomNumber = ((float)rand() / RAND_MAX);
    float delay = 1.0 + randomNumber;
    [NSThread sleepForTimeInterval:delay];

    [self getMoneyByPrice:kWashPrice fromObject:self.objectToProcess];

}

@end
