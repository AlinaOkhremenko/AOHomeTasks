//
//  AOAlphabetWithStrings.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 28.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAlphabetWithStrings.h"
@interface AOAlphabetWithStrings ()

@property (nonatomic, strong) NSArray *letters;

@end

@implementation AOAlphabetWithStrings 

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

@end
