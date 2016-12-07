#ifndef SERVICE_H
#define SERVICE_H

#include <algorithm>
#include <vector>
#include "legend.h"
#include "dataaccess.h"

using namespace std;

class Service
{
public:
    Service();
        void setTableName (int command);
        void setCaseField (int command);
        void setSearchField (string toSearch);
        void setSearchField (int toSearch);
        void setSearchField (char toSearch);
        void setSearchField (bool toSearch);
        vector <Legend> requestLegendSearch();
        vector <Computer> requestComputerSearch();
        void requestLegendAdd(string name, char gender, int born, int death);
        void requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt, int index);
        vector <Legend> requestLegendSort();
        vector <Computer> requestComputerSort();
        vector<string> requestComputerTypes();
        void requestComputerTypeAdd(string name);


private:
        dataAccess a;
        string _tableName;
        int _caseField;
        string _searchString;
};

#endif // SERVICE_H
