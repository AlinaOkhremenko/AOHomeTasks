//
//  AOCar.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCar.h"

@implementation AOCar

#pragma mark - Initialization Methods

- (id)initWithMoney:(float)money {
    self = [super init];
    if (nil != self) {
        self.account = money;
    }
    return self;
}

@end
