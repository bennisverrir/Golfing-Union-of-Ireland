#include "Service.h"
Service::Service(){

}

void Service::setTableName (int command){
    if (command == 1){
        _tableName = "Scientists";
    } else if (command == 2){
        _tableName = "Computers";
    } else if (command == 3){
        _tableName = "Relations";
    }
}

void Service::setCaseField (int command){
    _caseField = command - 1;
}

void Service::setSearchField (string toSearch){
    _searchString = toSearch;
}

void Service::setSearchField (int toSearch){
    _searchString = to_string(toSearch);
}

void Service::setSearchField (char toSearch){
    string s(1,toSearch);
    _searchString = s;
}

void Service::setSearchField (bool toSearch){
    if (toSearch){
        _searchString = "1";
    } else {
        _searchString = "0";
    }
}
string Service::getTableName(){
    return _tableName;
}
int Service::getCaseField (){
    return _caseField;
}
string Service::getSearchField(){
    return _searchString;
}

vector <Legend> Service::requestLegendSearch(){
    vector <Legend> returnVector;
    returnVector = a.findLegend (_caseField, _searchString);

    return returnVector;
}

vector <Computer> Service::requestComputerSearch(){
    vector <Computer> returnVector;
    returnVector = a.findComputer (_caseField, _searchString);
    return returnVector;
}
vector <Relation> Service::requestRelationSearch(){
    vector <Relation> returnVector;
    bool myTempBool = true;
    returnVector = a.getRelation();
    return returnVector;
}

void Service::requestLegendAdd(string name, char gender, int born, int death){
    Legend myNewLegend (name, gender, born, death);
    bool myTempBool = true;
    a.writeFile(myNewLegend, myTempBool);
}

void Service::requestComputerAdd(string name, int yearBuilt, string computerType, bool wasBuilt,int index){
    Computer myNewComputer (name, yearBuilt, computerType, wasBuilt);
    bool myTempBool = true;
    a.writeComputerFile (myNewComputer, myTempBool, index);
}
void Service::requestRelationAdd (string scientistName, string computerName){

}

vector <Legend> Service::requestLegendSort(){

    return a.sortLegend(_caseField);
}
vector <Computer> Service::requestComputerSort(){

    return a.sortComputer(_caseField);
}
vector <string> Service::requestComputerTypes()
{
    return a.getComputerTypes();
}

void Service::requestComputerTypeAdd(string name)
{
    a.addComputerType(name);
}

