//
//  AOSubject.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOSubject.h"

@implementation AOSubject

- (BOOL)getMoneyByPrice:(float)price
             fromObject:(id<MoneyFlow>)object
{
    if (price <= object.account) {
        [self debitAmount:price];
        [object creditAmount:price];
        
        return YES;
    }
    
    return NO;
}

- (BOOL)giveMoneyByPrice:(float)price
                toObject:(id<MoneyFlow>)object
{
    if (price <= object.account) {
        [self creditAmount:price];
        [object debitAmount:price];
        
        return YES;
    }
        return NO;
}

- (void)debitAmount:(float)amount {
    self.account = self.account + amount;
}

- (void)creditAmount:(float)amount {
    self.account = self.account - amount;
}


@end
