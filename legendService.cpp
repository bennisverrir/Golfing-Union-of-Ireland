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
void addLegend(string name, string gender, int born, int death){
    Legend a (name, gender, born, death);
    writeFile (a);
}
