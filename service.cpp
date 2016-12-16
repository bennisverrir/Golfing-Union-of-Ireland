#include "Service.h"
Service::Service()
{

}

/*Function setSearchField, @param string
*Sets the string that will be searched for when passed to the dataAccess layer.
*/
void Service::setSearchField (string toSearch)
{
    _searchString = toSearch;
}

/*Function setSearchField, @param int
*Sets the string that will be searched for when passed to the dataAccess layer.
*/
void Service::setSearchField (int toSearch)
{
    _searchString = to_string(toSearch);
}
/*Function setSearchField, @param char
*Sets the string that will be searched for when passed to the dataAccess layer.
*/
void Service::setSearchField (char toSearch)
{
    string s(1,toSearch);
    _searchString = s;
}
/*Function setSearchField, @param bool
*Sets the string that will be searched for when passed to the dataAccess layer.
*/
void Service::setSearchField (bool toSearch)
{
    if (toSearch)
    {
        _searchString = "1";
    }
    else
    {
        _searchString = "0";
    }
}

/*Function getCaseField, @param string
*Gets the currently selected parameter to search for.
* returns a case field to search for
*/

string Service::getSearchField() const
{
    return _searchString;
}

/*Function requestLegendSearch, @return vector <Legend>
* forwards the findLegend function to data-access class
*/
vector <Legend> Service::requestLegendSearch()
{
    vector <Legend> returnVector;
    returnVector = a.findLegend (_searchString);

    return returnVector;
}

/*Function requestComputerSearch, @return vector <Computer>
* forwards the findComputer function to data-access class
*/
vector <Computer> Service::requestComputerSearch()
{
    vector <Computer> returnVector;
    returnVector = a.findComputer (_searchString);
    return returnVector;
}

/*Function requestRelationSearch, @return vector <Relation>
* forwards the findRelation function to data-access class
*/
vector <Relation> Service::requestRelationSearch()
{
    vector <Relation> returnVector;


    returnVector = a.findRelation(_searchString);
    return returnVector;
}

/*Function requestLegendAdd, @parma string, char, int, int
* forwards the function addLegend to the data-access class
* returns a value of success or fail
*/
bool Service::requestLegendAdd(string name, char gender, int born, int death, string bio)
{

    Legend myNewLegend (name, gender, born, death, bio);
    return a.writeFile(myNewLegend);
}

/*Function requestComputerAdd, @parma int, string, char, bool and int
* forwards the function addComputer to the data-access class
* returns a value of success or fail
*/
bool Service::requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt, int index, string bio)
{
    for(size_t i = 0; i < bio.size(); i++)
    {
        if(bio.at(i) == '\'')
        {
            bio.insert(i-1,"'",1);
        }
    }

    qDebug() << QString::fromStdString(bio);

    Computer myNewComputer (name, yearBuilt, computerType, wasBuilt, bio);
    return a.writeComputerFile (myNewComputer, index);
}

/*Function requestRelationAdd, @parma int
* forwards the function addRelation to the data-access class
* returns a value of success or fail
*/
bool Service::requestRelationAdd (int scientistID, int computerID)
{
    Relation myNewRelation (scientistID, computerID);
    return a.addRelation (myNewRelation);
}

/*Function requestLegendEdit, @parma string, char, int and legend
* forwards the function editLegend to the data-access class
* returns a value of success or fail
*/
bool Service::requestLegendEdit (string name, char gender, int born, int death, string bio, Legend oldLegend)
{
    Legend myEditedLegend (name, gender, born, death, bio);
    return a.editLegend(oldLegend, myEditedLegend);

}

/*Function requestComputerEdit, @parma string, int, bool and Computer
* forwards the function editComputer in the data-acess class
*
*/
bool Service::requestComputerEdit (string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer, int index, string bio)
{
    Computer myEditedComputer (name, yearBuilt, computerType, wasBuilt, bio);
    return a.editComputer(oldComputer, myEditedComputer, index);
}

/*Function requestRelationEdit, @parma string and Relation
* forwards the function editRelation to the data-access class
* returns a value of success or fail
*/
bool Service::requestRelationEdit (int scientistID, int computerID, Relation oldRelation)
{
    return a.editRelation (scientistID, computerID, oldRelation);
}


vector <Legend> Service::requestLegendSort()
{
    return a.sortLegend();
}

/*Function requestComputerSort, @returns vector<Computer>
* forwards the function computer sorting to the data-access class
* returns a vector of computers
*/
vector<Computer> Service::requestComputerSort()
{
    return a.sortComputer();
}

/*Function requestRelationSort, @returns vector<Relation>
* forwards the function sortRelation to the data-access class
* and returns a vector of relations
*/
vector<Relation> Service::requestRelationSort()
{
    return a.sortRelation();
}

/*Function requestComputerTypes, @returns vector<string>
* forwards the function getComputerType to the data-access class
* and returns a vector of strings containing all computer types
*/

vector <string> Service::requestComputerTypes()
{
    return a.getComputerTypes();
}

/*Function requestComputerTypeAdd, @parma string
* forwards the function addComputerType to the data-access class
* returns a bool of success or fail
*/
bool Service::requestComputerTypeAdd(string name)
{
    return a.addComputerType(name);
}
/*Function requestComputerTypeAdd, @parma string
* forwards the function find relation to the data-access class
* returns a vector of relations
*/
vector<Relation> Service::findRelation(string name)
{
    return a.findRelation(name);
}


/*Function requestRelationDelete, @parma Relation
* calles the function addRelation in the dataAccess class
*
*/
bool Service::requestRelationDelete(Relation deleteRelation)
{
   return a.deleteRelation(deleteRelation);
}


/*Function getJoke, @return string
*
*
*/
vector<string> Service::getJoke()
{
    return a.joke();
}
