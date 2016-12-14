#ifndef LEGEND_H
#define LEGEND_H

#include <string>
using namespace std;

class Legend
{
public:
    Legend();

    /* Constructor without ID, used when adding a legend to the SQL
     * as ID is assigned in the SQL and not input by the user.
     */
    Legend (string name, char gender, int born, int death);

    /* Constructor with ID, used when retrieving a legend from SQL
     * as ID index has been assigned.
     */
    Legend (int iD,string name, char gender, int born, int death);

    // Set functions to set the different variables in the class.
    void setID (int iD);
    void setName(string);
    void setGender(char);
    void setBorn(int);
    void setDeath(int);

    /* Get functions to get the value of the different
     * variables in the class
     */
    int getID();
    string getName() const;
    char getGender() const;
    int getBorn() const;
    int getDeath() const;
    int getAge() const;
    int getDeathAge()const;

private:
    // Private attributes of the class, used to identify the legend.
    string _name;
    char _gender;
    int _born;
    int _death;
    int _myID;
};

#endif // LEGEND_H
