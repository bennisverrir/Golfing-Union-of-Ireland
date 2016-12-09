#include "Service.h"
Service::Service()
{

}

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

void Service::setCaseField (int command)
{
    _caseField = command - 1;

}

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

vector <Legend> Service::requestLegendSort()
{
    return a.sortLegend(_caseField, _ascDescOrder);
}

vector <Computer> Service::requestComputerSort()
{
    return a.sortComputer(_caseField, _ascDescOrder);
}
vector <Relation> Service::requestRelationSort()
{
    return a.sortRelation(_caseField, _ascDescOrder);
}

vector <string> Service::requestComputerTypes()
{
    return a.getComputerTypes();
}

void Service::requestComputerTypeAdd(string name)
{
    a.addComputerType(name);
}

vector<Relation> Service::findRelation(string name)
{
    return a.findRelation(name);
}

