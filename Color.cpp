//
// Created by DEBUG on 3/26/2020.
//
#include "Color.h"

Color createColor(std::string name, char abbreviation, int colorCode)
{
    if(name.empty())
        exceptionCall("createColor", "name is empty!");

    if(colorCode < 0 || colorCode > 254)
        exceptionCall("createColor", "invalid color code");

    Color newColor;
    newColor.Name = name;
    newColor.Abbreviation = abbreviation;
    newColor.ColorCode = colorCode;

    return  newColor;
}