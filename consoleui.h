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
    void commandListScientists();
    //void checkForFileError();
    void commandAddScientist();
    void commandEditComputer();
    void getName(string &name);
    bool checkName(string name, bool flag);
    string rightName(string name);
    void getGender(char &gender);
    void getBorn(int &born);
    void validateCommand (int &command);
    void validateYear (int begin, int &input);
    void getDeath(int &death, int born);
    bool checkIfDead();
    void commandDelete();
    void commandFindScientist();
    void subCommandFind(int command, vector <Legend> &toPrint);
    void commandClear();
    void fortyTwo();
    void commandListComputers();
    void commandAddComputer();
    void getComputerType(int computerType);
    bool getWasBuilt(bool wasBuilt);
    void sortComputer(char sortComputerCommand, vector<Computer>& computers);
    void commandListComputerTypes();
    void addComputerType();
    void commandFindComputer();
    void commandEditScientist();
    void ascDesc();
    void validateGender(char &gender);
    void validateInputYN(char &toValidate);
    void commandEditRelation();
    void findRelation();
    void commandListRelations();
    void commandAddRelation();
    void subCommandFindComputer(int command, vector <Computer> &toPrint);
    void getComputerName(string &computerName);
    void getBuildYear(int &buildYear, bool &wasBuilt);
    bool checkIfBuilt(bool &wasBuilt);




    int _numOfChoices;
    int _currentYear = 2016;
};

#endif // CONSOLEUI_H
