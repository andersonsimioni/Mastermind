//
// Created by DEBUG on 4/11/2020.
//
#pragma once

#include <stdlib.h>
#include <string.h>
#include <time.h>

///Set rand seed to current time
void updateRandSeed();

/// Take a totally random number between min and max
/// \param min number
/// \param max number
/// \return random number between min and max
int getRandomInt32(int min, int max);