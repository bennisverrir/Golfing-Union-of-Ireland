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
    void sort(char command, vector<Legend>& legends);
};

#endif // CONSOLEUI_H
