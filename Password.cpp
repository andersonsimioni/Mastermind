//
// Created by DEBUG on 4/2/2020.
//
#include "Password.h"
#include "Random.h"

int findPegPos(Password* password, int fromIndex, char abbreviation)
{
    if(password == nullptr)
        exceptionCall("findPegPos", "password pointer is null!");

    if(fromIndex < 0)
        exceptionCall("findPegPos", "invalid fromIndex!");

    for (int i = fromIndex; i < password->PegsCount; ++i)
        if(password->ColorSequence[i].Abbreviation == abbreviation)
            return i;

    return  -1;
}

Password createRandomPassword(ColorPalette* palette, int pegsCount)
{
    if(palette == nullptr)
        exceptionCall("createRandomPassword", "palette pointer is null!");

    if(palette->ColorsCount < pegsCount)
        exceptionCall("createRandomPassword", "Palette color collection is smaller than pegs number!");

    Password newPassword;
    newPassword.PegsCount = pegsCount;

    updateRandSeed();
    for (int i = 0; i < pegsCount; ++i)
        newPassword.ColorSequence[i] = getRandomColor(palette);

    return newPassword;
}

int findBlackHits(Password* password, std::string play, bool* accountedHits)
{
    int blackHits = 0;

    for (int i = 0; i < password->PegsCount; ++i)
    {
        if(accountedHits[i] == true)
            continue;

        if(play[i] == password->ColorSequence[i].Abbreviation)
        {
            blackHits++;
            accountedHits[i] = true;
        }
    }

    return  blackHits;
}

int findWhiteHits(Password* password, std::string play, bool* accountedHits)
{
    int whiteHits = 0;

    for (int i = 0; i < password->PegsCount; ++i)
    {
        int leftPos = findPegPos(password, 0, play[i]);
        int rightPos = findPegPos(password, i, play[i]);

        if(leftPos != POSITION_NOT_FOUND)
            if(accountedHits[i] == false)
            {
                whiteHits++;
                accountedHits[i] = true;
            }

        if(rightPos != POSITION_NOT_FOUND)
            if(accountedHits[i] == false)
            {
                whiteHits++;
                accountedHits[i] = true;
            }
    }

    return  whiteHits;
}

void findAllHits(Password* password, std::string play, int* blackPoints, int* whitePoints)
{
    if(password == nullptr)
        exceptionCall("findAllHits", "password pointer is nullptr!");

    if(blackPoints == nullptr)
        exceptionCall("findAllHits", "blackPoints pointer is nullptr!");

    if(whitePoints == nullptr)
        exceptionCall("findAllHits", "whitePoints pointer is nullptr!");

    bool accountedHits[MAX_COLORS] = {};

    *blackPoints = findBlackHits(password, play, (bool*)accountedHits);
    *whitePoints = findWhiteHits(password, play, (bool*)accountedHits);
}

void printCorrectPassword(Password* password)
{
    if(password == nullptr)
        exceptionCall("printCorrectPassword", "Password pointer is null!");

    std::cout<<"The correct password is: ";

    for (int i = 0; i < password->PegsCount; ++i)
    {
        std::string abbreviation = "";
        abbreviation += password->ColorSequence[i].Abbreviation;
        printColored(abbreviation, password->ColorSequence[i]);
    }

    std::cout<<"\n";
}