//
//  AOCarBox.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCarBox.h"

@implementation AOCarBox

#pragma mark -
#pragma mark Initialization Methods

- (id)initCarBoxWithCapacity {
    self = [super init];
    if (nil != self) {
        self.capacityCars = 1;
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFull {
    return (nil != self.currentCar);
}

@end
