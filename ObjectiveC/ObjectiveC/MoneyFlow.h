//
//  MoneyFlow.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 26.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MoneyFlow <NSObject>

@optional
- (void)creditMoneyByPrice: (NSNumber *)price;  //get (-)
- (void)debitMoneyByPrice : (NSNumber *)price; //recieve (+)
- (void)countMoney;

@end
