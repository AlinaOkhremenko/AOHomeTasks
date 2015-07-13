//
//  AOCreature.h
//  ObjectiveC
//
//  Created by Alina Okhremenko on 13.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AOCreatureGender) {
    AOCreatureGenderMale,
    AOCreatureGenderFemale
};

@interface AOCreature : NSObject

@property(nonatomic, assign) AOCreatureGender gender;
@property(nonatomic, retain) NSString *name;
@property(nonatomic) uint weight;
@property(nonatomic) uint age;
@property (nonatomic,copy) NSArray *children;

-(id)childCreateWithWeight:(uint)weight andAge :(uint)age
               andGender :(AOCreatureGender)gender;
//-(void)addChild:(AOCreature *)child;
//-(void)removeChild:(AOCreature *)child;
-(void)sayHello;
-(void)goneMakeWar;

@end
