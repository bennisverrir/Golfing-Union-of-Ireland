#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "legendService.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
private:
    LegendService _service;
};

#endif // CONSOLEUI_H
