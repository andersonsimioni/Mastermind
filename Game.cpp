//
// Created by DEBUG on 3/26/2020.
//
#include "Game.h"

void runGame()
{
    Game newGame = createNewGame();
    printAllUsefulColors(&newGame.GameColors);
    playGameRounds(&newGame);
}

Game createNewGame()
{
    Game newGame;
    newGame.Round = 1;
    loadPalette(&newGame.GameColors);
    newGame.GamePassword = createRandomPassword(&newGame.GameColors, 4);

    return newGame;
}

void endGame(Game* game, bool win)
{
    if(win)
        std::cout<<"Congratulations!! You won the match!!\n";
    else
    {
        std::cout<<"Too bad, unfortunately his attempts are over ...\n";
        printCorrectPassword(&game->GamePassword);
    }

    abort();
}

bool isValidPlay(Game* game, std::string play)
{
    if(game == nullptr)
        exceptionCall("isValidPlay", "game struct ref is null!");

    if(play.length() != game->GamePassword.PegsCount)
        return false;

    for (int i = 0; i < play.length(); ++i)
        for (int j = 0; j < game->GameColors.ColorsCount; ++j)
            if(game->GameColors.Colors[j].Abbreviation == play[i])
                return true;

    return false;
}

std::string readPlay(Game* game)
{
    if(game == nullptr)
        exceptionCall("readPlay", "game is null!");

    std::string play;
    std::cout<<"Please insert your play:";
    getline(std::cin, play);

    while(isValidPlay(game, play) == false)
    {
        printColored("Please, insert a valid play:", TERMINAL_RED_ALERT);
        getline(std::cin, play);
    }

    return play;
}

void playGameRounds(Game* game)
{
    if(game == nullptr)
        exceptionCall("playGameRounds", "game is null!");

    while(game->Round <= MAX_ROUND)
    {
        int whiteCount = 0;
        int blackCount = 0;

        std::string play = readPlay(game);

        findAllHits(&game->GamePassword, play, &blackCount, &whiteCount);

        printHits(game->Round, blackCount, whiteCount);

        if(blackCount == play.length())
            endGame(game, true);

        game->Round++;
    }

    endGame(game, false);
}

void printHits(int round, int blackHits, int whiteHits)
{
    std::cout<<"[Round "<<round<<" Hits] -> ";

    if(!blackHits && !whiteHits)
    {
        printColored("nothing\n", TERMINAL_RED_ALERT);
        return;
    }

    std::cout<<"|";

    for (int i = 0; i < blackHits; ++i)
        printColored("*", TERMINAL_BLACK);

    for (int i = 0; i < whiteHits; ++i)
        printColored("*", TERMINAL_WHITE);

    std::cout<<"|\n";
}