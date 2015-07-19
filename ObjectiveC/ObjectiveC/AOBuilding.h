//
//  AOBuilding.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AORoom.h"

typedef NS_ENUM(NSUInteger, AOBuildingType) {
    AOBuildingUnknown,
    AOBuildingCarWash,
    AOBuildingAdministrative
};

@interface AOBuilding : NSObject

@property(nonatomic, assign)    AOBuildingType      type;
@property(nonatomic, readonly)  NSArray*            rooms;
@property(nonatomic, copy)      NSString*           adress;

- (id)initWithRooms: (NSArray*)rooms;
- (void)addRoom:(AORoom*)room;
- (void)removeRoom:(AORoom*)room;
- (AOBuildingType)type;

@end
