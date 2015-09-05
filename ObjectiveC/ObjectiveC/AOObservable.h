//
//  AOSubject.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOMoneyFlowProtocol.h"
#import "AOCarWashObserver.h"

typedef NS_ENUM(NSUInteger, AOState){
    AOStateFree = 0,
    AOStateBusy,
    AOStateFinishedJob,
};

@interface AOObservable : NSObject <AOMoneyFlowProtocol>
@property (nonatomic, assign)    float       account;

@property (nonatomic, readonly)  NSArray     *observers;
@property (nonatomic, assign)    AOState     state;

@property (nonatomic, assign)    id          objectToProcess;

- (void)addObserver:(id<AOCarWashObserver>)observer;
- (void)removeObserver:(id<AOCarWashObserver>)observer;

- (void)performSpecificJob;
- (void)doJob;

@end
