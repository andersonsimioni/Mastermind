//
// Created by DEBUG on 3/26/2020.
//
#pragma once

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/// Use this function when there is a problem detected in the code
/// \param functionName is Name of function with error
/// \param message detail of the error
void exceptionCall(std::string functionName, std::string message);