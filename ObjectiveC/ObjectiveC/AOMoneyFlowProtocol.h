//
//  MoneyFlow.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 26.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

@protocol AOMoneyFlowProtocol <NSObject>

@property (nonatomic, assign) int account;

- (BOOL)getMoneyByPrice:(int)price fromObject:(id<AOMoneyFlowProtocol>)object;
- (BOOL)giveMoneyByPrice:(int)price toObject:(id<AOMoneyFlowProtocol>)object;

- (void)debitAmount:(int)amount;
- (void)creditAmount:(int)amount;


@end
