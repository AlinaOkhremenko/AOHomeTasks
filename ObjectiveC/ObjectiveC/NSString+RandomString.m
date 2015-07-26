//
//  NSString+RandomString.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 23.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "NSString+RandomString.h"

@implementation NSString (RandomString)

- (NSString *)randomStringWith: (NSUInteger)length
                   andAlphabet: (AOAlphabet *)alphabet
{
    NSMutableString *string = [NSMutableString stringWithCapacity:length];
    
    for (uint i = 0; i < length; i++) {
        [string appendFormat:@"%@",[alphabet getRandomLetter]];
    }
    
    return [string copy];
}

@end
