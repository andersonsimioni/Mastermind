//
// Created by DEBUG on 3/26/2020.
//
#include "Exception.h"
#include "ColoredConsole.h"

void exceptionCall(std::string functionName, std::string message)
{
    if(functionName == "")
        exceptionCall("exceptionCall", "FunctionName is empty!");

    if(message == "")
        exceptionCall("exceptionCall", "message is empty!");

    std::string exception = functionName;
    exception.append(" -> ");
    exception.append(message);

    printColored(exception, TERMINAL_RED_ALERT);
    abort();
}