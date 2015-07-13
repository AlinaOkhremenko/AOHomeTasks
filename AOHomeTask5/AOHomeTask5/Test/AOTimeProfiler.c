//
//  AOTimeProfiler.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 02.07.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include "AOTimeProfiler.h"
#include <sys/time.h>

void AOTimeProfilingForFunction(void (*testFunction)(void), const char *functionName) {
    
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    
    testFunction();
    
    gettimeofday(&end, NULL);
    
    unsigned long long miliseconds = 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000;
    printf("%s execution took %llu ms\n", functionName, miliseconds);
}
