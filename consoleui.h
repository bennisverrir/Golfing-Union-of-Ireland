#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream>
#include <iomanip>
#include "legend.h"
#include "legendService.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
private:
    LegendService _service;

    void displayCommands();
    void commandList();
    void checkForFileError();
    void sort(char command, vector<Legend>& legends);
    void commandAdd();
    string getName(string name);
    bool checkName(string name, bool flag);
    string rightName(string name);
    void getGender(char &gender);
    void getBorn(int &born);
    void validateInput (int &intValue);
    void getDeath(int &death, int born);
    bool checkIfDead();
    void commandDelete();
    void commandFind();
    void subCommandFind(char command, vector <Legend> &toPrint);
    void commandClear();
    void fortyTwo();
};

#endif // CONSOLEUI_H
