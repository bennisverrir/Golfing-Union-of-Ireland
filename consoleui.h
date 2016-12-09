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

    void displayCommands();
    void validateCommand (int &command);
    void coutChoice(int command);
    void commandListScientists();
    void ascDesc();
    void commandListComputers();
    void commandListRelations();
    void commandAddScientist();
    void getName(string &name);
    bool checkName(string name, bool flag);
    string rightName(string name);
    void getGender(char &gender);
    void validateGender(char &gender);    
    void getBorn(int &born);
    void validateYear (int begin, int &input);
    void getDeath(int &death, int born);
    bool checkIfDead();
    void validateInputYN(char &toValidate);
    void commandAddComputer();
    void getComputerName(string &computerName);
    void getBuildYear(int &buildYear, bool &wasBuilt);
    bool checkIfBuilt(bool &wasBuilt);
    void commandListComputerTypes();
    void addComputerType();   
    void commandAddRelation();
    void commandFindScientist();
    void subCommandFind(int command, vector <Legend> &toPrint);
    void commandFindComputer();
    void subCommandFindComputer(int command, vector <Computer> &toPrint);
    void findRelation();
    void commandEditScientist();
    void commandEditComputer();
    void commandEditRelation();
    void deleteRelation();
    void fortyTwo();  
    void outputJoke();

    Service _service;
    int _numOfChoices;
    int _currentYear = 2016;
};

#endif // CONSOLEUI_H
