//
//  AOManager.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOManager.h"

@implementation AOManager

#pragma mark -
#pragma mark Public Methods

- (void)finishJob {
    [super finishJob];
    NSLog(@"Finally this working day is over");
}

@end
