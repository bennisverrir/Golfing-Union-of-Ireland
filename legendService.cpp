#include "legendService.h"
#include <algorithm>

/* struct legendComparison
 * @returns order of (2) legends based on names, gender birth year or if they're still alive
 * (See corresponding names).
 * utilizes the sort algorithm in the algorithm package included in the class.
 */
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
struct legendComparisonStillAlive
{
    bool operator() (Legend i,Legend j){return(i.getDeath() < j.getDeath());}
};

LegendService::LegendService()
{

}
/* function getLegends
 * @return vector of legends as read from file.
 * contacts dataaccess-layer to create a vector of legends from entries on list.
 */
vector <Legend> LegendService::getLegends()
{
    vector <Legend> legend;
    legend = a.readFile();
    return legend;
}
/* function checkForValid @param user input class legend.
 * @return boolean value of whether input is already listed.
 * runs user input legend through vector of listed inputs (from file),
 * utilizes overloaded operator to compare all values.
 */
bool LegendService::checkForValid(Legend legend)
{
    vector<Legend> legends = getLegends();

    for(int i = 0; i < legends.size(); i++)
    {
        if(legends[i] == legend)
        {
            return false;
        }
    }

    return true;
}
/* function getSort
 * @return sorted vector of legends
 * utilizes legendComparison struct to compare names (1 at a time)
 * of entries in unsorted vector to sorted vector. (selection sort)
 */
vector <Legend> LegendService::getSort()
{
    vector <Legend> legends2 = getLegends();
    legendComparison cmp;
    sort(legends2.begin(), legends2.end(), cmp);
    return legends2;
}
/* function getSortGender
 * @return sorted vector of legends
 * utilizes legendComparisonGender struct to compare genders (1 at a time)
 * of entries of unsorted vector to sorted vector (selection sort).
 */
vector <Legend> LegendService::getSortGender()
{
    vector <Legend> legends3 = getLegends();
    legendComparisonGender cmp;
    sort(legends3.begin(), legends3.end(), cmp);
    return legends3;
}
/* function getSortDateOfBirth
 * @return sorted vector of legends
 * utilizes legendComparisonBirth struct to compare birth year (1 at a time)
 * of entries in unsorted vector to sorted vector (selection sort).
 */
vector <Legend> LegendService::getSortDateOfBirth()
{
    vector <Legend> legends4 = getLegends();
    legendComparisonBirth cmp;
    sort(legends4.begin(), legends4.end(), cmp);
    return legends4;
}
/* function getSortStillAlive
 * @return sorted vector of legends
 * utilizes the legendComparisonStillAlive struct to compare values of year died (1 at a time)
 * of entries in unsorted vector to sorted vector (selection sort).
 */
vector <Legend> LegendService::getSortStillAlive()
{
    vector <Legend> legends5 = getLegends();
    legendComparisonStillAlive cmp;
    sort(legends5.begin(), legends5.end(), cmp);
    return legends5;
}
/* function addLegend @param user input name, gender, year born and died (if applicable)
 * and a bool that determines if the legend is already listed.
 * @return void
 * if the entry is valid, contacts dataaccess and adds a new line to the list of legends if so.
 */
void LegendService::addLegend(string name, char gender, int born, int death, bool &boolValid)
{
    Legend person (name, gender, born, death);

    bool valid = checkForValid(person);

    if(valid)
    {
        boolValid = true;
        a.writeFile(person, "legend.txt");
    }
    else
    {
        boolValid = false;
    }
}

/* function findLegend, @param the name input
 * @returns a vector of matching inputs (from file)
 * accepts a input string (name) and compares to set name of the inputs from file.
 */
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
/* function findLegend, @param the gender input
 * @returns a vector of matching inputs (from file)
 * accepts a input character (gender) and compares to set gender.
 */
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
/* function findLegend, @param the year input and bool to select born or death
 * @returns a vector of matching inputs (from file)
 * accepts a input integer (year) and compares to either born or death value
 * depending on the boolean parameter.
 */
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
/*function deleteLegend, @param list index and vector of legends acquired via search function
 * @return void.
 * Accepts the index of a legend from a list of matching legends
 * loops through the entire file to find a matching index of the legend to delete
 * then deletes the entry specified.
 */
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
