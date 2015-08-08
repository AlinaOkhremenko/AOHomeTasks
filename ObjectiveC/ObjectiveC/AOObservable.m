//
//  AOSubject.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOObservable.h"
@interface AOObservable ()

@property(nonatomic, retain)    NSHashTable      *mutableObservers;

@end

@implementation AOObservable

#pragma -
#pragma mark Deallocations and Initializations

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if(nil != self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
    }
    return self;
}

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

- (void)setState:(AOState)state {
    if (_state != state) {
        for (id<CarWashObserver> observerObject in self.observers) {
            [observerObject valueOfStateChanged:self];
        }
        _state = state;
    }
}

#pragma -
#pragma mark Public 

- (void)addObserver:(id<CarWashObserver>)observer {
    [self.mutableObservers addObject:observer];
    
}

- (void)removeObserver:(id<CarWashObserver>)observer {
    [self.mutableObservers removeObject:observer];
}

#pragma -
#pragma mark Protocol MoneyFlow 

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
