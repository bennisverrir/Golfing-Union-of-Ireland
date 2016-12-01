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
    bool checkForValid(Legend legend);
    vector <Legend> getSort ();
    vector <Legend> getSortGender (); 
    vector <Legend> getSortDateOfBirth ();
    vector <Legend> getSortStillAlive ();
    vector <Legend> findLegend(string nameToFind);
    vector <Legend> findLegend(char genderToFind);
    vector <Legend> findLegend(int yearToFind, bool select);
    void addLegend (string name, char gender, int born, int death, bool &boolValid);
    void deleteLegend(int index, vector<Legend> deleteVector);
};

#endif // LEGENDSERVICE_H
