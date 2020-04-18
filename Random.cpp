//
// Created by DEBUG on 4/11/2020.
//

#include "Random.h"

void updateRandSeed()
{
    srand(time(0));
}

int getRandomInt32(int min, int max)
{
    int range = (max - min) + 1;
    int randomNumber = (rand() % range);
    randomNumber += min;

    return  randomNumber;
}