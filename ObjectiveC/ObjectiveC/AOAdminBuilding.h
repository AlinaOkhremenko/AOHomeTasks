//
//  AOAdminBuilding.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOBuilding.h"

@interface AOAdminBuilding : AOBuilding

- (id)initWithRoom:(AORoom*)room;
- (AOBuildingType)type;

@end
