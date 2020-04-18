//
// Created by DEBUG on 4/13/2020.
//

#include "TestColor.h"

void testCreateColor()
{
    Color c = createColor("testColor", 'T', 10);

    std::cout<<"new color \n{\n";
    std::cout<<"    name = "<<c.Name<<",\n";
    std::cout<<"    abbreviation = "<<c.Abbreviation<<",\n";
    std::cout<<"    colorCode = "<<c.ColorCode<<"\n}";
}