#ifndef COMPUTER_H
#define COMPUTER_H


#include <string>
using namespace std;

class Computer
{
public:
    Computer();

    /* Constructor without ID, used when adding a computer to the SQL
     * as ID is assigned in the SQL and not input by the user.
     */
    Computer(string name, int buildYear, string computerType, bool wasBuilt, string bio);

    /* Constructor with ID, used when retrieving a computer from SQL
     * as ID index has been assigned.
     */
    Computer (int iD, string name, int buildYear, string computerType, bool wasBuilt, string bio);

    // Set functions to set the different variables in the class.
    void setID(int ID);
    void setName(string);
    void setBuildYear(int);
    void setComputerType(string);
    void setWasBuilt(bool);
    void setBio(string);

    /* Get functions to get the value of the different
     * variables in the class
     */
    int getID();
    string getName() const;
    int getBuildYear() const;
    string getComputerType() const;
    bool getWasBuilt() const;
    string getBio() const;

private:
    // Private attributes of the class, used to identify the computer.
    string _name;
    int _buildYear;
    string _computerType;
    bool _wasBuilt;
    int _myID;
    string _bio;
};

#endif // COMPUTER_H
