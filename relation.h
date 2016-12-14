 #ifndef RELATION_H
#define RELATION_H

#include <string>
using namespace std;

class Relation
{
public:

    Relation();
    /* Constructor with ID's for the SQL which only utilizes the foreign keys
     * of the corresponding indexes
     */
    Relation (int scientistID, int computerID);

    //Constructor with combined ID's and names, utilized in editing relations
    Relation (int scientistID, int computerID, string legendName, string computerName);

    /* Constructor with names for the table, which only utilizes the names of
     * the computers and scientists/legends
     */
    Relation (string legendName, string computerName);

    // Set functions to set the different variables in the class.
    void setLegendName(string legendName);
    void setComputerName(string computerName);
    void setScientistID(int ID);
    void setComputerID(int ID);

    /* Get functions to get the value of the different
     * variables in the class
     */
    string getLegendName() const;
    string getComputerName()const;
    int getScientistID();
    int getComputerID();

private:
    // Private attributes of the class, used to identify the relation.
    int _scientistID;
    int _computerID;
    string _legendName;
    string _computerName;
};

#endif // RELATION_H
