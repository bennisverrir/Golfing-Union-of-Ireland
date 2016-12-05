#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include <algorithm>
#include <vector>
#include "computer.h"
#include "dataaccess.h"

using namespace std;

class ComputerService
{
public:
    ComputerService();
    vector <Computer> getComputers ();
    bool checkForValid(Computer computer);
    vector <Computer> getSort ();
    vector <Computer> getSortBuildYear ();
    vector <Computer> getSortComputerType ();
    vector <Computer> getSortWasBuilt ();
    void addComputer (string name, int buildYear, char computerType, bool wasBuilt, bool &boolValid);
    vector <Computer> findComputer(string nameToFind);
    vector <Computer> findComputer(int buildYearToFind);
    vector <Computer> findComputer(char typeToFind);
    vector <Computer> findComputer (bool wasBuilt);
    void deleteComputer(int index, vector<Computer> &deleteVector);
    bool getFileOpen();

private:
    dataAccess a;
    bool fileOpen;
};


#endif // COMPUTERSERVICE_H
