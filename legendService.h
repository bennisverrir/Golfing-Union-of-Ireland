#ifndef LEGENDSERVICE_H
#define LEGENDSERVICE_H

#include <vector>
#include "legend.h"

using namespace std;

class LegendService
{
public:
    LegendService();
    vector <Legend> getLegends ();
    addLegend ();
};

#endif // LEGENDSERVICE_H
