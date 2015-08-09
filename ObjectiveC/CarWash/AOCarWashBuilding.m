//
//  AOCarWashBuilding.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCarWashBuilding.h"

@implementation AOCarWashBuilding

#pragma mark - Initialization Methods

- (id)initWithRoom:(AORoom *)room
          andPrice:(float)price
{
    self = [super initWithRooms:@[room]];
    if (nil != self) {
        self.price = price;
    }
    
    return self;
}

#pragma mark - Accessors

- (AOBuildingType)type {
    
    return AOBuildingCarWash;
}

@end
