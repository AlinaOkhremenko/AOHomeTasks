//
//  AOSubject.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MoneyFlow.h"

@interface AOSubject : NSObject <MoneyFlow>

@property(nonatomic, assign)    float   account;

@end
