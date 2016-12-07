#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream>
#include <iomanip>
#include "legend.h"
#include "service.h"
#include "relation.h"


class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
private:
    Service _service;
    //ComputerService  _cService;
    void coutChoice(int command);
    void displayCommands();
    void commandList();
    //void checkForFileError();
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
    void subCommandFind(int command, vector <Legend> &toPrint);
    void commandClear();
    void fortyTwo();
    void commandListComputers();
    void commandAddComputer();
    void getBuildYear(int buildYear);
    void getComputerType(int computerType);
    bool getWasBuilt(bool wasBuilt);
    string getComputerName(string ComputerName);
    void sortComputer(char sortComputerCommand, vector<Computer>& computers);
    void commandListComputerTypes();
    void addComputerType();
};

#endif // CONSOLEUI_H
