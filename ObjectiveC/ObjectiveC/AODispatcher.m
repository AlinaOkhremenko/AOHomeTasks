//
//  AODispatcher.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 31.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AODispatcher.h"
#import "AOStaff.h"
#import "AOWasher.h"
#import "AOQueue.h"
#import "AOObservable.h"

@interface AODispatcher ()
@property (nonatomic, retain)   NSMutableArray  *mutableHandlers;
@property (nonatomic, retain)   AOQueue         *queue;

- (void)enqueue:(id)object;
- (id)dequeue;
- (BOOL)isEmptyQueue;

- (AOStaff *)freeHandler;

@end

@implementation AODispatcher

#pragma mark -
#pragma mark - Initializations and Deallocations

- (void)dealloc {
    self.mutableHandlers = nil;
    self.queue = nil;
    
    [super dealloc];
}
- (instancetype)init {
    self = [super init];
    if (nil != self) {
        self.mutableHandlers = [[NSMutableArray alloc] init];
        self.queue = [[AOQueue alloc] init];
    }
    
    return self;
}

#pragma mark -
#pragma mark - Public Methods Implementation

- (void)addHandler:(id)handler {
    @synchronized(self.mutableHandlers) {
        if (nil != handler) {
            [self.mutableHandlers addObject:handler];
            [handler addObserver:self];
        }
    }
}

- (void)removeHandler:(id)handler {
    @synchronized(self.mutableHandlers){
        [self.mutableHandlers removeObject:handler];
        [handler removeObserver:self];
    }
}

- (void)enqueue:(id)object {
    [self.queue enqueue:object];
}

- (id)dequeue {
    return [self.queue dequeue];
}

- (BOOL)isEmptyQueue {
    return self.queue.length == 0;

}
    
- (AOStaff *)freeHandler{
    @synchronized(self.mutableHandlers) {
        for (AOStaff *handler in self.mutableHandlers) {
            if (handler.state == AOStateFree) {
                return handler;
            }
        }
    }
    
    return nil;
}

- (void)processWithObject:(id)object {
    AOStaff *freeHandler = [self freeHandler];
    if (nil != freeHandler) {
        freeHandler.objectToProcess = object;
        [freeHandler performSpecificJob];
    }else {
        [self enqueue:object];
    }
}

#pragma mark -
#pragma mark Accessor methods

- (BOOL)workDone {
    for (AOStaff *handler in self.mutableHandlers) {
        if (handler.state != AOStateFree) {
            return NO;
        }
    }
    
    return YES;
}

#pragma mark -
#pragma mark - AOCarWashObserverProtocol methods implementation

- (void)objectDidChangeState:(AOStaff *)freeHandler {
    
    if (freeHandler.state == AOStateFinishedJob) {
        [self.delegate object:freeHandler.objectToProcess wasHandledByHandler:freeHandler];
    }
    else if (freeHandler.state == AOStateFree) {
        id object = [self dequeue];
        if (nil != object) {
            freeHandler.objectToProcess = object;
            [freeHandler performSpecificJob];
        }
    }
}

@end
