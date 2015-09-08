//
//  AOWasher.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#import "AOStaff.h"
#import "AOCar.h"
#import "AOMoneyFlowProtocol.h"

@interface AOWasher : AOStaff

@property (nonatomic, readonly, getter=isBusy)  BOOL    busy;


@end
