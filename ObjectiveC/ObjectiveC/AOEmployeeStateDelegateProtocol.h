//
//  AOEmployeeStateDelegateProtocol.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 01.09.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOStaff.h"

@protocol AOEmployeeStateDelegateProtocol <NSObject>

- (void)object:(id)object wasHandledByHandler:(AOStaff *)handler;

@end
