//
//  AOStaff.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOBuilding.h"

@interface AOStaff : NSObject
@property(nonatomic, assign)    uint            salary;
@property(nonatomic, copy)      NSString*       experience;
@property(nonatomic, copy)      NSString*       name;
@property(nonatomic,assign)     float           cash;
@property(nonatomic, assign)    AOBuildingType  office;

- (id)initWithName: (NSString*)name
     andExperience: (NSString*)experience
       andBuilding: (AOBuildingType)office;

@end
