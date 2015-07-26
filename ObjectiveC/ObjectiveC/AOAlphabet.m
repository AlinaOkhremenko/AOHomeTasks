//
//  AOAlphabet.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 23.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAlphabet.h"

@interface AOAlphabet ()

@property (nonatomic, strong) NSArray *letters;

@end

@implementation AOAlphabet

+ (instancetype)alphabetWithString:(NSString*)string {
    return [[AOAlphabet alloc]initWithString:string];
}

+ (instancetype)alphabetWithNumbers {
    return [[AOAlphabet alloc]initWithString:@"0123456789"];
}

+ (instancetype)alphabetWithLowercaseLetters {
    return [[AOAlphabet alloc]initWithString:@"abcdefghigklmnopqrstuvwxyz"];
}

+ (instancetype)alphabetWithUppercaseLetters {
    return [[AOAlphabet alloc]initWithString:@"ABCDEFGHIGKLMNOPQRSTUVWXYZ"];
}

- (id)initWithString:(NSString*)string {
    if (self = [super init]) {
        NSMutableArray *temporaryArray = [[NSMutableArray alloc] init];
        for (int i=0; i<string.length; i++) {
            NSRange range = NSMakeRange(i, 1);
            NSString *letter = [string substringWithRange:range];
            [temporaryArray addObject:letter];
        }
        self.letters = [temporaryArray copy];
    }
    
    return self;
}

- (NSString*)getRandomLetter {
    int index = rand() % self.letters.count;
    return [self.letters objectAtIndex:index];
}

@end
