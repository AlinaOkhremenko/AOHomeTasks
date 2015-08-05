//
//  AOCarBox.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AORoom.h"
#import "AOCar.h"

@interface AOCarBox : AORoom

@property(nonatomic, assign)    uint    capacityCars;
@property(nonatomic, readonly, getter=isFull)  BOOL    full;
@property(nonatomic, assign)    AOCar   *currentCar;

- (id)initCarBoxWithCapacity;


@end
