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
#include "relation.h"

using namespace std;

class dataAccess
{
    QSqlDatabase db;
    QString dbName;

public:
    dataAccess();
    ~dataAccess();
    vector<Legend> pushingLegendVector(QSqlQuery query);
    vector<Computer> pushingComputerVector(QSqlQuery query);
    bool writeFile(Legend writeLegend);
    bool writeComputerFile(Computer writeComputer, int index);
    void deleteLine(vector<Legend> &deleteLegend);
    vector<Legend> sortLegend();
    vector<Computer> sortComputer();
    vector<Legend> findLegend(string sort);
    vector<Computer> findComputer(string find);
    vector<string> getComputerTypes();
    bool addComputerType(string newComputerType);
    vector<Relation> sortRelation();
    bool addRelation(Relation relation);
    bool editLegend(Legend oldLegend, Legend editLegend);
    bool editComputer(Computer oldComputer, Computer editComputer, int index);
    int getID(QSqlQuery query,QString name, QString tableName);
    vector<Relation> findRelation(string nameToFind);
    bool deleteRelation(Relation relationToDelete);
    bool editRelation(int scientistID, int computerID, Relation oldRelation);
    vector<string>joke();
};

#endif // DATAACCESS_H
