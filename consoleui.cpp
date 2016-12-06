#include "consoleui.h"

using namespace std;

/*function <<, @param instance of ostream and Legend vector instance, @return ostream.
* outputs all information about listed legends in a table.
*/
ostream& operator << (ostream& out,const vector<Legend>& rhs)
{
    out << endl;

    out << setw(7) << left <<  "No." << setw(30) << left << "Name" << setw(11) << "Gender" << setw(10) <<
            "Born" <<  setw(11) << " Died" << endl;
    for(int i = 0; i < 44; i++)
    {
        out << "--";
    }
    out << endl;

    for (size_t i = 0; i < rhs.size(); i++) //creating the output table
    {
        out << setw(7) << (i+1) << setw(30) << left << rhs[i].getName();
        out << setw(10) << rhs[i].getGender() << " ";
        out << setw(10) <<  rhs[i].getBorn() << " ";
        if(rhs[i].getDeath() != 0)                                      // output information about legend.
        {
            out << setw(10) << rhs[i].getDeath();
            out << setw(5) <<"Died " << rhs[i].getDeathAge() <<" years old";
        }
        else
        {
            out << setw(10) << "     " << rhs[i].getAge()<< " years old";
        }

        out << endl;
    }

    return out;
}
ostream& operator << (ostream& out,const vector<Computer>& rhs)
{
    out << endl;

   out << setw(7) << left <<  "No." << setw(30) << left << "Name" << setw(11) << "Build Year" << setw(5) <<" "<<
            "Computer Type"<<endl;
    for(int i = 0; i < 35; i++)
    {
        out << "--";
    }
    out << endl;

    for (size_t i = 0; i < rhs.size(); i++) //creating the output table
    {

        out << setw(7) << (i+1) << setw(30) << left << rhs[i].getName();
        if(rhs[i].getWasBuilt())
        {
            out << setw(10) << rhs[i].getBuildYear() << " ";
            if(rhs[i].getComputerType() == '1')                                      // output information about legend.
            {
                out << setw(5)<<" " << "Mechanical";
            }
            else if(rhs[i].getComputerType() == '2')
            {
                out << setw(5)<<" " << "Electrical";
            }
            else if(rhs[i].getComputerType() == '3')
            {
                out << setw(5)<<" " << "Transistor";
            }
             else if(rhs[i].getComputerType() == '4')
            {
                out << setw(5)<<" " << "Electromechnical";
            }
        }
        else
        {
            if(rhs[i].getComputerType() == '1')                                      // output information about legend.
            {
                out << setw(16)<<" " << "Mechanical";
            }
            else if(rhs[i].getComputerType() == '2')
            {
                out << setw(16)<<" " << "Electrical";
            }
            else if(rhs[i].getComputerType() == '3')
            {
                out << setw(16)<<" " << "Transistor";
            }
            else if(rhs[i].getComputerType() == '4')
            {
                out << setw(16)<<" " << "Electromechnical";
            }
        }
        out << endl;
    }

    return out;
}

ConsoleUI::ConsoleUI(){}


/*function deleteLegend, @return void.
* reads input from user, if input matches a command it performs that command, if not outputs error.
* runs until the user inputs the quit command.
*/
void ConsoleUI::run()
{
    int command, command2;

    do{

        displayCommands();

        cin >> command;

        if (command == 1)
        {

            do
            {
                cout << "Enter one of the following commands:" << endl;
                cout << "[1] - to list all the scientists" << endl;
                cout << "[2] - to list all the computers" << endl;

                cin >> command2;
                _service.setTableName(command2);

                if(command2 == 1)
                { 
                    commandList();
                }
                else if(command2 == 2)
                {
                    //commandListComputers();
                }
                else
                {
                    cout << "please enter a valid command" << endl;
                }
                
              }while(command2 != 1 && command2 != 2);
         }   
    else if (command == 2)
    {
        int command3;
            do{
             cout << "Enter one of the following commands:" << endl;
             cout << "[1] - to add a scientist" << endl;
             cout << "[2] - to add a command" << endl;

             cin >> command3;
             _service.setTableName(command3);
            if(command3 == 1)
            {
                commandAdd();
            }
            else if(command3 == 2)
            {
                commandAddComputer();
            }
            else
            {
                cout << "please enter a valid command" << endl;
            }
            }while(command3 != 1 && command3 != 2);
    }

    else if (command == 4)
    {
        //commandDelete();
    }
     else if (command == 3)
    {
        int command4;
          do{
             cout << "Enter one of the following commands:" << endl;
             cout << "1 - to find a scientist" << endl;
             cout << "2 - to find a computer" << endl;

             cin >> command4;
             _service.setTableName(command4);
                if(command4 == 1)
                {
                    commandFind();
                }
                else if(command4 == 2)
                {
                    //TODO: Find fyrir gombuter
                }
                else
                {
                    cout << "please enter a valid command" << endl;
                }
                }while(command4 != 1 && command4 != 2);
    }
    else if(command == 5)
    {
        commandClear();
    }
    else if(command == 42)
    {
        fortyTwo();
    }
    else if(command == 999)
    {
       // _service.requestComputerAdd("Gervinho", 1000, 3, 1);
    }
    else
    {
        if(command != 6)
        {cout << "Invalid Command!" << endl;}
    }
    cout << endl;

    }while(command != 6);
}

/*function displayCommands, @return void.
* displays a list of commands at the users disposal.
*/
void ConsoleUI::displayCommands()
{
    cout << "Please enter one of the following numbers:"<< endl;
    cout << "[1]   - To list all the computer scientists or computers" << endl;
    cout << "[2]    - To add a computer scientist or a computer " << endl;
    cout << "[3]   - To find a computer scientist from the list or a computer" << endl;
    cout << "[4] - This will delete a computer scientists from the list" << endl;
    cout << "[5]  - this will clear the screen" << endl;
    cout << "[6]   - This will quit the program" << endl;

    cout << endl;
}

/*function commandList, @return void.
*outputs a list of sorting catagories and their commands, then outputs that to the sort function.
*/
void ConsoleUI::commandList()
{
    int sortCommand;

    cout << "How do you want to sort"<< endl;
    cout << "[1] - Alphabetical order" << endl;
    cout << "[2] - Gender order" << endl;
    cout << "[3] - Year of birth order" << endl;
    cout << "[4] - Still alive order(those who are still alive appear first)" << endl;
    cout << "[5] - No particular sorting" << endl << endl;

    cin >> sortCommand;
    _service.setCaseField(sortCommand);

    //sort(sortCommand);
    cout << _service.requestLegendSort();


}

/*Function commandAdd checks if the year @parm list: gender, born, death, valid @return void.
This function checks if the input name is valid, if it is already in the list.
*/
void ConsoleUI::commandAdd()
{
    string name;
    char gender;
    int born;
    int death;
    bool valid;

    name = getName(name);
    getGender(gender); //checking for a valid gender
    getBorn(born);
    getDeath(death, born);
    _service.requestLegendAdd(name, gender, born, death);

    cout << endl << "Legend Added!" << endl;
}

/*Function getName @parm list: name, flag. @return name.
*Takes the input name and checks if it is valid.
*/
string ConsoleUI::getName(string name)
{
    bool flag = true;

    do
    {
        cout << "Enter the name: ";

        getline(cin,name);

        flag = checkName(name, flag);
        if(!flag)
        {
            cout << "Please enter a valid name" << endl;
        }

    }while(!flag);

    name = rightName(name);
    return name;
}

/*Function checkName @parm list: name, flag @return bool(true/false).
*Checks if the person is still alive, and errorchecks the input.
*/
bool ConsoleUI::checkName(string name, bool flag)
{
    for(size_t i = 0; i < name.size(); i++)
    {
         if(isalpha(name[i]) || name[i] == ' ' || name[i] == '.' || name[i] == '-') //checking for a valid name
         {
            if((name[i] == '.' && ((name[i] == name[i-1] ) || name[i-1] == '-')) && ((name[i] == '-' && ((name[i] == name[i-1] ) || name[i-1] == '.'))))
            {
                flag = false;
                break;
            }

            flag = true;
         }
         else
         {
            flag = false;
            break;
         }
    }


    return flag;
}

/*  function rightName @param string name, @return string
 *  Converts name so that every name starts with a upper case letter and all other letters are lower case;
 */
string ConsoleUI::rightName(string name)
{
    name[0] = toupper(name[0]);

    for(size_t i = 0; i < name.size(); i++)
    {
        if(name[i] == ' ' && i != (name.size() - 1u))
        {
            name[i+1] = toupper(name[i+1]);
        }
        else
        {
            name[i+1] = tolower(name[i+1]);
        }
    }

    return name;
}

/*Function getGender @parm list: gender @return void.
*This function takes the gender input. And checks if it is valid.
*/
void ConsoleUI::getGender(char &gender)
{
    do
    {
        cout << "Enter the gender (M/F): ";
        cin >> gender;

        gender = toupper(gender);

        if(gender != toupper('m') && gender != toupper('f'))
        {
            cout << "Please enter a valid gender" << endl;
        }

    }while(gender != toupper('m') && gender != toupper('f'));
}

/*Function getBorn @parm list: born @return void.
*This function takes in the year of birth, and checks if it is valid.
*/
void ConsoleUI::getBorn(int &born)
{
    do
    {
        cout << "Enter the year of birth (up to 4 digits): ";
        validateInput(born);

        if(born < 0 || born > 2016)
        {
             cout << "Please enter a valid year of birth" <<endl;
        }

    }while(born < 0 || born > 2016);

}

/*function validateInput, @param an integer value, @return void.
* validates that the input from the user is an integer value.
*/
void ConsoleUI::validateInput(int &intValue)
{
    cin >> intValue;
    while (cin.fail())      // runs if input is not an integer value
    {
        cout <<endl<< "Please enter a valid input" << endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        cin >> intValue;
    }
}

/*Function getDeath checks if the year @parm list: death @return void.
*Checks if the year of death is valid.
*/
void ConsoleUI::getDeath(int &death, int born)
{
   if(checkIfDead())
   {
        do
        {
            cout << "Enter the year of death (up to 4 digits): ";
            validateInput(death);

            if(death < born || death > 2016)
            {
                cout << "Please enter a valid year of death" << endl;
            }

        }while(death < born || death > 2016);
    }
    else
   {
       death = 0;
   }
}

/*Function checkIfDead @parm list: command @return bool(true/false).
*Checks if the person is still alive, and errorchecks the input.
*/
bool ConsoleUI::checkIfDead()
{
    char command = ' ';

    while(command != toupper('y') && command != toupper('n'))
    {
        cout << "Are they alive (y/n)? ";

        cin >> command;

        command = toupper(command);

        if(command != toupper('y') && command != toupper('n'))
        {
            cout << "Please enter a valid command" << endl;
        }
    }

    if(command == toupper('y'))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * function CommandDelete, @return void.
* Calls find function to match search string, deletes person from that list based on index input
*
*/

/*void ConsoleUI::commandDelete()
{
    string deleteName;

    cout << "Who do you want to delete (press enter to get the full list)?  ";

    getline(cin,deleteName);

    deleteName = rightName(deleteName);

    vector<Legend> deleteLegend = _service.findLegend(deleteName);



    if(deleteLegend.size() > 0)
    {
        cout << deleteLegend;
        cout << "What number do you want to delete? ";

        int number;
        validateInput(number);
        int max = _service.findLegend(deleteName).size();


        if(number<1|| number>max)
        {
           cout<<endl<< "Invalid number!"<<endl;
        }
        else
        {
        _service.deleteLegend(number, deleteLegend); // deletes the legend


        cout << endl << "The line has been deleted" << endl;
        }
    }
    else
    {
        cout << endl <<"No results from that query!" << endl;
    }
}*/

/*function commandFind, @return void
 *asks the user what he wants to search and then calls subCommandFind and passes in a vector.
 *Then prints out the vector from subCommandFind
 */
void ConsoleUI::commandFind()
{
    cout << "Which parameter would you like to search for?" << endl;
    cout << "[1] - Name" << endl;
    cout << "[2] - Gender" << endl;
    cout << "[3] - Born (year)" << endl;
    cout << "[4] - Died (year)" << endl;
    int whatToFind;
    cin >> whatToFind;
    _service.setCaseField(whatToFind);
    vector <Legend> toPrint = _service.requestLegendSearch();

    subCommandFind (whatToFind, toPrint);
    if(toPrint.size() > 0)
    {
        cout << toPrint;
    }
    else
    {
        cout << endl <<"No results from that query!" << endl;
    }
}

/*function subCommandFind, @param an integer value, @return void.
* validates that the input from the user is an integer value.
*/
void ConsoleUI::subCommandFind(int command, vector <Legend> &toPrint)
{
    if (command == 1)
    {
        string name;
        cout << "Enter a name to search for: ";
        
        cin.ignore();
        getline(cin,name);

        name = rightName(name);
        _service.setSearchField (name);

        toPrint = _service.requestLegendSearch(); // sends the input name into the search function
                                             // and assigns its value to the return value.

    } 
    else if (command == 2)
    {
        char gender;
        cout << "Enter a gender to search for(M/F): ";
        cin >> gender;
        if (toupper (gender) == 'M'|| toupper(gender) == 'F')
        {
            _service.setSearchField(gender);
            toPrint = _service.requestLegendSearch();           //sends in the input gender to the
                                                             //search function.

        }

        else
        {
            cout << "Please enter a valid gender (M/F): ";
            subCommandFind (command, toPrint);
        }
    } 
    else if (command == 3 || command == 4)
    {
        int year;
        cout << "Enter a year to search for: (3 or 4 digits)";
        validateInput(year);
        _service.setSearchField(year);
        toPrint = _service.requestLegendSearch();

    }
    else
    {
        cout << "Please enter a valid command (n/g/b/d)" << endl;
        commandFind();
    }
}

/*function commandClear, @return void
 * Clears the screen
 */
void ConsoleUI::commandClear()
{
    system("cls"); // clears the screen
}

void ConsoleUI::commandAddComputer()
{
    string computerName;
    int buildYear;
    char computerType;
    bool wasBuilt;
  //  bool valid;

    computerName = getName(computerName);
}
    /*getBuildYear(buildYear);
    getComputerType(computerType);
    wasBuilt = getWasBuilt(wasBuilt);
  //  _service.addComputer(computerName, buildYear, computerType, wasBuilt);
}
    if(!valid)
    {
        cout << endl << "This Computer is already in the list" << endl;
    }
    else
    {
        cout << endl << "Computer Added!" << endl;
    }
}

*/


/*
void ConsoleUI::commandListComputers()
{
   vector <Computer> computers = _service.getComputers();



    char sortComputerCommand;

    cout << "How do you want to sort"<< endl;
    cout << "[1] - Alphabetical order" << endl;
    cout << "[2] - Built year order" << endl;
    cout << "[3] - Was built" << endl;
    cout << "[4] - Type of computer order" << endl;
    cout << "[5] - No particular sorting" << endl << endl;

    cin >> sortComputerCommand;

   //sortComputer(sortComputerCommand, computers);


}
/*function fortyTwo, @return void
 *prints out the answer to life the universe and evertything
 */
void ConsoleUI::fortyTwo()
{

    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;  
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@@@         `@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@              @@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@                @@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@          @@@@@@@@@@@@                  @@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@@@                    @@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@@        @@@@        @@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@       @@@@@@@@       @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@      @@@@@@@@@@      @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@       @      @@@@@@@@@@      @@@@@@@@@@      @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@       @@      @@@@@@@@@@      @@@@@@@@@@      @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@       @@      @@@@@@@@@@      @@@@@@@@@@       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@       @@@      @@@@@@@@@@      @@@@@@@@@@       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@       @@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@       @@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@        @@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@       @@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@       @@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@       @@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@       @@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@       @@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@        @@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@       @@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@       @@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@       @@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@       @@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@@@@@@@@        @@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@@@@@@@        @@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@                             @@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@          @@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@                       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@                       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@                       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@                       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@                       @@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;


}



