#include "Service.h"
Service::Service()
{

}

/*Function setTableName, @param int
*
*
*/
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
}

/*Function setCaseField, @param int
*Sets the search field (parameter selection). The value is transformed to a corresponding value or column in the data layer.
*/
void Service::setCaseField (int command)
{
    _caseField = command - 1;

}

/*Function setAscDescOrder, @param int
*Decides where items should be sorted in ascending or descending order in the sorting function.
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
/*Function getTableName, @param
*gets the name of the currently selected table.
*/
string Service::getTableName() const
{
    return _tableName;
}
/*Function getCaseField, @param string
*Gets the currently selected parameter to search for.
*/
int Service::getCaseField () const
{
    return _caseField;
}
/*Function getSearchField, @param string
*get the string that was inputted to be searched for.
*/
string Service::getSearchField() const
{
    return _searchString;
}

/*Function requestLegendSearch, @return vector <Legend>
*
*
*/
vector <Legend> Service::requestLegendSearch()
{
    vector <Legend> returnVector;
    returnVector = a.findLegend (_caseField, _searchString);

    return returnVector;
}

/*Function requestComputerSearch, @return vector <Computer>
*
*
*/
vector <Computer> Service::requestComputerSearch()
{
    vector <Computer> returnVector;
    returnVector = a.findComputer (_caseField, _searchString);
    return returnVector;
}

/*Function requestRelationSearch, @return vector <Relation>
*
*
*/
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


/*Function requestLegendAdd, @parma string, char and int
* calles the function writeFile in the dataAccess class
*
*/
void Service::requestLegendAdd(string name, char gender, int born, int death)
{
    Legend myNewLegend (name, gender, born, death);
    a.writeFile(myNewLegend);
}

/*Function requestComputerAdd, @parma int, string, char, bool and int
* calles the function writeComputerFile in the dataAccess class
*
*/
void Service::requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt,int index)
{
    Computer myNewComputer (name, yearBuilt, computerType, wasBuilt);
    a.writeComputerFile (myNewComputer, index);
}

/*Function requestRelationAdd, @parma int
* calles the function addRelation in the dataAccess class
*
*/
void Service::requestRelationAdd (int scientistID, int computerID)
{
    Relation myNewRelation (scientistID, computerID);
    a.addRelation (myNewRelation);
}

/*Function requestLegendEdit, @parma string, char, int and legend
*calles the function editLegend in the dataAccess class
*
*/
void Service::requestLegendEdit (string name, char gender, int born, int death, Legend oldLegend)
{
    Legend myEditedLegend (name, gender, born, death);
    a.editLegend(oldLegend, myEditedLegend);
}

/*Function requestComputerEdit, @parma string, int, bool and Computer
*calles the function editComputer in the dataAcess class
*
*/
void Service::requestComputerEdit (string name, int yearBuilt, string computerType, bool wasBuilt, Computer oldComputer, int index)
{
    Computer myEditedComputer (name, yearBuilt, computerType, wasBuilt);
    a.editComputer(oldComputer, myEditedComputer, index);
}

/*Function requestRelationEdit, @parma string and Relation
* calles the function editRelation in the dataAccess class
*
*/
void Service::requestRelationEdit (string scientistName, string computerName, Relation oldRelation)
{
    Relation myEditedRelation (scientistName, computerName);
    a.editRelation (oldRelation, myEditedRelation);
}


vector <Legend> Service::requestLegendSort()
{
    return a.sortLegend(_caseField, _ascDescOrder);
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
