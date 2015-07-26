//
//  AOSyllablesAlphabet.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 26.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOAlphabet.h"

@interface AOSyllablesAlphabet : AOAlphabet

+ (instancetype)syllablesAlphabetWithString: (NSString *)string;
+ (instancetype)syllablesAlphabetWithSyllables: (NSArray *)syllables;

- (id)initWithString: (NSString *)string;
- (id)initWithSyllables: (NSArray *)syllables;

@end
