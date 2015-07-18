//
//  AOCreature.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 13.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AOCreatureNSObjectCategory.h"
@interface AOCreature : NSObject

typedef NS_ENUM(NSUInteger, AOCreatureGender) {
    AOCreatureMaleGender,
    AOCreatureFemaleGender
};

@property(nonatomic,copy)       NSString            *name;
@property(nonatomic,assign)     uint                weight;
@property(nonatomic,assign)     uint                age;
@property(nonatomic,readonly)   NSArray             *children;


- (void)performGenderSpecificOperation;
- (id)initWithWeight:(uint)weight
              andAge:(uint)age;
- (void)addChild:(AOCreature *)child;
- (void)removeChild:(AOCreature *)child;
- (void)sayHello;


@end
