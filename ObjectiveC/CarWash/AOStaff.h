//
//  AOStaff.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOObservable.h"
#import "Defines.h"

@interface AOStaff : AOObservable

@property(nonatomic, assign)    uint            salary;
@property(nonatomic, copy)      NSString        *experience;
@property(nonatomic, copy)      NSString        *name;

- (id)initWithName:(NSString *)name
     andExperience:(NSString *)experience;


@end
