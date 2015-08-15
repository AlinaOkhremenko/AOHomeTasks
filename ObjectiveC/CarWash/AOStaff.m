//
//  AOStaff.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOStaff.h"
@interface AOStaff ()
@property(nonatomic, assign)    AOStaffState   currentState;

@end

@implementation AOStaff

#pragma mark -
#pragma mark Deallocation and Initialization Methods

- (void)dealloc {
    self.name = nil;
    self.experience = nil;
    
    [super dealloc];
}

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience
{
    self = [super init];
    if (nil != self) {
        self.name = name;
        self.experience = experience;
    }
    return self;
}

#pragma mark -
#pragma mark - Public Methods

- (void)performSpecificJob {
    if (self.currentState == AOStaffStateFree) {
        [self beginJob];
        [self doJob];
        [self finishJob];
    }
}

- (BOOL)beginJob {
    if (self.currentState == AOStaffStateFree) {
        self.state = AOStateBeginWork;
        self.currentState = AOStaffStateBusy;
        return YES;
    }
    return NO;
}

- (void)doJob {
    self.state = AOStateMakeWork;
}

- (void)finishJob {
    //  self.state = AOStateFinishWork;
    [self performSelectorOnMainThread:@selector(setStateToFinishWork)
                           withObject:nil
                        waitUntilDone:YES];
    self.currentState = AOStaffStateFree;
}

- (void)setStateToFinishWork {
    self.state = AOStateFinishWork;
}

- (void)mayBeFree {
    if (self.currentState == AOStaffStateBusy) {
        self.currentState = AOStaffStateFree;
    }
}

@end
