//
//  AOStaff.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOBuilding.h"
#import "AOObservable.h"
#import "Defines.h"

typedef NS_ENUM(NSUInteger, AOStaffState) {
    AOStaffStateFree,
    AOStaffStateBusy
    
};

@interface AOStaff : AOObservable
@property(nonatomic, readonly)  AOStaffState    currentState;
@property(nonatomic, assign)    uint            salary;
@property(nonatomic, copy)      NSString        *experience;
@property(nonatomic, copy)      NSString        *name;

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience;

- (void)performSpecificJob;
- (BOOL)beginJob;
- (void)doJob;
- (void)finishJob;
- (void)mayBeFree;

@end
