//
// Created by DEBUG on 4/13/2020.
//

#include "TestColorPalette.h"

void testLoadPalette() {
    ColorPalette p;
    loadPalette(&p);

    std::cout << "Loaded colors :\n";

    for (int i = 0; i < p.ColorsCount; ++i)
    {
        std::cout<<"\n{\n";
        std::cout << "  name = " << p.Colors[i].Name << "\n";
        std::cout << "  abbreviation = " << p.Colors[i].Abbreviation << "\n";
        std::cout << "  color code = " << p.Colors[i].ColorCode << "\n";
        std::cout<<"}\n";
    }

}

void testGetColorByName()
{
    ColorPalette p;
    loadPalette(&p);

    Color c = getColorByName(&p, "Red");

    std::cout<<"\n{\n";
    std::cout << "  name = " << c.Name << "\n";
    std::cout << "  abbreviation = " << c.Abbreviation << "\n";
    std::cout << "  color code = " << c.ColorCode << "\n";
    std::cout<<"}\n";
}

void testGetColorByAbbreviation()
{
    ColorPalette p;
    loadPalette(&p);

    Color c = getColorByAbbreviation(&p, 'R');

    std::cout<<"\n{\n";
    std::cout << "  name = " << c.Name << "\n";
    std::cout << "  abbreviation = " << c.Abbreviation << "\n";
    std::cout << "  color code = " << c.ColorCode << "\n";
    std::cout<<"}\n";
}

void testGetRandomColor()
{
    ColorPalette p;
    loadPalette(&p);

    Color c = getRandomColor(&p);

    std::cout<<"\n{\n";
    std::cout << "  name = " << c.Name << "\n";
    std::cout << "  abbreviation = " << c.Abbreviation << "\n";
    std::cout << "  color code = " << c.ColorCode << "\n";
    std::cout<<"}\n";
}

void testPrintAllUsefulColors()
{
    ColorPalette p;
    loadPalette(&p);

    printAllUsefulColors(&p);
}

void testPrintUsefulColor()
{
    Color randomColor = createColor("Red", 'R', 12);
    printUsefulColor(randomColor);
}