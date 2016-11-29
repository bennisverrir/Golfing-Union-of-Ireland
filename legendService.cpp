#include "legendService.h"
#include "dataaccess.h"


LegendService::LegendService()
{

}

vector <Legend> LegendService::getLegends(){
    vector <Legend> legend;
    dataAccess a;
    legend = a.readFile();
    return legend;
}
void addLegend(string name, char gender, int born, int death){
    Legend a (name, gender, born, death);
    dataAccess braeikka;
    braeikka.writeFile(a);
}
