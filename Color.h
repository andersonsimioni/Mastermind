//
// Created by DEBUG on 3/26/2020.
//
#pragma once

#include <string>
#include "Exception.h"

/// This structure represents a color in the game,
/// it stores the color name, abbreviation and reference
/// code to change the color of the terminal
struct Color
{
    std::string Name;
    char Abbreviation;

    ///Reference code to change terminal color
    int ColorCode;
};

/// Create a new color
/// \param name color name
/// \param abbreviation colo abbreviation
/// \param consoleKeyCommand key used in cosole to change color
/// \return new color struct
Color createColor(std::string name, char abbreviation, int colorCode);