//
// Created by DEBUG on 3/26/2020.
//
#pragma once

#include <cstdlib>
#include "Password.h"
#include "ColoredConsole.h"

///Maximum rounds to try color sequence
#define MAX_ROUND 12

/// Stores game information such as secret
/// color sequence, colors to be used
/// and current game round
struct Game
{
    int Round;
    Password GamePassword;
    ColorPalette GameColors;
};

///Create and start a new game and play
void runGame();

/// Create a new game struct with
/// rounds equal 1 and new random
/// color sequence
/// \return new game struct
Game createNewGame();

/// Verify if player win and show
/// winner or defeat game text
/// \param game ref struct
/// \param win player win?
void endGame(Game* game, bool win);

/// Play all the attempts the player
/// has or until he guesses the color sequence
/// \param game struct to play
void playGameRounds(Game* game);

/// Check is player play string with colors
/// abbreviation is valid
/// \param game struct
/// \param play string with colors abbreviation
/// \return if valid return tru, ele false
bool isValidPlay(Game* game, std::string play);

/// Read from the terminal to the player's move
/// and if it is invalid ask for another move
/// \param game struct to play
/// \return valid player play
std::string readPlay(Game* game);

/// Shows the player's hits in the terminal,
/// each hit of color and position is represented
/// by a black asterisk and each hit of just color
/// by a white asterisk
/// \param round current round to show in play hits
/// \param blackHits number of times the player hit color and position
/// \param whiteHits number of times the player hit the color only
void printHits(int round, int blackHits, int whiteHits);