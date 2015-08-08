//
//  AOEnterprise.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOWasher.h"
#import "AOStaff.h"
#import "AOManager.h"
#import "AOAccountant.h"
#import "AOCarBox.h"
#import "AOCar.h"

@interface AOEnterprise : NSObject <CarWashObserver>

- (BOOL)washTheCar:(AOCar *)car;

@end
