//
// Created by DEBUG on 4/2/2020.
//
#pragma once

#include <windows.h>
#include <iostream>
#include "Color.h"
#include "Exception.h"

///Default terminal colors
const Color TERMINAL_BLACK = createColor("Black", 'b', 8);
const Color TERMINAL_WHITE = createColor("White", 'w', 15);
const Color TERMINAL_RED_ALERT = createColor("Red alert", 'r', 12);
///-----------------------

/// Print a colored message in terminal
/// \param text to print
/// \param background color
/// \param foreground color
void printColored(std::string text, Color color);