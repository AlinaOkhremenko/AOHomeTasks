//
//  AOSyllablesAlphabet.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 26.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOSyllablesAlphabet.h"

@interface AOSyllablesAlphabet ()

@property (nonatomic, strong) NSArray *syllables;

@end

@implementation AOSyllablesAlphabet

+ (instancetype)syllablesAlphabetWithString: (NSString *)string {
     return [[AOSyllablesAlphabet alloc]initWithString:string];
}

+ (instancetype)syllablesAlphabetWithSyllables: (NSArray *)syllables {
    return [[AOSyllablesAlphabet alloc]initWithSyllables:syllables];
}

- (id)initWithString: (NSString *)string {
    self = [super init];
    if (nil != self) {
        NSArray *arrayOfSyllables = [string componentsSeparatedByString:@" "];
        self.syllables = arrayOfSyllables;
    }
    
    return self;
}

- (id)initWithSyllables: (NSArray *)syllables {
    self = [super init];
    if (nil != self) {
        self.syllables = syllables;
    }
    
    return self;
}

@end
