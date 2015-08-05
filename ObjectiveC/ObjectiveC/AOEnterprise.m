//
//  AOEnterprise.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOEnterprise.h"
#import "Defines.h"

@implementation AOEnterprise

- (void)dealloc {
    self.manager = nil;
    self.accountant = nil;
    self.washer = nil;
  
    [super dealloc];
}


- (BOOL)addCar:(AOCar *)car
      toCarBox:(AOCarBox *)carBox
{
    if (car.condition == AOCarIsDirty && carBox.isFull == NO) {
        carBox.currentCar = car;
        
        return YES;
    }
    
    return NO;
}


- (BOOL)washTheCar:(AOCar *)car {
    
    if (self.washer.busy == NO) {
        self.washer.busy = YES;
        
        [self.washer performSpecificJob];
        [self.washer getMoneyByPrice:kWashPrice fromObject:car];
        [self.washer giveMoneyByPrice:kWashPrice toObject:self.accountant];
        
        self.washer.busy = NO;
        
            return YES;
        
        } else {
    
        return NO;
    }
}

- (void)getMoneyFromAccountant: (AOAccountant *)accountant toManager: (AOManager *)manager {
    [self.manager getMoneyByPrice:kWashPrice fromObject: self.accountant];
}

- (void)valueOfStateChanged:(AOObservable *)observableObject {
    NSLog(@"Observable object %@ with state %lu",observableObject,observableObject.state);
}


@end
