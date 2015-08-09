//
//  CarWashObserver.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 05.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AOObservable;

@protocol CarWashObserver <NSObject>

- (void)valueOfStateChanged:(AOObservable *)observableObject;

@end
