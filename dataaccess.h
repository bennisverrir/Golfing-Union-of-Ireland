#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include "legend.h"

using namespace std;

class dataAccess
{
public:
    dataAccess();
    vector<Legend> readFile();
    void writeFile(Legend writeLegend);
    void deleteLine(vector<Legend> deleteLegend);
private:
    const string fileName = "legend.txt";
};

#endif // DATAACCESS_H
