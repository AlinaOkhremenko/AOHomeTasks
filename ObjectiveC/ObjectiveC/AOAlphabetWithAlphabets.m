//
//  AOAlphabetWithAlphabets.m
//  ObjectiveC
//
//  Created by Alina Okhremenko on 28.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import "AOAlphabetWithAlphabets.h"

@interface AOAlphabet (PrivateAlphabet)

@property (nonatomic, strong)   NSArray     *letters;

@end

@interface AOAlphabetWithAlphabets ()

@property(nonatomic, strong)    NSArray    *letters;

@end

@implementation AOAlphabetWithAlphabets 

- (id)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    if (nil != self) {
        NSMutableSet *set = [[NSMutableSet alloc]init];
        for (AOAlphabet *alphabet in alphabets) {
            NSArray *array = alphabet.letters;
            
            [set addObjectsFromArray:array];
        }
        self.letters = [set allObjects];
    }
    
    return self;
}

@end
