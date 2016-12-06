#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <QtSql>
#include "legend.h"
#include "computer.h"

using namespace std;

class dataAccess
{
    QSqlDatabase db;
    QString dbName;

public:
    dataAccess();
    vector<Legend> pushingLegendVector(QSqlQuery query);
    vector<Computer> pushingComputerVector(QSqlQuery query);
    void writeFile(Legend writeLegend, bool &fileError);
    void writeComputerFile(Computer writeComputer, bool &fileError);
    void deleteLine(vector<Legend> &deleteLegend, bool &fileError);
    vector<Legend> sortLegend(int sort);
    vector<Computer> sortComputer(int sort);
    vector<Legend> findLegend(int whatToFind, string sort,bool &fileOpen);
private:
    const string fileName = "legend.txt";
};

#endif // DATAACCESS_H
