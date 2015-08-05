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

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience
       andBuilding:(AOBuilding *)office
{
    self = [super init];
    if (nil != self) {
        self.name = name;
        self.experience = experience;
        self.office = office;
        
    }
    return self;
}

- (void)performSpecificJob {
    if (self.currentState == AOStaffStateFree) {
        self.currentState = AOStaffStateBusy;
        [self beginJob];
        [self doJob];
        [self finishJob];
        self.currentState = AOStaffStateFree;
    }
}

- (void)beginJob {
    self.state = AOStateBeginWork;
}
- (void)doJob {
    self.state = AOStateMakeWork;
}
- (void)finishJob {
    self.state = AOStateFinishWork;
}

- (void)mayBeFree {
    if (self.currentState == AOStaffStateBusy) {
        self.currentState = AOStateFree;
    }
}

@end
