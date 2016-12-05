#include "computerService.h"

struct computerComparison
{
    bool operator() (Computer i,Computer j)
    {
        return(i.getName() < j.getName());
    }
};
struct computerComparisonBuildYear
{
    bool operator() (Computer i,Computer j)
    {
        return(i.getBuildYear() < j.getBuildYear());
    }
};
struct computerComparisonComputerType
{
    bool operator() (Computer i,Computer j)
    {
        return(i.getComputerType() < j.getComputerType());
    }
};
struct computerComparisonWasBuilt
{
    bool operator() (Computer i,Computer j)
    {
        return(i.getWasBuilt() < j.getWasBuilt());
    }
};

ComputerService::ComputerService()
{
    fileOpen = false;
}
/* function getLegends
 * @return vector of legends as read from file.
 * contacts dataaccess-layer to create a vector of legends from entries on list.
 */
vector <Computer> ComputerService::getComputers()
{
    vector <Computer> computers;
    computers = a.readComputerFile(fileOpen);
    return computers;
}
/* function checkForValid @param user input class legend.
 * @return boolean value of whether input is already listed.
 * runs user input legend through vector of listed inputs (from file),
 * utilizes overloaded operator to compare all values.
 */
bool ComputerService::checkForValid(Computer computer)
{
    vector<Computer> computers = getComputers();

    for(size_t i = 0; i < computers.size(); i++)
    {
        if(computers[i] == computer)
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
vector <Computer> ComputerService::getSort()
{
    vector <Computer> computers = getComputers();
    computerComparison cmp;
    sort(computers.begin(), computers.end(), cmp);
    return computers;
}
/* function getSortGender
 * @return sorted vector of legends
 * utilizes legendComparisonGender struct to compare genders (1 at a time)
 * of entries of unsorted vector to sorted vector (selection sort).
 */
vector <Computer> ComputerService::getSortBuildYear()
{
    vector <Computer> computers = getComputers();
    computerComparisonBuildYear cmp;
    sort(computers.begin(), computers.end(), cmp);
    return computers;
}
/* function getSortDateOfBirth
 * @return sorted vector of legends
 * utilizes legendComparisonBirth struct to compare birth year (1 at a time)
 * of entries in unsorted vector to sorted vector (selection sort).
 */
vector <Computer> ComputerService::getSortComputerType()
{
    vector <Computer> computers = getComputers();
    computerComparisonComputerType cmp;
    sort(computers.begin(), computers.end(), cmp);
    return computers;
}
/* function getSortStillAlive
 * @return sorted vector of legends
 * utilizes the legendComparisonStillAlive struct to compare values of year died (1 at a time)
 * of entries in unsorted vector to sorted vector (selection sort).
 */
vector <Computer> ComputerService::getSortWasBuilt()
{
    vector <Computer> computers = getComputers();
    computerComparisonWasBuilt cmp;
    sort(computers.begin(), computers.end(), cmp);
    return computers;
}
/* function addLegend @param user input name, gender, year born and died (if applicable)
 * and a bool that determines if the legend is already listed.
 * @return void
 * if the entry is valid, contacts dataaccess and adds a new line to the list of legends if so.
 */
void ComputerService::addComputer(string name, int buildYear, char computerType, bool wasBuilt, bool &boolValid)
{
    Computer computer (name, buildYear, computerType, wasBuilt);

    bool valid = checkForValid(computer);

    if(valid)
    {
        boolValid = true;
    //    a.writeFile(computer, fileOpen);
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
vector <Computer> ComputerService::findComputer(string nameToFind){
    vector <Computer> computers = getComputers();
    vector <Computer> returnVector;
    for (size_t i = 0;i < computers.size(); i++ ){
        if (computers[i].getName().find(nameToFind) != string::npos) {
            returnVector.push_back(computers[i]);
        }
    }
    return returnVector;
}
/* function findLegend, @param the gender input
 * @returns a vector of matching inputs (from file)
 * accepts a input character (gender) and compares to set gender.
 */
vector <Computer> ComputerService::findComputer(int buildYearToFind){
    vector <Computer> computers = getComputers();
    vector <Computer> returnVector;
    for (size_t i = 0;i < computers.size(); i++ ){
        if (computers[i].getBuildYear() == buildYearToFind){
            returnVector.push_back(computers[i]);
        }
    }
    return returnVector;
}
/* function findLegend, @param the year input and bool to select born or death
 * @returns a vector of matching inputs (from file)
 * accepts a input integer (year) and compares to either born or death value
 * depending on the boolean parameter.
 */
vector <Computer> ComputerService::findComputer(char computerTypeToFind){
    vector <Computer> computers = getComputers();
    vector <Computer> returnVector;
    for (size_t i = 0;i < computers.size(); i++ ){
        if (computers[i].getComputerType() == computerTypeToFind){
            returnVector.push_back(computers[i]);
        }
    }
    return returnVector;
}
/*function deleteLegend, @param list index and vector of legends acquired via search function
 * @return void.
 * Accepts the index of a legend from a list of matching legends
 * loops through the entire file to find a matching index of the legend to delete
 * then deletes the entry specified.
 */
void ComputerService::deleteComputer(int index, vector<Computer> &deleteVector)
{
    vector<Computer> newComputer = getComputers();

    for(size_t i = 0; i < newComputer.size(); i++)
    {
        if(deleteVector[index-1] == newComputer[i])
        {
            newComputer.erase(newComputer.begin()+i);
            break;
        }
    }
    //a.deleteLine(newComputer, fileOpen);
}
/*function getFileOpen
 * @return bool.
 * returns true if file is open and false if file could not be open.
 */
bool ComputerService::getFileOpen()
{
    return fileOpen;
}

