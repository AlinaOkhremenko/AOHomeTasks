//
//  main.c
//  AOHomeTask2
//
//  Created by Alina Okhremenko on 10.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//
#include <stdio.h>

#define AOMacroGenerateType(type, specifier) \
void output_##type(type value) { \
printf( #type "value = " specifier "\n", value);\
}


#define AOMacroOutputType(type, value)\
output_##type(value)

AOMacroGenerateType(int, "%d")

int main(int argc, const char * argv[]) {
    
    AOMacroOutputType(int, 2);
    
    return 0;
}
