//
//  BitwiseOutput.c
//  AOHomeTask3
//
//  Created by Alina Okhremenko on 24.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "BitwiseOutput.h"
#include <stdbool.h>

void AOBitwiseOutput(BitsUnion mask) {
    printf("AOBitwiseOutput of %d is:\n%d%d%d%d%d%d%d%d\n", mask.byte, mask.bits.b7, mask.bits.b6, mask.bits.b5, mask.bits.b4, mask.bits.b3, mask.bits.b2, mask.bits.b1, mask.bits.b0);
}

void AOBytewiseOutput(ByteUnion mask) {
    printf("AOBytewiseOutput of %d is:\n%d %d\n", mask.twoBytes, mask.bytes.a1, mask.bytes.a2);
}

bool AOIsLittleEndian() {
    ByteUnion value;
    value.twoBytes = 256;
    return (value.bytes.a1 == 0) ? 1 : 0;
}



