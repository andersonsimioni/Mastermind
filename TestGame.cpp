//
// Created by DEBUG on 4/13/2020.
//

#include "TestGame.h"

void testRunGame()
{
    std::string response;
    std::cout<<"This test will play all game's rounds in a new game struct, type 'y' to continue\n";
    getline(std::cin, response);

    if(response == "y")
        runGame();
}

void testCreateNewGame()
{
    Game g = createNewGame();

    std::cout<<"New game created\n";

    std::cout<<"Round = "<<g.Round<<"\n";

    std::cout<<g.GameColors.ColorsCount<<" Colors\n{\n";
    for (int i = 0; i < g.GameColors.ColorsCount; ++i)
    {
        Color color = g.GameColors.Colors[i];
        std::cout << "    (" << color.Name << ", " << color.Abbreviation << ", "<< color.ColorCode << ")\n";
    }
    std::cout<<"}\n";

    std::cout<<g.GamePassword.PegsCount<<" Colors sequence password\n{\n";
    for (int i = 0; i < g.GamePassword.PegsCount; ++i)
    {
        Color color = g.GamePassword.ColorSequence[i];
        std::cout << "    (" << color.Name << ", " << color.Abbreviation << ", "<< color.ColorCode << ")\n";
    }
    std::cout<<"}";
};

void testEndGame()
{
    Game game = createNewGame();

    std::string response;
    std::cout<<"Type 'w' to test win or anything to lose\n";

    getline(std::cin, response);

    if(response == "w")
        endGame(&game, true);
    else
        endGame(&game, false);
}

void testPlayGameRounds()
{
    std::string response;
    std::cout<<"This test will play all game's rounds in a new game struct, type 'y' to continue\n";
    getline(std::cin, response);

    if(response == "y")
    {
        Game g = createNewGame();
        playGameRounds(&g);
    }
}

bool testIsValidPlay()
{
    Game game = createNewGame();

    std::cout<<"This test validate player's play\n";


    std::cout<<"Insert a simulated move to check the validity:";

    std::string response;
    std::getline(std::cin, response);
    std::cout<<isValidPlay(&game, response) ? ("Is valid.") : ("is not valid!");
}

void testReadPlay()
{
    Game game = createNewGame();

    readPlay(&game);
}

void testPrintHits()
{
    std::cout<<"The test should inform round 5 with 2 white and 2 black hits\n";
    printHits(5, 2, 2);
}