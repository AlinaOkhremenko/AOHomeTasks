//
//  AOCarWashBuilding.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCarWashBuilding.h"



@implementation AOCarWashBuilding

- (id)initWithRoom:(AORoom*)room {
    self = [super initWithRooms:@[room]];
    if (self) {
        
    }
    
    return self;
}

- (AOBuildingType)type {
    return AOBuildingCarWash;
}

@end
