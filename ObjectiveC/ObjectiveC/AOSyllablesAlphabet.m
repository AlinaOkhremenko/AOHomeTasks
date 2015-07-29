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


- (id)initWithSyllables:(NSArray *)syllables {
    self = [super init];
    if (nil != self) {
        self.syllables = syllables;
    }
    
    return self;
}

- (NSString*)getRandomLetter {
    return nil;
}

@end
