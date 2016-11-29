#include "legendService.h"

LegendService::LegendService()
{

}
vector <Legend> LegendService::getLegends(){
    vector <Legend> legend;

    Legend h ("Helgi", "male", 1991);
    Legend e ("Elvar", "male", 1995);
    Legend s ("Sara", "female", 1991);
    Legend b ("Benni", "male", 1991);
    Legend k ("Kolbeinn", "male", 1995);
    Legend t ("Thorfinnur", "male", 1995);
    legend.push_back(h);
    legend.push_back(e);
    legend.push_back(s);
    legend.push_back(b);
    legend.push_back(k);
    legend.push_back(t);

    //TODO: business logic!
    return legend;
}
void addLegend(string name, string gender, int born){
    Legend a (name, gender, born);

}
