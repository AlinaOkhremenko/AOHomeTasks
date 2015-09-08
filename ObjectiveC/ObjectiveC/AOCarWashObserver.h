//
//  CarWashObserver.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 05.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

@class AOObservable;

@protocol AOCarWashObserver <NSObject>

- (void)objectDidChangeState:(AOObservable *)observableObject;

@end
