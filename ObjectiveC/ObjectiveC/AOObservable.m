//
//  AOSubject.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOObservable.h"
@interface AOObservable ()

@property(nonatomic, retain)    NSMutableArray      *mutableObservers;

@end

@implementation AOObservable

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if(nil != self) {
        self.mutableObservers = [[[NSMutableArray alloc] init] autorelease];
    }
    return self;
}

- (NSArray*)observers {
    return [[[self.mutableObservers copy] allObjects] autorelease];
}

- (void)setState:(AOState)state {
    if (_state != state) {
        for (id<CarWashObserver> observerObject in self.observers) {
            [observerObject valueOfStateChanged:self];
        }
        _state = state;
    }
}

- (void)addObserver:(id<CarWashObserver>)observer {
    if (![self.mutableObservers containsObject:observer]) {
    [self.mutableObservers addObject:observer];
    }
}

- (void)removeObserver:(id<CarWashObserver>)observer {
    [self.mutableObservers removeObject:observer];
}


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
