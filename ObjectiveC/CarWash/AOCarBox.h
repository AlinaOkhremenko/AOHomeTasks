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

@property(nonatomic, assign)    NSArray    *cars;
@property(nonatomic, readonly)    BOOL    isFull;

- (void)addCar:(AOCar *)car;
- (void)removeCar:(AOCar *)car;
- (NSArray *)cars;

@end
