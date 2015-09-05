//
//  AODispatcher.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 31.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOCarWashObserver.h"
#import "AOEmployeeStateDelegateProtocol.h"



@interface AODispatcher : NSObject <AOCarWashObserver>
@property (nonatomic, assign)       id<AOEmployeeStateDelegateProtocol>     delegate;
@property (nonatomic, readonly) BOOL workDone;

- (void)addHandler:(id)object;
- (void)removeHandler:(id)object;

- (void)processWithObject:(id)object;

@end
