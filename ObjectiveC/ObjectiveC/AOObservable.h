//
//  AOSubject.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MoneyFlow.h"
#import "CarWashObserver.h"

typedef NS_ENUM(NSUInteger, AOState){
    AOStateBeginWork,
    AOStateMakeWork,
    AOStateFinishWork,
};

@interface AOObservable : NSObject <MoneyFlow>
@property(nonatomic, assign)    float       account;

@property(nonatomic, readonly)  NSArray     *observers;
@property(nonatomic, assign)    AOState     state;

-(void)addObserver:(id<CarWashObserver>)observer;
-(void)removeObserver:(id<CarWashObserver>)observer;

@end
