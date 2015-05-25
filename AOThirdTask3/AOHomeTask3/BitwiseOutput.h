//
//  BitwiseOutput.h
//  AOHomeTask3
//
//  Created by Alina Okhremenko on 24.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#ifndef __AOHomeTask3__BitwiseOutput__
#define __AOHomeTask3__BitwiseOutput__

#include <stdio.h>
#include <stdbool.h>

typedef union {

    struct {
        unsigned int b0:1;
        unsigned int b1:1;
        unsigned int b2:1;
        unsigned int b3:1;
        unsigned int b4:1;
        unsigned int b5:1;
        unsigned int b6:1;
        unsigned int b7:1;
    } bits;
    unsigned char byte;
    
} BitsUnion;

typedef union {
    
    struct {
        char a1;
        char a2;
    } bytes;
    unsigned short twoBytes;
    
} ByteUnion;

void AOBitwiseOutput(BitsUnion mask);
void AOBytewiseOutput(ByteUnion mask);
bool AOIsLittleEndian();



#endif /* defined(__AOHomeTask3__BitwiseOutput__) */
