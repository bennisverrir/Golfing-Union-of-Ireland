#ifndef SERVICE_H
#define SERVICE_H

#include <algorithm>
#include <vector>
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
        bool requestLegendAdd(string name, char gender, int born, int death, string bio);
        bool requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt, int index, string bio);
        bool requestRelationAdd(int scientistID, int computerID);
        bool requestLegendEdit(string name, char gender, int born, int death, string bio, Legend oldLegend);
        bool requestComputerEdit(string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer,int index, string bio);
        bool requestRelationEdit(int scientistID, int computerID, Relation oldRelation);
        vector <Legend> requestLegendSort();
        vector <Computer> requestComputerSort();
        vector <Relation> requestRelationSort();
        vector <string> requestComputerTypes();
        bool requestComputerTypeAdd(string name);
        vector<Relation> findRelation(string name);
        bool requestRelationDelete(Relation deleteRelation);
        vector<string> getJoke();



private:
        dataAccess a;
        string _tableName;
        bool _ascDescOrder;
        string _searchString;
};

#endif // SERVICE_H
