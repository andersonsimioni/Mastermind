//
// Created by DEBUG on 4/13/2020.
//

#include "TestColoredConsole.h"

void testPrintColored()
{
    Color red = createColor("Red", 'R', 12);
    printColored("Hello world!", red);
}