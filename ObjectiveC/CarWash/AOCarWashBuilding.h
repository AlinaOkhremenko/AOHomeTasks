//
//  AOCarWashBuilding.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOBuilding.h"

@interface AOCarWashBuilding : AOBuilding

@property(nonatomic, assign)    float   price;

- (id)initWithRoom: (AORoom *)room andPrice: (float)price;
- (AOBuildingType)type;

@end
