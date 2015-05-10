//
//  main.c
//  AOHomeTask3
//
//  Created by Alina Okhremenko on 09.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <stdio.h>
#include <limits.h>


int main(int argc, const char * argv[]) {
    int Number = -45; unsigned int iterator = 1 << 31;

    while (1){
        if (Number&iterator)
        {
            printf("1");
        }
         else
        {
            printf("0");
        }
        if (iterator == 1)
        
        break;
        
        iterator = iterator >> 1;
    }
    
    
    return 0;
}





 








