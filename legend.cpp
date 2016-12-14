#include "legend.h"


Legend::Legend()
{

}
Legend::Legend(string name, char gender, int born, int death)
{
    setName(name);
    setGender(gender);
    setBorn(born);
    setDeath(death);
}
Legend::Legend (int iD, string name, char gender, int born, int death)
{
    setID (iD);
    setName(name);
    setGender(gender);
    setBorn(born);
    setDeath(death);
}
void Legend::setID (int iD)
{
    _myID = iD;
}

void Legend::setName(string name)
{
    _name = name;
}

void Legend::setGender(char gender)
{
    _gender = gender;
}

void Legend::setBorn(int born)
{
    _born = born;
}

void Legend::setDeath(int death)
{
    _death = death;
}


int Legend::getID()
{
    return _myID;
}
string Legend::getName() const
{
    return _name;
}
char Legend::getGender() const
{
    return _gender;
}
int Legend::getBorn() const
{
    return _born;
}
int Legend::getDeath() const
{
    return _death;
}
int Legend::getDeathAge() const
{
    return getDeath()-getBorn();
}

int Legend::getAge() const
{
    return 2016-getBorn();
}
