//
//  AOCar.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOObservable.h"

typedef NS_ENUM(NSUInteger, AOCarCleaness){
    AOCarIsDirty,
    AOCarIsClean
};

@interface AOCar : AOObservable

@property (nonatomic, assign)    AOCarCleaness  condition;
@property (nonatomic, copy)      NSString       *name;

- (id)initWithMoney:(float)money;

@end
