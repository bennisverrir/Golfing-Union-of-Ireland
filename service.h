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
        void requestComputerAdd(string name, int yearBuilt, int computerType, bool wasBuilt);
        vector <Legend> requestLegendSort();

private:
        dataAccess a;
        string _tableName;
        int _caseField;
        string _searchString;
};

#endif // SERVICE_H
