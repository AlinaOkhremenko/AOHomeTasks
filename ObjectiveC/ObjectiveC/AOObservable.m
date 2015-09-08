//
//  AOSubject.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOObservable.h"
@interface AOObservable ()

@property (nonatomic, retain)    NSHashTable      *mutableObservers;

@property (nonatomic, retain)   id<NSLocking>  stateLock;
@property (atomic, retain)   dispatch_queue_t queue;

@end


@implementation AOObservable


@synthesize state = _state;

#pragma mark -
#pragma mark Deallocation and Initialization Methods

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if(nil != self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
        self.queue = dispatch_queue_create("observableQueue", DISPATCH_QUEUE_SERIAL);
        self.stateLock = [NSLock new];
    }
    return self;
}

#pragma mark -
#pragma mark - Accessors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

- (void)setState:(AOState)state {
    [self.stateLock lock];
        _state = state;
    
    [self.stateLock unlock];
    
    for (id<AOCarWashObserver> observerObject in self.observers) {
        [observerObject objectDidChangeState:self];
    }
}

- (AOState)state {
    [self.stateLock lock];
    
     AOState currentState = _state;
    
    [self.stateLock unlock];
    
    return currentState;
}

#pragma mark -
#pragma mark  Public Methods

- (void)addObserver:(id<AOCarWashObserver>)observer {
    @synchronized(self.mutableObservers) {
        [self.mutableObservers addObject:observer];
    }
}

- (void)removeObserver:(id<AOCarWashObserver>)observer {
    @synchronized(self.mutableObservers) {
        [self.mutableObservers removeObject:observer];
    }
}

- (void)performSpecificJob {
    if (self.state == AOStateFree) {
        self.state = AOStateBusy;
        
        dispatch_async(self.queue, ^{
            [self doJob];
               self.state = AOStateFinishedJob;
            if (self.state == AOStateFinishedJob) {
                self.state = AOStateFree;
            }
        });
    }
}

- (void)doJob {
    
}

#pragma mark -
#pragma mark Protocol MoneyFlow Methods

- (BOOL)getMoneyByPrice:(int)price
             fromObject:(id<AOMoneyFlowProtocol>)object
{
    if (price <= object.account) {
        
            [self debitAmount:price];
            [object creditAmount:price];
        return YES;
    }
    
    return NO;
}

- (BOOL)giveMoneyByPrice:(int)price
                toObject:(id<AOMoneyFlowProtocol>)object
{
    if (price <= self.account) {
        
            [self creditAmount:price];
            [object debitAmount:price];
        return YES;
    }
    
    return NO;
}

- (void)debitAmount:(int)amount {
    
    self.account = self.account + amount;
}

- (void)creditAmount:(int)amount {
    
    self.account = self.account - amount;
    
}

@end
