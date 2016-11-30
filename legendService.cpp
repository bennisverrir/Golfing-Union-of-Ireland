#include "legendService.h"
#include <iostream>
#include <algorithm>

struct legendComparison
{
    bool operator() (Legend i,Legend j){return(i.getName() < j.getName());}
};
struct legendComparisonGender
{
    bool operator() (Legend i,Legend j){return(i.getGender() < j.getGender());}
};
struct legendComparisonBirth
{
    bool operator() (Legend i,Legend j){return(i.getBorn() < j.getBorn());}
};

LegendService::LegendService()
{

}

vector <Legend> LegendService::getLegends(){
    vector <Legend> legend;
    legend = a.readFile();
    return legend;
}
vector <Legend> LegendService::getSort(){
    vector <Legend> legends2;
    legends2 = a.readFile();
    legendComparison cmp;
    sort(legends2.begin(), legends2.end(), cmp);
    return legends2;
}
vector <Legend> LegendService::getSortGender() //copy
{
    vector <Legend> legends3;
    legends3 = a.readFile();
    legendComparisonGender cmp;
    sort(legends3.begin(), legends3.end(), cmp);
    return legends3;
}
vector <Legend> LegendService::getSortDateOfBirth() //copy
{
    vector <Legend> legends4;
    legends4 = a.readFile();
    legendComparisonBirth cmp;
    sort(legends4.begin(), legends4.end(), cmp);
    return legends4;
}
void LegendService::addLegend(string name, char gender, int born, int death){
    Legend person (name, gender, born, death);
    a.writeFile(person);
}

vector <Legend> LegendService::findLegend(string nameToFind){
    vector <Legend> legend = a.readFile();
    string myString;
    vector <Legend> returnVector;
    for (size_t i = 0;i < legend.size(); i++ ){
        if (legend[i].getName().find(nameToFind) != string::npos) {
            returnVector.push_back(legend[i]);
            /*
            myString = legend[i].getName();
            myString.append ("\t ");
            myString += legend[i].getGender();
            myString.append ("\t ");
            myString.append (to_string(legend[i].getBorn()));
            myString.append ("\t ");
            myString.append (to_string(legend[i].getDeath()));
            returnVector.push_back(myString);
            */
        }
    }
    return returnVector;

}
