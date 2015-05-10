//
//  main.c
//  MethodValueOutput_MamaPapa
//
//  Created by Alina Okhremenko on 10.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <stdio.h>

int MethodValueOutput (int value) {
    
    int result;
    
    if (value % 15 == 0){
        printf ("mamapapa\n");
        result = 2;
    }
    else if (value % 3 == 0){
        printf ("mama\n");
        result = 0;
    }
    else if (value % 5 == 0){
        printf ("papa\n");
        result = 1;
    }
    else {
        result = 3;
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    
    MethodValueOutput(30);
    
    printf("%d\n", MethodValueOutput(1));
    
    for (int i = 0; i<=1000; i++){
        MethodValueOutput(i);
    }
    
    return 0;
}
