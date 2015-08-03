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
    
    if (self.washer.isBusy == NO) {
        self.washer.isBusy = YES;
        
        [self.washer performSpecificJob];
        [self.washer getMoneyByPrice:kWashPrice fromObject:car];
        [self.washer giveMoneyByPrice:kWashPrice toObject:self.accountant];
        
        self.washer.isBusy = NO;
        
            return YES;
        
        } else {
    
        return NO;
    }
}









@end
