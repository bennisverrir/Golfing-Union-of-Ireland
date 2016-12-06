#include "Service.h"
Service::Service(){

}

void Service::setTableName (int command){
    if (command == 1){
        _tableName = "Scientists";
    } else if (command == 2){
        _tableName = "Computers";
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

vector <Legend> Service::requestLegendSearch(){
    vector <Legend> returnVector;
    bool myTempBool = true;
    returnVector = a.findLegend (_caseField, _searchString, myTempBool);
}

vector <Computer> Service::requestComputerSearch(){
    vector <Computer> returnVector;
    bool myTempBool = true;
    //returnVector = a.findComputer (_caseField, _searchString, myTempbool);
    return returnVector;
}

void Service::requestLegendAdd(string name, char gender, int born, int death){
    Legend myNewLegend (name, gender, born, death);
    bool myTempBool = true;
    a.writeFile(myNewLegend, myTempBool);
}

void Service::requestComputerAdd(string name, int yearBuilt, int computerType, bool wasBuilt){
    Computer myNewComputer (name, yearBuilt, computerType, wasBuilt);
    bool myTempBool = true;
    a.writeComputerFile (myNewComputer, myTempBool);
}
vector <Legend> Service::requestLegendSort(){

    return a.sortLegend(_caseField);
}
