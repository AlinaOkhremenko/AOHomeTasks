//
//  AOQueue.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 14.08.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

@interface AOQueue : NSObject

- (id)dequeue;
- (void)enqueue:(id)object;
- (NSUInteger)length;

@end
