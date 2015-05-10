//
//  AOValueSizeofType.c
//  AOHomeTask1
//
//  Created by Alina Okhremenko on 10.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOValueSizeofType.h"

#define AOValuePrint(type)\
printf("size of " #type " = '%lu'\n", sizeof(type))

void ValueSizeofType(void)
{
    AOValuePrint(char);
    AOValuePrint(int);
    AOValuePrint(long int);
    AOValuePrint(short int);
    AOValuePrint(double);
    AOValuePrint(long double);
    AOValuePrint(unsigned char);
    AOValuePrint(float);
    AOValuePrint(signed long int);
}

