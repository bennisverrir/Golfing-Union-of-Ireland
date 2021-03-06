#include "computer.h"


Computer::Computer()
{

}
Computer::Computer(string name, int buildYear, string computerType, bool wasBuilt, string bio)
{
    setName(name);
    setBuildYear(buildYear);
    setComputerType(computerType);
    setWasBuilt(wasBuilt);
    setBio(bio);
}
Computer::Computer (int iD, string name, int buildYear, string computerType, bool wasBuilt, string bio)
{
    setID (iD);
    setName(name);
    setBuildYear(buildYear);
    setComputerType(computerType);
    setWasBuilt(wasBuilt);
    setBio(bio);
}
void Computer::setID(int ID)
{
    _myID = ID;
}

int Computer::getID()
{
    return _myID;
}

void Computer::setName(string name)
{
    _name = name;
}

void Computer::setBuildYear(int buildYear)
{
    _buildYear = buildYear;
}

void Computer::setComputerType(string computerType)
{
    _computerType = computerType;
}

void Computer::setWasBuilt(bool wasBuilt)
{
    _wasBuilt = wasBuilt;
}

void Computer::setBio(string bio)
{
    _bio = bio;
}



string Computer::getName() const
{
    return _name;
}
int Computer::getBuildYear() const
{
    return _buildYear;
}
string Computer::getComputerType() const
{
    return _computerType;
}
bool Computer::getWasBuilt() const
{
    return _wasBuilt;
}
string Computer::getBio() const
{
    return _bio;
}
