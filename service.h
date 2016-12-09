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
        void setTableName (int command);
        void setCaseField (int command);
        void setAscDescOrder (int command);
        void setSearchField (string toSearch);
        void setSearchField (int toSearch);
        void setSearchField (char toSearch);
        void setSearchField (bool toSearch);
        string getTableName () const;
        int getCaseField() const;
        string getSearchField() const;
        vector <Legend> requestLegendSearch();
        vector <Computer> requestComputerSearch();
        vector <Relation> requestRelationSearch();
        void requestNonRelatedComputer(string name);
        void requestLegendAdd(string name, char gender, int born, int death);
        void requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt, int index);
        void requestRelationAdd (int scientistID, int computerID);
        void requestLegendEdit(string name, char gender, int born, int death, Legend oldLegend);
        void requestComputerEdit(string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer,int index);
        void requestRelationEdit(string scientistName, string computerName, Relation oldRelation);
        vector <Legend> requestLegendSort();
        vector <Computer> requestComputerSort();
        vector <Relation> requestRelationSort();
        vector <string> requestComputerTypes();
        void requestComputerTypeAdd(string name);
        vector<Relation> findRelation(string name);
        void requestRelationDelete(Relation deleteRelation);
        string getJoke();



private:
        dataAccess a;
        string _tableName;
        int _caseField;
        bool _ascDescOrder;
        string _searchString;
};

#endif // SERVICE_H
