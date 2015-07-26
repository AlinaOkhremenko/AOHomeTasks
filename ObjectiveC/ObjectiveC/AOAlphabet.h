//
//  AOAlphabet.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 23.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AOAlphabet : NSObject

+ (instancetype)alphabetWithString:(NSString*)string;
+ (instancetype)alphabetWithNumbers;
+ (instancetype)alphabetWithLowercaseLetters;
+ (instancetype)alphabetWithUppercaseLetters;

- (id)initWithString: (NSString *)string;
- (NSString*)getRandomLetter;

@end
