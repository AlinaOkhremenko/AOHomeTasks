//
//  AOCar.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCar.h"

@implementation AOCar

- (id)initWithMoney:(float)money {
    self = [super init];
    if (nil != self) {
        self.money = money;
    }
    return self;
}

@end
