//
//  AOStaff.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOStaff.h"

@implementation AOStaff

- (id)initWithName: (NSString*)name
     andExperience: (NSString*)experience
       andBuilding: (AOBuilding*)office
{
    self = [super init];
    if (nil != self) {
        self.name = name;
        self.experience = experience;
        self.office = office;
        
    }
    return self;
}

@end
