//
// Created by DEBUG on 4/13/2020.
//

#include "TestPassword.h"

void testFindPegPos()
{
    ColorPalette p;
    loadPalette(&p);

    Password pass = createRandomPassword(&p, 4);
    int pos = findPegPos(&pass, 0, 'R');

    std::cout<<"Red color pos = "<<pos;
}

void testCreateRandomPassword()
{
    ColorPalette p;
    loadPalette(&p);

    Password pass = createRandomPassword(&p, 4);

    std::cout<<"Color sequence \n{\n";

    for (int i = 0; i < pass.PegsCount; ++i)
        std::cout<<"    Color("<<pass.ColorSequence[i].Name<<", "<<pass.ColorSequence[i].Abbreviation<<", "<<pass.ColorSequence[i].ColorCode<<")\n";

    std::cout<<"}";
}

void testFindBlackHits()
{
    Password pass;
    pass.PegsCount = 4;
    pass.ColorSequence[0] = createColor("Red", 'R', 0);
    pass.ColorSequence[1] = createColor("Green", 'G', 0);
    pass.ColorSequence[2] = createColor("Blue", 'B', 0);
    pass.ColorSequence[3] = createColor("Orange", 'O', 0);

    //---3 black hits---
    std::string play = "RBGO";

    //0 accounted hits
    bool accounted[4] = {};

    std::cout<<"hits = "<<findBlackHits(&pass, play, (bool*)accounted)<<" (the correct value is 2)";
}

void testFindWhiteHits()
{
    Password pass;
    pass.PegsCount = 4;
    pass.ColorSequence[0] = createColor("Red", 'R', 0);
    pass.ColorSequence[1] = createColor("Green", 'G', 0);
    pass.ColorSequence[2] = createColor("Blue", 'B', 0);
    pass.ColorSequence[3] = createColor("Orange", 'O', 0);

    //---3 black hits---
    std::string play = "OYPR";

    //0 accounted hits
    bool accounted[4] = {};

    std::cout<<"hits = "<<findWhiteHits(&pass, play, (bool*)accounted)<<" (the correct value is 2)";
}

void testFindAllHits()
{
    Password pass;
    pass.PegsCount = 4;
    pass.ColorSequence[0] = createColor("Red", 'R', 0);
    pass.ColorSequence[1] = createColor("Green", 'G', 0);
    pass.ColorSequence[2] = createColor("Blue", 'B', 0);
    pass.ColorSequence[3] = createColor("Orange", 'O', 0);

    //---3 black hits---
    std::string play = "RBGO";

    //0 accounted hits
    bool accounted[4] = {};
    int blackHits = 0;
    int whiteHits = 0;
    findAllHits(&pass, play, &blackHits, &whiteHits);

    std::cout<<"blackHits = "<<blackHits<<" (the correct value is 2)\n";
    std::cout<<"whiteHits = "<<whiteHits<<" (the correct value is 2)\n";
}

void testPrintCorrectPassword()
{
    Game game = createNewGame();

    printCorrectPassword(&game.GamePassword);
}