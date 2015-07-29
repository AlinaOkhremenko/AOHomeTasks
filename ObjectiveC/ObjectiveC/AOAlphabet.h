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
+ (instancetype)alphabetWithSyllables: (NSArray *)syllables;
+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

+ (instancetype)alphabetWithNumbers;
+ (instancetype)alphabetWithLowercaseLetters;
+ (instancetype)alphabetWithUppercaseLetters;


@end
