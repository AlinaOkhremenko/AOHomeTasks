//
//  AOCarBox.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCarBox.h"
@interface AOCarBox()

@property(nonatomic, retain)    NSMutableArray     *mutableCars;

@end
@implementation AOCarBox

- (void)addCar:(AOCar *)car {
    if (nil != car) {
        [self.mutableCars addObject:car] ;
    }
}

- (void)removeCar:(AOCar *)car {
    [self.mutableCars removeObject:car];
}

- (NSArray *)cars {
    return [[self.mutableCars copy] autorelease];
}

- (BOOL)isFull {
    return (nil != self.cars);
}


@end
