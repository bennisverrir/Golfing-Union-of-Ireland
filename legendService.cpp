#include "legendService.h"
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
vector <Legend> LegendService::getLegends()
{
    vector <Legend> legend;
    legend = a.readFile();
    return legend;
}
vector <Legend> LegendService::getSort()
{
    vector <Legend> legends2;
    legends2 = a.readFile();
    legendComparison cmp;
    sort(legends2.begin(), legends2.end(), cmp);
    return legends2;
}
vector <Legend> LegendService::getSortGender()
{
    vector <Legend> legends3;
    legends3 = a.readFile();
    legendComparisonGender cmp;
    sort(legends3.begin(), legends3.end(), cmp);
    return legends3;
}
vector <Legend> LegendService::getSortDateOfBirth()
{
    vector <Legend> legends4;
    legends4 = a.readFile();
    legendComparisonBirth cmp;
    sort(legends4.begin(), legends4.end(), cmp);
    return legends4;
}
void LegendService::addLegend(string name, char gender, int born, int death)
{
    Legend person (name, gender, born, death);
    a.writeFile(person, "legend.txt");
}

vector <Legend> LegendService::findLegend(string nameToFind){
    vector <Legend> legend = a.readFile();
    vector <Legend> returnVector;
    for (size_t i = 0;i < legend.size(); i++ ){
        if (legend[i].getName().find(nameToFind) != string::npos) {
            returnVector.push_back(legend[i]);
        }
    }
    return returnVector;
}

vector <Legend> LegendService::findLegend(char genderToFind){
    vector <Legend> legend = a.readFile();
    vector <Legend> returnVector;
    for (size_t i = 0;i < legend.size(); i++ ){
        if (legend[i].getGender() == toupper (genderToFind)){
            returnVector.push_back(legend[i]);
        }
    }
    return returnVector;
}

vector <Legend> LegendService::findLegend(int yearToFind, bool select){
    vector <Legend> legend = a.readFile();
    vector <Legend> returnVector;
    if(select == true)
    {
        for (size_t i = 0;i < legend.size(); i++ ){
            if (legend[i].getBorn() == yearToFind){
                returnVector.push_back(legend[i]);
            }
        }
        return returnVector;
    }
    else
    {
        for (size_t i = 0;i < legend.size(); i++ ){
            if (legend[i].getDeath() == yearToFind){
                returnVector.push_back(legend[i]);
            }
        }
        return returnVector;
    }
}

void LegendService::deleteLegend(int index, vector<Legend> deleteVector)
{
    vector<Legend> newLegend = getLegends();

    for(size_t i = 0; i < newLegend.size(); i++)
    {
        if((deleteVector[index-1].getName() == newLegend[i].getName()) && (deleteVector[index-1].getGender() == newLegend[i].getGender()) &&
           (deleteVector[index-1].getBorn() == newLegend[i].getBorn()) && (deleteVector[index-1].getDeath() == newLegend[i].getDeath()))
        {
            newLegend.erase(newLegend.begin()+i);
            break;
        }
    }
    a.deleteLine(newLegend);
}
