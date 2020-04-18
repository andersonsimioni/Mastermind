//
// Created by DEBUG on 4/2/2020.
//
#include "ColoredConsole.h"

void printColored(std::string text, Color color)
{
    if(color.ColorCode < 0 || color.ColorCode > 254)
        exceptionCall("printColored","invalid color code!");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.ColorCode);

    std::cout<<text.c_str();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TERMINAL_WHITE.ColorCode);
}