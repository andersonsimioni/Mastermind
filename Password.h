//
// Created by DEBUG on 4/2/2020.
//
#pragma once

#include "ColorPalette.h"
#include "Exception.h"

///Maximum Pegs in all games
#define MAX_PEGS 6
#define POSITION_NOT_FOUND -1

/// stores information about the
/// color sequence that the player will have to hit
struct Password
{
    int PegsCount;
    Color ColorSequence[MAX_PEGS];
};

/// find a color by abbreviation
/// and return the position,
/// if color not exist return -1
/// \param password
/// \param fromIndex search after this index in the array
/// \param abbreviation
/// \return color position
int findPegPos(Password* password, int fromIndex, char abbreviation);

/// Create a new password with a random
/// colors sequence, these colors isn't equal
/// \param pegsCount is number of pegs
/// \param palette is where find the colors to use
Password createRandomPassword(ColorPalette* palette, int pegsCount);

/// Search for the black type hits that are
/// when the player has hit position and color
/// \param password to find hits
/// \param play player round
/// \param accountedHits hits counted
/// \return black hits count
int findBlackHits(Password* password, std::string play, bool* accountedHits);

/// Search only for hits of the white type that
/// are if the player hit a color but not the position
/// \param password
/// \param play
/// \param accountedHits
/// \return white hits count
int findWhiteHits(Password* password, std::string play, bool* accountedHits);

/// Checks the number of each type of hit that the player had and deposits
/// the values​in two variables passed by reference
/// \param password to check hits
/// \param play player text played
/// \param blackPoints pointer of black points var
/// \param whitePoints pointer of white points var
void findAllHits(Password* password, std::string play, int* blackPoints, int* whitePoints);

/// Print on screen the correct password
/// \param password to print
void printCorrectPassword(Password* password);