#include "relation.h"


bool operator == (Relation &lhs, Relation &rhs)
{
    if(lhs._legendName == rhs._legendName && lhs._computerName == rhs._legendName)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
string Relation::getLegendName() const
{
    return _legendName;
}
string Relation::getComputerName()const
{
    return _computerName;
}
void Relation::setLegendName(string legendName)
{
    _legendName = legendName;
}
void Relation::setComputerName(string computerName)
{
    _computerName = computerName;
}

int Relation::getScientistID ()
{
    return _scientistID;
}

int Relation::getComputerID ()
{
    return _computerID;
}
