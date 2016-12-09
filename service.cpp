#include "Service.h"
Service::Service()
{

}

/*Function setTableName, @param int
*
*
*
void Service::setTableName (int command)
{
    if (command == 1)
    {
        _tableName = "Scientists";
    }
    else if (command == 2)
    {
        _tableName = "Computers";
    }
    else if (command == 3)
    {
        _tableName = "Relations";
    }
}*/

/*Function setCaseField, @parma int
*TODO
*
*/
void Service::setCaseField (int command)
{
    _caseField = command - 1;

}

/*Function setAscDescOrder, @return vector<string>
*return a vector of all the jokes in the joke table in sql
*
*/
void Service::setAscDescOrder (int command)
{
    if (command == 1)
    {
        _ascDescOrder = true;
    }
    else
    {
        _ascDescOrder = false;
    }
}

void Service::setSearchField (string toSearch)
{
    _searchString = toSearch;
}

void Service::setSearchField (int toSearch)
{
    _searchString = to_string(toSearch);
}

void Service::setSearchField (char toSearch)
{
    string s(1,toSearch);
    _searchString = s;
}

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

string Service::getTableName() const
{
    return _tableName;
}

int Service::getCaseField () const
{
    return _caseField;
}

string Service::getSearchField() const
{
    return _searchString;
}

vector <Legend> Service::requestLegendSearch()
{
    vector <Legend> returnVector;
    returnVector = a.findLegend (_caseField, _searchString);

    return returnVector;
}

vector <Computer> Service::requestComputerSearch()
{
    vector <Computer> returnVector;
    returnVector = a.findComputer (_caseField, _searchString);
    return returnVector;
}

vector <Relation> Service::requestRelationSearch()
{
    vector <Relation> returnVector;
    returnVector = a.sortRelation(_caseField, _ascDescOrder);
    return returnVector;
}
/*void Service::requestNonRelatedComputer(string scientistName)
{
   // a.findNonRelatedRelation(scientistName);
}

void Service::requestNonRelatedScientist(string computerName)
{
   // a.findNonRelatedRelation (computerName);
}*/

void Service::requestLegendAdd(string name, char gender, int born, int death)
{
    Legend myNewLegend (name, gender, born, death);
    a.writeFile(myNewLegend);
}

void Service::requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt,int index)
{
    Computer myNewComputer (name, yearBuilt, computerType, wasBuilt);
    a.writeComputerFile (myNewComputer, index);
}


void Service::requestRelationAdd (int scientistID, int computerID)
{
    Relation myNewRelation (scientistID, computerID);
    a.addRelation (myNewRelation);
}

void Service::requestLegendEdit (string name, char gender, int born, int death, Legend oldLegend){
    Legend myEditedLegend (name, gender, born, death);
    a.editLegend(oldLegend, myEditedLegend);
}
void Service::requestComputerEdit (string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer, int index){
    Computer myEditedComputer (name, yearBuilt, computerType, wasBuilt);
    a.editComputer(oldComputer, myEditedComputer, index);
}
void Service::requestRelationEdit (string scientistName, string computerName, Relation oldRelation){
    Relation myEditedRelation (scientistName, computerName);
    a.editRelation (oldRelation, myEditedRelation);
}

/*Function requestComputerSort, @returns vector<Computer>
*
*
*/
vector<Computer> Service::requestComputerSort()
{
    return a.sortComputer(_caseField, _ascDescOrder);
}

/*Function requestRelationSort, @returns vector<Relation>
* calles the function sortRelation in the dataAccess class
*and returns a sorted vector of Relation
*/
vector<Relation> Service::requestRelationSort()
{
    return a.sortRelation(_caseField, _ascDescOrder);
}

/*Function requestComputerTypes, @returns vector<string>
* calles the function getComputerType in the dataAccess class
*and returns a vector of strings containing all computer types
*/

vector <string> Service::requestComputerTypes()
{
    return a.getComputerTypes();
}

/*Function requestComputerTypeAdd, @parma string
* calles the function addComputerType in the dataAccess class
*
*/
void Service::requestComputerTypeAdd(string name)
{
    a.addComputerType(name);
}

/*Function findRelation, @parma string
*
*
*/
vector<Relation> Service::findRelation(string name)
{
    return a.findRelation(name);
}


/*Function requestRelationDelete, @parma Relation
* calles the function addRelation in the dataAccess class
*
*/
void Service::requestRelationDelete(Relation deleteRelation)
{
   a.deleteRelation(deleteRelation);
}


/*Function getJoke, @return string
*
*
*/
string Service::getJoke()
{
    string joke;
    joke = a.joke()[rand() % a.joke().size()];

    return joke;
}
