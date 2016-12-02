#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI(){}


/*function deleteLegend, @return void.
* reads input from user, if input matches a command it performs that command, if not outputs error.
* runs until the user inputs the quit command.
*/
void ConsoleUI::run()
{
    string keepGoing;

    do{

        displayCommands();
        string command;
        
        cin.clear();
        cin.sync();
        
        getline(cin, command);
        keepGoing = command;

    if (command == "list")
    {
        CommandList();
    }
    else if (command == "add")
    {
      commandAdd();
    }
    else if (command == "delete")
    {
        CommandDelete();
    }
    else if (command == "find")
    {
       CommandFind();
    }
    else if(command == "clear")
    {
        commandClear();
    }
    else if(command == "the answer to life")
    {
        fortyTwo();
    }
    else
    {
        if(keepGoing != "quit")
        {cout << "Invalid Command!" << endl;}
    }
    cout << endl;

    }while(keepGoing != "quit");
}

/*function displayCommands, @return void.
* displays a list of commands at the users disposal.
*/
void ConsoleUI::displayCommands()
{
    cout << "Please enter one of the following commands:"<< endl;
    cout << "list   - This will list all the computer scientists " << endl;
    cout << "add    - This will add a computer scientists " << endl;
    cout << "find   - This will find a computer scientists from the list" << endl;
    cout << "delete - This will delete a computer scientists from the list" << endl;
    cout << "clear  - this will clear the screen" << endl;
    cout << "quit   - This will quit the program" << endl;

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
/*function commandList, @return void.
*outputs a list of sorting catagories and their commands, then outputs that to the sort function.
*/
void ConsoleUI::CommandList()
{
    vector <Legend> legends = _service.getLegends();

    if(_service.getFileOpen())
    {
        char sortCommand;

        cout << "How do you want to sort"<< endl;
        cout << "a - Alphabetical order" << endl;
        cout << "g - Gender order" << endl;
        cout << "b - Year of birth order" << endl;
        cout << "l - Still alive order(those who are still alive appear first)" << endl;
        cout << "n - No particular sorting" << endl << endl;


        cout << endl;
        cin >> sortCommand;

        sort(sortCommand, legends);
    }
    else
    {
        cout << "Could not open file" << endl;
        exit(1);
    }
}
/*function sort, @param output from commmandListand vector Legend instance, @return void.
* sorts list of legends in a order according to what the user inputs in the commandList function.
*/
void ConsoleUI::sort(char command, vector<Legend>& legends)
{
   if(command == 'a') //Alphabetical order
   {
       cout << _service.getSort();
   }
   if(command == 'n') //no order
   {
       cout << legends;
   }
    if(command == 'g') //gender order
   {
   cout << _service.getSortGender();
   }
   if(command == 'b') //Date of birth order
   {
       cout << _service.getSortDateOfBirth(); 
   }
     if(command == 'l') //Still Alive order
   {
       cout << _service.getSortStillAlive();
   }

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
void ConsoleUI::CommandFind()
{
    cout << "Which parameter would you like to search for?" << endl;
    cout << "n - Name" << endl;
    cout << "g - Gender" << endl;
    cout << "b - Born (year)" << endl;
    cout << "d - Died (year)" << endl;

    char whatToFind;
    cin >> whatToFind;
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
}
/*function subCommandFind, @param an integer value, @return void.
* validates that the input from the user is an integer value.
*/
void ConsoleUI::subCommandFind(char command, vector <Legend> &toPrint)
{
    if (command == 'n')
    {
        string name;
        cout << "Enter a name to search for: ";
        
        cin.ignore();
        getline(cin,name);
        toPrint = _service.findLegend(name); // sends the input name into the search function
                                             // and assigns its value to the return value.
    } 
    else if (command == 'g')
    {
        char gender;
        cout << "Enter a gender to search for(M/F): ";
        cin >> gender;
        if (toupper (gender) == 'M'|| toupper(gender) == 'F')
        {
            toPrint = _service.findLegend(gender);           //sends in the input gender to the
        }                                                    //search function.
        else
        {
            cout << "Please enter a valid gender (M/F): ";
            subCommandFind (command, toPrint);
        }
    } 
    else if (command == 'b' || command == 'd')
    {
        int year;
        cout << "Enter a year to search for: (3 or 4 digits)";
        validateInput(year);
        if (command == 'b')
        {
            toPrint = _service.findLegend(year, true);
        }
        else        // sends year and if they are dead or not to the search function.
        {
            toPrint = _service.findLegend(year, false);
        }
    }
    else
    {
        cout << "Please enter a valid command (n/g/b/d)" << endl;
        CommandFind();
    }
}


string ConsoleUI::rightName(string name)       //makes sure the first letter in every name is uppercase
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
/*function deleteLegend, @param list index and Legend instance, @return void.
* Accepts the index of a legend from a sorted list of legends. If it returns
* multiple legends, it lets the user decide which legend you wan to delete.
*/
void ConsoleUI::CommandDelete()
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
}

void ConsoleUI::commandClear()
{
    system("cls"); // clears the screen
}
/*Function checkName @parm list: name, flag @return bool(true/false).
*Checks if the person is still alive, and errorchecks the input. 
*/
bool ConsoleUI::checkName(string name, bool flag)
{
    for(size_t i = 0; i < name.size(); i++)
    {
         if(isalpha(name[i]) || name[i] == ' ') //checking for a valid name
         {
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
            cout << "Please enter a valid name, only with letters" << endl;
        }

    }while(!flag);

    name = rightName(name);
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
        cout << "Enter the year of birth (3 or 4 digits): ";
        validateInput(born);

        if(born < 0 || born > 2016)
        {
             cout << "Please enter a valid year of birth" <<endl;
        }

    }while(born < 0 || born > 2016);

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
/*Function getDeath checks if the year @parm list: death @return void.
*Checks if the year of death is valid. 
*/
void ConsoleUI::getDeath(int &death, int born)
{
   if(checkIfDead())
   {
        do
        {
            cout << "Enter the year of death (3 or 4 digits): ";
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
    _service.addLegend(name, gender, born, death, valid);

    if(!valid)
    {
        cout << endl << "This person is already in the list" << endl;
    }
    else
    {
        cout << endl << "Legend Added!" << endl;
    }
}
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

