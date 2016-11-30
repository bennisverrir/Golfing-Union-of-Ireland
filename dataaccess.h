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
    void writeFile(Legend writeLegend, string fileName);
    void deleteLine(vector<Legend> deleteLegend);
};

#endif // DATAACCESS_H
