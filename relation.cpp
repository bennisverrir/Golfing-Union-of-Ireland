#include "relation.h"

Relation::Relation()
{

}
Relation::Relation (int scientistID, int computerID, string legendName, string computerName)
{
    _scientistID = scientistID;
    _computerID = computerID;
    _legendName = legendName;
    _computerName = computerName;
}
Relation::Relation (int scientistID, int computerID)
{
    _scientistID = scientistID;
    _computerID = computerID;
}
Relation::Relation (string legendName, string computerName)
{
    _scientistID = 0;
    _computerID = 0;
    _legendName = legendName;
    _computerName = computerName;
}

void Relation::setLegendName(string legendName)
{
    _legendName = legendName;
}
void Relation::setComputerName(string computerName)
{
    _computerName = computerName;
}
void Relation::setScientistID (int ID)
{
    _scientistID = ID;
}

void Relation::setComputerID (int ID)
{
    _computerID = ID;
}

string Relation::getLegendName() const
{
    return _legendName;
}
string Relation::getComputerName()const
{
    return _computerName;
}
int Relation::getScientistID ()
{
    return _scientistID;
}

int Relation::getComputerID ()
{
    return _computerID;
}


