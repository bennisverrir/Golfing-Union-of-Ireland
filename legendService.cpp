#include "legendService.h"
#include <iostream>
#include <algorithm>

struct legendComparison
{
    bool operator() (Legend i,Legend j){return(i.getName() < j.getName());}
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
void LegendService::addLegend(string name, char gender, int born, int death){
    Legend person (name, gender, born, death);
    a.writeFile(person);
}

vector <Legend> LegendService::findLegend(string nameToFind){
    vector <Legend> legend;
    vector <Legend> targetLegend;
    dataAccess a;
    legend = a.readFile();
    for (size_t i = 0;i < legend.size(); i++ ){
        if (legend[i].getName().find(nameToFind) != string::npos) {
        targetLegend.push_back(legend[i]);
        }
    }
    return targetLegend;
}
