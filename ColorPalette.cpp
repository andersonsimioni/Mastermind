//
// Created by DEBUG on 3/26/2020.
//
#include "ColorPalette.h"


void loadPalette(ColorPalette* palette)
{
    if(palette == nullptr)
        exceptionCall("loadPalette", "Palette is nullptr!");

    Color newColorCollection[] =
     {
        //---All game colors---//
        createColor("Blue", 'B', 1),
        createColor("Red", 'R', 4),
        createColor("Green", 'G', 2),
        createColor("Orange", 'O', 6),
        createColor("Yellow", 'Y', 14),
        createColor("Purple", 'P', 13),
     };

    int len = (sizeof(newColorCollection)/sizeof(Color));

    if(len > MAX_COLORS)
        exceptionCall("loadPalette", "number of colors loaded greater than the maximum number of colors");

    palette->ColorsCount = len;

    for (int i = 0; i < len; ++i)
        palette->Colors[i] = newColorCollection[i];
}

Color getColorByName(ColorPalette* palette, std::string name)
{
    if(palette == nullptr)
        exceptionCall("getColorByName", "palette is nullptr!");

    if(name.empty())
        exceptionCall("getColorByName", "name is empty!");

    for (int i = 0; i < palette->ColorsCount; ++i)
        if(palette->Colors[i].Name == name)
            return  palette->Colors[i];

    exceptionCall("getColorByName", "Color not found");
}

Color getColorByAbbreviation(ColorPalette* palette, char abbreviation)
{
    if(palette == nullptr)
        exceptionCall("getColorByAbbreviation", "palette is nullptr!");

    for (int i = 0; i < palette->ColorsCount; ++i)
        if(palette->Colors[i].Abbreviation == abbreviation)
            return  palette->Colors[i];

    exceptionCall("getColorByAbbreviation", "Color not found");
}

Color getRandomColor(ColorPalette* palette)
{
    if(palette == nullptr)
        exceptionCall("getRandomColor", "Palette is nullptr!");

    Color color = palette->Colors[getRandomInt32(0, palette->ColorsCount - 1)];

    return color;
}

void printUsefulColor(Color color)
{
    std::string text = "[";
    text += color.Abbreviation;
    text += " = ";
    text += color.Name;
    text += "]";

    printColored(text, color);
}

void printAllUsefulColors(ColorPalette* palette)
{
    if(palette == nullptr)
        exceptionCall("printAllUsefulColors", "Palette is nullptr!");

    std::cout<<"You can use this colors: \n";

    bool jumpLine = false;
    for (int i = 0; i < palette->ColorsCount; ++i)
    {
        printUsefulColor(palette->Colors[i]);
        std::cout<<"    ";

        if(jumpLine)
            std::cout<<"\n";

        jumpLine = !jumpLine;
    }
}