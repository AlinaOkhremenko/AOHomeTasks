//
//  AOAccountant.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAccountant.h"

@implementation AOAccountant

#pragma mark -
#pragma mark Public Methods

- (void)finishJob {
    [super finishJob];
    NSLog(@"Ready to give money to manager");
}

@end
