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

   void addLegend (string name, char gender, int born, int death);
};

#endif // LEGENDSERVICE_H
