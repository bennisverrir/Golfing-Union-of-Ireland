#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "legendService.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
    friend ostream& operator << (ostream& out,const vector<Legend>& rhs);
private:
    LegendService _service;
    void sort(char command, vector<Legend>& legends);
    void CommandList();
    void CommandFind();
    void CommandDelete();
    void displayCommands();
    bool checkName(string name, bool flag);
    string getName(string name);
    void getGender(char &gender);
    void getBorn(int &born);
    bool checkIfDead();
    void getDeath(int &death, int born);
    void commandAdd();
};

#endif // CONSOLEUI_H
