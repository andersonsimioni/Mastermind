//
// Created by DEBUG on 3/26/2020.
//
#pragma once

#include "Color.h"
#include "Random.h"
#include "Exception.h"
#include "ColoredConsole.h"

///Maximum colors number in the game
#define MAX_COLORS 8

/// This structure can store up to 255 colors
/// to be used in the game or in the terminal
struct ColorPalette
{
    int ColorsCount;
    Color Colors[MAX_COLORS];
};

/// Load defined defaults game colors to
/// apply in game and cosole
/// \param palette
void loadPalette(ColorPalette* palette);

/// Get color by name in palette colors
/// \param palette to find color
/// \param name name of color
/// \return color
Color getColorByName(ColorPalette* palette, std::string name);

/// Get color by abbreviation in palette colors
/// \param palette to find color
/// \param abbreviation of color
/// \return color
Color getColorByAbbreviation(ColorPalette* palette, char abbreviation);

/// Take a random color from the chosen palette
/// \return random color in palette
Color getRandomColor(ColorPalette* palette);

/// Draws a color usable in the game
/// \param color to print
void printUsefulColor(Color color);

/// Print in terminal all colored colors abbreviations
/// \param palette palette reference
void printAllUsefulColors(ColorPalette* palette);