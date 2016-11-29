/*
#include "legendService.h"
#include <algorithm>

struct legendComparison
{
    bool operator() (Legend i,Legend j){return(i.getName()<j.getName());}
};
LegendService::LegendService()
{

}

vector <Legend> LegendService::getLegends(){
    vector <Legend> legend;
    legend = a.readFile();

    legendComparison cmp;
    sort(legend.begin(), legend.end(), cmp);
    return legend;
}
void addLegend(string name, char gender, int born, int death){
    Legend person (name, gender, born, death);

    a.writeFile(person);
}
*/
#include "legendService.h"
#include <iostream>
#include <algorithm>

struct legendComparison
{
    bool operator() (Legend i,Legend j){return(i.getName()<j.getName());}
};

LegendService::LegendService()
{

}

vector <Legend> LegendService::getLegends(){
    vector <Legend> legend;
    legend = a.readFile();
    legendComparison cmp;
    sort(legend.begin(), legend.end(), cmp);
    return legend;
}
void LegendService::addLegend(string name, char gender, int born, int death){
    Legend person (name, gender, born, death);
    a.writeFile(person);
}
