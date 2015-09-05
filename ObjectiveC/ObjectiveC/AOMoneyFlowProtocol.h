//
//  MoneyFlow.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 26.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AOMoneyFlowProtocol <NSObject>

@property (nonatomic, assign) float account;

- (BOOL)getMoneyByPrice:(float)price fromObject:(id<AOMoneyFlowProtocol>)object;
- (BOOL)giveMoneyByPrice:(float)price toObject:(id<AOMoneyFlowProtocol>)object;

- (void)debitAmount:(float)amount;
- (void)creditAmount:(float)amount;


@end
