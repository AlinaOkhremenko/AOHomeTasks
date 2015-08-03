//
//  AORoom.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AORoom : NSObject

@property(nonatomic, assign)    uint    maxCountPeople;
@property(nonatomic, assign)    uint    capacityCars;


- (id)initRoomWithMaxCountPeople:(uint)maxCountPeople
                 andCapacityCars:(uint)capacityCars;

@end
