#ifndef LEGENDSERVICE_H
#define LEGENDSERVICE_H
#include "dataaccess.h"
#include <vector>
#include "legend.h"


using namespace std;

class LegendService
{
    dataAccess a;
public:
    LegendService();
    vector <Legend> getLegends ();
    vector <Legend> getSort ();
    vector <Legend> getSortGender (); 
    vector <Legend> getSortDateOfBirth ();
    vector <Legend> findLegend(string nameToFind);
   void addLegend (string name, char gender, int born, int death);
};

#endif // LEGENDSERVICE_H
