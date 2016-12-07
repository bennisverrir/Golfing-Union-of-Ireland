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
Relation::Relation (string legendName, string computerName)
{
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
string Relation::setLegendName(string legendName)
{
    _legendName = legendName;
}
string Relation::setComputerName(string computerName)
{
    _computerName = computerName;
}