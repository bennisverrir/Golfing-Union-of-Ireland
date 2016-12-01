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
    void validateInput (int &intValue);
    void subCommandFind(char command, vector <Legend> &toPrint);
    void CommandFind();
    void CommandDelete();
    void commandClear();
    void displayCommands();
    bool checkName(string name, bool flag);
    string getName(string name);
    string rightName(string name);
    void getGender(char &gender);
    void getBorn(int &born);
    bool checkIfDead();
    void getDeath(int &death, int born);
    void commandAdd();
};

#endif // CONSOLEUI_H
