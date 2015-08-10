//
//  AOAdminBuilding.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAdminBuilding.h"

@implementation AOAdminBuilding

#pragma mark -
#pragma mark Initialization Methods

- (id)initWithRoom:(AORoom *)room {
    self = [super initWithRooms:@[room]];
    if (nil != self) {
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (AOBuildingType)type {
    return AOBuildingAdministrative;
}

@end
