//
//  AOCar.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MoneyFlow.h"



typedef NS_ENUM(NSUInteger, AOCarCleaness){
    AOCarIsDirty,
    AOCarIsClean
};

@interface AOCar : NSObject <MoneyFlow>

@property(nonatomic, assign) NSNumber *money;
@property(nonatomic, assign) AOCarCleaness condition;

- (id)initWithMoney: (NSNumber *)money;

@end
