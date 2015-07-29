//
//  AOAlphabetWithRange.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 28.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAlphabetWithRange.h"

@interface AOAlphabetWithRange ()

@property(nonatomic, strong)    NSArray    *letters;

@end

@implementation AOAlphabetWithRange

- (id)initWithRange:(NSRange)range {
    self = [super init];
    if (nil != self) {
        NSMutableArray *mutableArray = [[NSMutableArray alloc]init];
        for (unichar index = range.location; index < NSMaxRange(range); index ++) {
        NSString *letter = [NSString stringWithFormat:@"%C", index];
        [mutableArray addObject:letter];
    }
    
        self.letters = [mutableArray copy];
    }

    return self;
}

@end
