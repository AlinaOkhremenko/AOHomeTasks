//
//  main.c
//  AOHomeTask5
//
//  Created by Alina Okhremenko on 17.05.15.
//  Copyright (c) 2015 Alina Okhremenko. All rights reserved.
//

#include <stdio.h>
#include "AOHumanStructure.h"

int main(int argc, const char * argv[]) {
    AOHumanStruct* Nikita;
    Nikita = AOHumanStructCreateMan("Nikita", 24, AOHumanGenderMale);
    AOHumanStruct* Olya;
    Olya = AOHumanStructCreateMan("Olya", 24, AOHumanGenderFemale);
    AOHumanStructMarriage(Nikita, Olya);
    
    
    printf("Nikita's partner is: %s", Nikita->_partner->_humanName);
    
    
    return 0;
}