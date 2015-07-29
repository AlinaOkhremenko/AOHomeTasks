//
//  AOAlphabet.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 23.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAlphabet.h"
#import "AOAlphabetWithStrings.h"
#import "AOSyllablesAlphabet.h"
#import "AOAlphabetWithRange.h"
#import "AOAlphabetWithAlphabets.h"

@interface AOAlphabet ()

@property (nonatomic, strong) NSArray *letters;

@end

@implementation AOAlphabet

+ (instancetype)alphabetWithString:(NSString*)string {
    return [[AOAlphabetWithStrings alloc]initWithString:string];
}

+ (instancetype)alphabetWithSyllables: (NSArray *)syllables {
    return [[AOSyllablesAlphabet alloc]initWithSyllables:syllables];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[AOAlphabetWithRange alloc]initWithRange:range];
}

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return [[AOAlphabetWithAlphabets alloc]initWithAlphabets:alphabets];
}

+ (instancetype)alphabetWithNumbers {
    return [[AOAlphabetWithStrings alloc]initWithString:@"0123456789"];
}

+ (instancetype)alphabetWithLowercaseLetters {
    return [[AOAlphabetWithStrings alloc]initWithString:@"abcdefghigklmnopqrstuvwxyz"];
}

+ (instancetype)alphabetWithUppercaseLetters {
    return [[AOAlphabetWithStrings alloc]initWithString:@"ABCDEFGHIGKLMNOPQRSTUVWXYZ"];
}

- (NSString*)getRandomLetter {
    int index = rand() % self.letters.count;
    return [self.letters objectAtIndex:index];
}

@end
