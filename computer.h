#ifndef COMPUTER_H
#define COMPUTER_H


#include <string>
using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int buildYear, string computerType, bool wasBuilt);
    Computer (int iD, string name, int buildYear, string computerType, bool wasBuilt);

    friend bool operator == (Computer &lhs, Computer &rhs);
    int getID();
    void setID(int ID);
    void setName(string);
    void setBuildYear(int);
    void setComputerType(string);
    void setWasBuilt(bool);
    string getName() const;
    int getBuildYear() const;
    string getComputerType() const;
    bool getWasBuilt() const;

private:
    string _name;
    int _buildYear;
    string _computerType;
    bool _wasBuilt;
    int _myID;
};

#endif // COMPUTER_H
