//
//  AORoom.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AORoom.h"

@implementation AORoom

- (id)initRoomWithMaxCountPeople:(uint)maxCountPeople

{
    self = [super init];
    if (nil != self) {
        self.maxCountPeople = maxCountPeople;
    }
    return self;
}


@end
