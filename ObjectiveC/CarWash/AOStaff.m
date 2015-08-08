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

- (void)dealloc {
    self.name = nil;
    self.experience = nil;
    
    [super dealloc];
}

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
        [self beginJob];
        [self doJob];
        [self finishJob];
    
}

- (void)beginJob {
    if(self.currentState == AOStaffStateFree) {
    self.state = AOStateBeginWork;
    self.currentState = AOStaffStateBusy;
    }
}
- (void)doJob {
    self.state = AOStateMakeWork;
}
- (void)finishJob {
    self.state = AOStateFinishWork;
    self.currentState = AOStaffStateFree;
}

- (void)mayBeFree {
    if (self.currentState == AOStaffStateBusy) {
        self.currentState = AOStaffStateFree;
    }
}

@end
