//
//  AOStaff.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOStaff.h"

@implementation AOStaff

#pragma mark -
#pragma mark Deallocation and Initialization Methods

- (void)dealloc {
    self.name = nil;
    self.experience = nil;
    
    [super dealloc];
}

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience
{
    self = [super init];
    if (nil != self) {
        self.name = name;
        self.experience = experience;
    }
    return self;
}

@end
