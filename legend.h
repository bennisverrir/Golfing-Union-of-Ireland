#ifndef LEGEND_H
#define LEGEND_H

#include <string>
using namespace std;


class Legend
{
public:
    Legend();
    Legend(string name, char gender, int born, int death);




    void setName(string);
    void setGender(char);
    void setBorn(int);
    void setDeath(int);
    string getName() const;
    char getGender() const;
    int getBorn() const;
    int getDeath() const;




private:
    string _name;
    char _gender;
    int _born;
    int _death;
};

#endif // LEGEND_H
