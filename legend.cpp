#include "legend.h"


Legend::Legend()
{

}
Legend::Legend(string name, char gender, int born, int death, string bio)
{
    setName(name);
    setGender(gender);
    setBorn(born);
    setDeath(death);
    setBio(bio);
}
Legend::Legend (int iD, string name, char gender, int born, int death, string bio)
{
    setID (iD);
    setName(name);
    setGender(gender);
    setBorn(born);
    setDeath(death);
    setBio(bio);
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

void Legend::setBio(string bio)
{
    _bio = bio;
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

string Legend::getBio() const
{
    return _bio;
}

int Legend::getAge() const
{
    return 2016-getBorn();
}
