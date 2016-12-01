#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "legend.h"

using namespace std;

class dataAccess
{
public:
    dataAccess();
    vector<Legend> readFile(bool &fileError);
    void writeFile(Legend writeLegend, bool &fileError);
    void deleteLine(vector<Legend> &deleteLegend, bool &fileError);
private:
    const string fileName = "legend.txt";
};

#endif // DATAACCESS_H
