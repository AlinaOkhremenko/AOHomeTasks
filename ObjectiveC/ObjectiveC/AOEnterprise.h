//
//  AOEnterprise.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 03.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOWasher.h"
#import "AOStaff.h"
#import "AOManager.h"
#import "AOAccountant.h"

@interface AOEnterprise : NSObject

@property(nonatomic, readonly)  AOWasher        *washer;
@property(nonatomic, readonly)  AOAccountant    *accountant;
@property(nonatomic, readonly)  AOManager       *manager;


- (BOOL)washTheVehicle:(AOCar *)vehicle;
- (AOAccountant *)accountant;
- (AOManager *)manager;
- (AOWasher *)washer;



@end
