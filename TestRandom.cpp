//
// Created by DEBUG on 4/13/2020.
//

#include "TestRandom.h"

void testUpdateSeed()
{
    int seed = time(0);

    srand(seed);

    std::cout<<"Rand Seed updated to "<<seed<<"\nIt's no crash :)";
}

void testGetRandomInt32()
{
    updateRandSeed();

    std::cout<<"10 random numbers between -100 and 100 will be generated\n";

    for (int i = 0; i < 10; ++i) {
        std::cout<<getRandomInt32(-100, 100)<<" ";
    }
}