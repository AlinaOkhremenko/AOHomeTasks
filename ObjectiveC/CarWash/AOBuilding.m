//
//  AOBuilding.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOBuilding.h"
@interface AOBuilding()

@property(nonatomic, strong) NSMutableArray *mutableRooms;

@end

@implementation AOBuilding

- (id)initWithRooms:(NSArray *)rooms {
    self =  [super init];
    if (nil != self) {
        self.mutableRooms = [NSMutableArray new];
    }
    
    return self;
}

- (void)addRoom:(AORoom *)room {
    if (nil == room) {
    [self.mutableRooms addObject:room];
    }
}

- (void)removeRoom:(AORoom *)room {
    
    [self.mutableRooms removeObject:room];
}

- (AOBuildingType)type {
    return AOBuildingUnknown;
}

@end
