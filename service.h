#ifndef SERVICE_H
#define SERVICE_H

#include <algorithm>
#include <vector>
#include <cstdlib>
#include "legend.h"
#include "dataaccess.h"
#include "computer.h"
#include "relation.h"

using namespace std;

class Service
{
public:
    Service();
        void setSearchField (string toSearch);
        void setSearchField (int toSearch);
        void setSearchField (char toSearch);
        void setSearchField (bool toSearch);
        string getSearchField() const;
        vector <Legend> requestLegendSearch();
        vector <Computer> requestComputerSearch();
        vector <Relation> requestRelationSearch();
        bool requestLegendAdd(string name, char gender, int born, int death);
        bool requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt, int index);
        bool requestRelationAdd(int scientistID, int computerID);
        bool requestLegendEdit(string name, char gender, int born, int death, Legend oldLegend);
        bool requestComputerEdit(string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer,int index);
        bool requestRelationEdit(string scientistName, string computerName, Relation oldRelation);
        vector <Legend> requestLegendSort();
        vector <Computer> requestComputerSort();
        vector <Relation> requestRelationSort();
        vector <string> requestComputerTypes();
        bool requestComputerTypeAdd(string name);
        vector<Relation> findRelation(string name);
        bool requestRelationDelete(Relation deleteRelation);
        string getJoke();



private:
        dataAccess a;
        string _tableName;
        bool _ascDescOrder;
        string _searchString;
};

#endif // SERVICE_H
