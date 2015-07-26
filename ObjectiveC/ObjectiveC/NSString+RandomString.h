//
//  NSString+RandomString.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 23.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOAlphabet.h"

@interface NSString (RandomString)

- (NSString *)randomStringWith: (NSUInteger)length
                   andAlphabet: (AOAlphabet *)alphabet;

@end
