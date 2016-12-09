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
    void writeFile(Legend writeLegend);
    void writeComputerFile(Computer writeComputer, int index);
    void deleteLine(vector<Legend> &deleteLegend);
    vector<Legend> sortLegend(int sort, bool ascDesc);
    vector<Computer> sortComputer(int sort, bool ascDesc);
    vector<Legend> findLegend(int whatToFind, string sort);
    vector<Computer> findComputer(int whatToFind, string find);
    vector<string> getComputerTypes();
    void addComputerType(string newComputerType);
    vector<Relation> sortRelation(int sort, bool ascDesc);
    void addRelation(Relation relation);
    void editLegend(Legend oldLegend, Legend editLegend);
    void editComputer(Computer oldComputer, Computer editComputer, int index);
    int getID(QSqlQuery query,QString name, QString tableName);
    void findNonRelatedRelation(Legend scientist);
    void findNonRelatedRelation(Computer computer);
    vector<Relation> findRelation(int nameToFind, int sort);
    vector<Relation> findRelation(string nameToFind, int sort);
    void deleteRelation(Relation relationToDelete);
    void editRelation(Relation oldRelation, Relation editedRelation);
    vector<string>joke();


private:
    const string fileName = "legend.txt";
};

#endif // DATAACCESS_H
