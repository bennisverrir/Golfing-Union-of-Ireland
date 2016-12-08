#ifndef LEGEND_H
#define LEGEND_H

#include <string>
using namespace std;

class Legend
{
public:
    Legend();
    Legend (string name, char gender, int born, int death);
    Legend (int iD,string name, char gender, int born, int death);

    friend bool operator == (Legend &lhs, Legend &rhs);
    void setID (int iD);
    void setName(string);
    void setGender(char);
    void setBorn(int);
    void setDeath(int);
    string getName() const;
    char getGender() const;
    int getBorn() const;
    int getDeath() const;
    int getAge() const;
    int getDeathAge()const;

private:
    string _name;
    char _gender;
    int _born;
    int _death;
    int _myID;
};

#endif // LEGEND_H
