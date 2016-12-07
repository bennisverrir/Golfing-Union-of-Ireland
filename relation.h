#ifndef RELATION_H
#define RELATION_H

#include <string>
using namespace std;

class Relation
{
public:
    Relation();
    Relation (string legendName, string computerName);

    friend bool operator == (Relation &lhs, Relation &rhs);
    string getLegendName() const;
    string getComputerName()const;
    string setLegendName(string legendName);
    string setComputerName(string computerName);

private:
    string _legendName;
    string _computerName;
};

#endif // RELATION_H
