#include "consoleui.h"

using namespace std;

/*function displayCommands, @return void.
* displays a list of commands at the users disposal.
*/
void ConsoleUI::displayCommands()
{
    cout << endl;
    cout << "Please enter one of the following numbers:"<< endl;
    cout << "[1] - To list all the computer scientists or computers" << endl;
    cout << "[2] - To add a computer scientist or a computer " << endl;
    cout << "[3] - To find a computer scientist from the list or a computer" << endl;
    cout << "[4] - This will delete a computer scientists from the list" << endl;
    cout << "[5] - this will clear the screen" << endl;
    cout << "[6] - This will quit the program" << endl;

    cout << endl;
}

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

   out << setw(7) << left <<  "No." << setw(30) << left << "Name" << setw(11) << "Build Year" << setw(5) << " " <<
            "Computer Type" << endl;
    for(int i = 0; i < 35; i++)
    {
        out << "--";
    }
    out << endl;

    for (size_t i = 0; i < rhs.size(); i++) //creating the output table
    {

        out << setw(7) << (i+1) << setw(30) << left << rhs[i].getName();

        if(rhs[i].getBuildYear() != 0)
        {
            out << setw(10) << rhs[i].getBuildYear() << setw(6) << " ";
        }
        else
        {
            out << setw(10) << "    " << setw(6) << " ";
        }
        out << setw(5) << rhs[i].getComputerType() ;

        out << endl;
    }

    return out;
}

ostream& operator << (ostream& out, const vector<string>& rhs)
{
    out << setw(7) << left << "No." << setw(30) << left << "Type" << endl;

    for(int i = 0; i < 20; i++)
    {
        out << "--";
    }

    out << endl << setw(7) << "0" << setw(30) << "Add a computerType";


    out << endl;

    for(size_t i = 0; i < rhs.size(); i++)
    {
        out << setw(7) << (i+1) << setw(30) << rhs[i] << endl;
    }

    return out;
}

ostream& operator << (ostream& out, const vector<Relation>& rhs)
{
    out << endl << setw(7) << left << "No." << setw(30) << left << "Name" << setw(10) << "Computer Name"  << endl;

    for(int i = 0; i < 40; i++)
    {
        out << "--";
    }
    out << endl;

    for(size_t i = 0; i < rhs.size(); i++)
    {
        out << setw(7) << (i+1) << setw(30) << rhs[i].getLegendName() << setw(10) << rhs[i].getComputerName() << endl;
    }

    out << endl;

    return out;
}


ConsoleUI::ConsoleUI(){}


/*function deleteLegend, @return void.
* reads input from user, if input matches a command it performs that command, if not outputs error.
* runs until the user inputs the quit command.
*/
void ConsoleUI::run()
{
    int command = 0;
    int subCommand = 0;
    while(command != 6)
    {
        displayCommands();
        _numOfChoices = 6;

        validateCommand(command);

        switch(command)
        {
            case 1:
                coutChoice(command);

                _numOfChoices = 2;

                validateCommand(subCommand);

                if(subCommand == 1)
                {
                    commandListScientists();
                }
                else if(subCommand == 2)
                {
                    commandListComputers();
                }
                else if(subCommand == 3)
                {
                    cout << _service.requestRelationSearch();
                }

            break;

            case 2:
                coutChoice(command);

                _numOfChoices = 2;

                validateCommand(subCommand);

                if(subCommand == 1)
                {
                    commandAddScientist();
                }
                else if(subCommand == 2)
                {
                    commandAddComputer();
                }

            break;

            case 3:
                coutChoice(command);

                _numOfChoices = 2;

                validateCommand(subCommand);

                if(subCommand == 1)
                {
                    commandFindScientist();
                }
                else if(subCommand == 2)
                {
                    commandFindComputer();
                }
            break;

            case 4:
                coutChoice(command);

                _numOfChoices = 2;

                validateCommand(subCommand);

                if(subCommand == 1)
                {
                    commandEditScientist();
                }
                else if(subCommand == 2)
                {
                    //commandEditComputer();
                }
            break;

            case 5:
                commandClear();
            break;

            case 6:
                exit(1);
            break;

            case 42:
                fortyTwo();
            break;
        }
    }
}//BUINN
void ConsoleUI::validateCommand(int &command)
{
    cin >> command;

    while (cin.fail() || ( command > _numOfChoices  && command < 0))
    {
        cout << endl << "Please enter a valid input" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> command;
    }
}

void ConsoleUI::validateYear (int begin, int &input)
{
    cin >> input;
    while (cin.fail() || (input < begin || input >_currentYear)){
        cout << endl << "Please enter a valid input." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
    }
}

void ConsoleUI::coutChoice(int command)
{  
    string com = " ";

    switch(command)
    {
        case 1:
            com = "list";
        break;

        case 2:
            com = "add";
        break;

        case 3:
            com = "find";
        break;

        case 4:
            com = "edit";
        break;
    }
    cout << "Enter one of the following commands:" << endl;
    cout << "[1] - to " << com << " scientists" << endl;
    cout << "[2] - to " << com << " computers" << endl;
    cout << "[3] - to " << com << " relations" << endl;

}
//buinn

/*function commandList, @return void.
*outputs a list of sorting catagories and their commands, then outputs that to the sort function.
*/
void ConsoleUI::commandListScientists()
{
    int sortCommand;

    cout << "How do you want to sort"<< endl;
    cout << "[1] - Alphabetical order" << endl;
    cout << "[2] - Gender order" << endl;
    cout << "[3] - Year of birth order" << endl;
    cout << "[4] - Still alive order(those who are still alive appear first)" << endl;
    cout << "[5] - No particular sorting" << endl << endl;

    _numOfChoices = 5;
    validateCommand(sortCommand);

    ascDesc();


    _service.setCaseField(sortCommand);
    cout << _service.requestLegendSort();

}
//buinn
void ConsoleUI::ascDesc()
{
    int ascDesc;

    cout << "Do you want it:" << endl;
    cout << "[1] - Ascending" << endl;
    cout << "[2] - Descending"  << endl;

    _numOfChoices = 2;
    validateCommand(ascDesc);

    _service.setAscDescOrder(ascDesc);
}
//buinn
/*Function commandAdd checks if the year @parm list: gender, born, death, valid @return void.
This function checks if the input name is valid, if it is already in the list.
*/
void ConsoleUI::commandAddScientist()
{
    string name;
    char gender;
    int born;
    int death;

    getName(name);
    getGender(gender);             //checking for a valid gender
    getBorn(born);

    getDeath(death, born);

    _service.requestLegendAdd(name, gender, born, death);
    cout << endl << "Scientist Added!" << endl << endl;
}
/*Function getName @parm list: name, flag. @return name.
*Takes the input name and checks if it is valid.
*/
void ConsoleUI::getName(string &name)
{
    bool flag = true;
    do
    {
        cout << "Enter the name: ";
        cin.ignore();
        getline(cin,name);
        flag = checkName(name, flag);
        if(!flag)
        {
            cout << "Please enter a valid name" << endl;
        }
    }while(!flag);
    name = rightName(name);
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
        cout << "Enter the gender (M/F): ";
        validateGender(gender);
}

/*Function getBorn @parm list: born @return void.
*This function takes in the year of birth, and checks if it is valid.
*/
void ConsoleUI::getBorn(int &born)
{
        cout << "Enter the year of birth (up to 4 digits): ";
        validateYear(0, born);
}//buinn

/*Function getDeath checks if the year @parm list: death @return void.
*Checks if the year of death is valid.
*/
void ConsoleUI::getDeath(int &death, int born)
{
   if(checkIfDead())
   {
       cout << "Enter the year of death (up to 4 digits): ";
       validateYear(born, death);
   }
   else
   {
       death = 0;
   }
}//buinn

/*Function checkIfDead @parm list: command @return bool(true/false).
*Checks if the person is still alive, and errorchecks the input.
*/
bool ConsoleUI::checkIfDead()
{
    char command = ' ';

    cout << "Are they alive (Y/N)? ";

    validateInputYN(command);

    if(command == toupper('y'))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void ConsoleUI::commandFindScientist()
{
    cout << "Which parameter would you like to search for?" << endl;
    cout << "[1] - Name" << endl;
    cout << "[2] - Gender" << endl;
    cout << "[3] - Born (year)" << endl;
    cout << "[4] - Died (year)" << endl;

    int whatToFind;
    validateCommand(whatToFind);

    _service.setCaseField(whatToFind);
    vector <Legend> toPrint;

    subCommandFind (whatToFind, toPrint);
    if(toPrint.size() > 0)
    {
        cout << toPrint;
    }
    else
    {
        cout << endl <<"No results from that query!" << endl;
    }
}//buinn



/*function subCommandFind, @param an integer value, @return void.
* validates that the input from the user is an integer value.
*/
void ConsoleUI::subCommandFind(int command, vector <Legend> &toPrint)
{
    switch(command)
    {
        case 1:
        {
            string name;
            cout << "Enter a name to search for: ";

            cin.ignore();
            getline(cin,name);

            name = rightName(name);
            _service.setSearchField (name);

            toPrint = _service.requestLegendSearch();

            break;
        }
        case 2:
        {
            char gender;
            cout << "Enter a gender to search for(M/F): ";
            cin >> gender;
            validateGender(gender);
            _service.setSearchField(gender);
            toPrint = _service.requestLegendSearch();

            break;
        }
        case 3:
        {
            int born = 0;
            cout << "Enter a year to search for: (3 or 4 digits): ";
            validateYear(0,born);

            _service.setSearchField(born);
            toPrint = _service.requestLegendSearch();

            break;
        }
        case 4:
        {
            int death = 0;

            cout << "Enter a year to search for: (3 or 4 digits): ";
            validateYear(0, death);

            _service.setSearchField(death);
            toPrint = _service.requestLegendSearch();

            break;
        }
    }
}//buinn

void ConsoleUI::commandFindComputer()
{
    string name;

    cout << "Which parameter would you like to search for?" << endl;
    cout << "[1] - Name" << endl;
    cout << "[2] - Build (year)" << endl;
    cout << "[3] - Type" << endl;

   /* commandListComputerTypes();

    cout << "Enter Computer Type(0-" << _service.requestComputerTypes().size() << "): ";*/
    int whatToFind;
    validateCommand(whatToFind);

    _service.setCaseField(1);
    //cout << "What to search? "<<endl;

    _service.setCaseField(whatToFind);
    vector <Computer> toPrint;

    subCommandFindComputer(whatToFind, toPrint);
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
void ConsoleUI::subCommandFindComputer(int command, vector <Computer> &toPrint)
{
    switch(command)
    {
        case 1:
        {
            string name;
            cout << "Enter a name to search for: ";

            cin.ignore();
            getline(cin,name);

            name = rightName(name);
            _service.setSearchField (name);

            toPrint = _service.requestComputerSearch();

            break;
        }
        case 2:
        {
            int buildYear;
            cout << "Enter a year to search for: (4 digits):";
            validateYear(0,buildYear);

            _service.setSearchField(buildYear);
            toPrint = _service.requestComputerSearch();

            break;
        }
        case 3:
        {
            int computerType = 0;
            cout << "Enter a type to search for(1-"<< _service.requestComputerTypes().size() << "): ";
            commandListComputerTypes();
            cin >> computerType;

            _service.setCaseField(computerType);
            _service.setSearchField(_service.requestComputerTypes()[computerType-1]);
            toPrint = _service.requestComputerSearch();

            break;
        }
    }
}//buinn


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
    string scientistName;
    int buildYear;
    int index = 0;
    string computerType;
    bool wasBuilt;
    char built;

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin,computerName);

    cout << "was it built (Y/N): ";

    validateInputYN(built);
    if(built == toupper('y'))
    {
        cout << "Year of build (4 digits): ";
        validateYear(0, buildYear);
    }

    commandListComputerTypes();

    cout << "Enter Computer Type(0-" << _service.requestComputerTypes().size() << "): ";

    cin >> index;

    if(index == 0)
    {
        addComputerType();
        index = _service.requestComputerTypes().size();
    }

    char yesNo;

    _service.requestComputerAdd(computerName, buildYear, computerType, wasBuilt, index);

    do
    {
        cout << "Add relation (Y/N): ";
        validateInputYN(yesNo);
        if(yesNo == 'Y')
        {
            int indexCommand;
            _service.setCaseField(1);
            vector<Legend> print = _service.requestLegendSort();
            cout << print;
            cout << "Relation (1-"<<_service.requestLegendSort().size() <<"): ";
            cin >> indexCommand;

            scientistName = print[indexCommand-1].getName();
            _service.requestRelationAdd(scientistName, computerName);
        }
    }while(yesNo != 'N');
}
void ConsoleUI::commandListComputers()
{
    int command;

    cout << "How do you want to sort"<< endl;
    cout << "[1] - Alphabetical order" << endl;
    cout << "[2] - Built year order" << endl;
    cout << "[3] - Was built" << endl;
    cout << "[4] - Type of computer order" << endl;
    cout << "[5] - No particular sorting" << endl << endl;

    _numOfChoices = 5;
    validateCommand(command);

    ascDesc();

    _service.setCaseField(command);

    cout << _service.requestComputerSort();


}

void ConsoleUI::commandEditScientist()
{
    int index = 0;
    string name;
    char gender;
    int born = 0;
    int death = 0;

    commandFindScientist();

    cout << "Who do you want to edit? ";
    cin >> index;

    Legend oldLegend =  _service.requestLegendSearch()[index-1];

    cout << "Old Name: " << oldLegend.getName() << endl;
    cout << "New Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Old gender: " << oldLegend.getGender() << endl;
    cout << "New gender: ";
    cin >> gender;
    cout << "Old birth Year: " << oldLegend.getBorn() << endl;
    cout << "New birth Year: ";
    validateYear(0, born);
    cout << "Old death year: " << oldLegend.getDeath() << endl;
    cout << "New death year: ";
    validateYear(born,death);

    cout << endl;
    
    _service.requestLegendEdit(name, toupper(gender), born, death, oldLegend);
}

void ConsoleUI::commandEditComputer()
{
    int index = 0;
    string name;;
    bool wasBuilt;
    int buildYear;
    string type;

    commandFindComputer();

    cout << "Who do you want to edit? ";
    cin >> index;

    Computer oldComputer =  _service.requestComputerSearch()[index-1];

    cout << "Old Name: " << oldComputer.getName() << endl;
    cout << "New Name: ";

    cin.ignore();
    getline(cin, name);
    cout << "Old was Built: " << oldComputer.getWasBuilt() << endl;
    cout << "New was built: ";
    cin >> wasBuilt;
    cout << "Old built Year: " << oldComputer.getBuildYear() << endl;
    cout << "New built Year: ";
    cin >> buildYear;
    cout << "Old computer type: " << oldComputer.getComputerType() << endl;
    cout << "New computer type: ";
    cin >> type;

    cout << endl;

    _service.requestComputerEdit(name, buildYear, type, wasBuilt, oldComputer);
}
void ConsoleUI::commandListComputerTypes()
{
    cout << _service.requestComputerTypes();
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

void ConsoleUI::addComputerType()
{
    string name;

    cout << "Name of ComputerType? ";

    cin.ignore();
    getline(cin, name);

    _service.requestComputerTypeAdd(name);
}

void ConsoleUI::validateGender(char &gender)
{
    do
    {
        cin >> gender;
        cin.clear();
        gender = toupper(gender);

        if(gender != toupper('m') && gender != toupper('f'))
        {
            cout << "Please enter a valid gender" << endl;
        }

    }while(gender != toupper('m') && gender != toupper('f'));
}

void ConsoleUI::validateInputYN(char &toValidate)
{
    cin >> toValidate;
    toValidate = toupper(toValidate);
    while (cin.fail() || (toValidate != 'Y' && toValidate != 'N'))
    {
        cout <<endl<< "Please enter (Y/N) :";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        cin >> toValidate;
    }
}
