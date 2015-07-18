//
//  AOCreatureNSObjectCategory.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 19.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOCreatureNSObjectCategory.h"

@implementation NSObject (AOCreatureNSObjectCategory)

+ (id)object {
    return [[[self alloc]init]autorelease];
}

@end
