#include "consoleui.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "legend.h"

using namespace std;

ConsoleUI::ConsoleUI(){}

ostream& operator << (ostream& out,const vector<Legend>& rhs)
{
    cout << setw(30) << left << "Name" << setw(11) << "Gender" << setw(10) <<
            "Born" <<  setw(11) << " Died" << endl;
    for(int i = 0; i < 40; i++)
    {
        cout << "--";
    }
    cout << endl;

    for (size_t i = 0; i < rhs.size(); i++)
    {
        out << setw(30) << left << rhs[i].getName();
        out << setw(10) << rhs[i].getGender() << " ";
        out << setw(10) <<  rhs[i].getBorn() << " ";
        if(rhs[i].getDeath() != 0)
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


void ConsoleUI::sort(char command, vector<Legend>& legends)
{
   if(command == 'a')
   {
       cout << _service.getSort();
   }
   if(command == 'n')
   {
       cout << legends;
   }
    if(command == 'g')
   {
   cout << _service.getSortGender();
   }
   if(command == 'b')
   {
       cout << _service.getSortDateOfBirth();
   }
}

void ConsoleUI::CommandList()
{
    vector <Legend> legends = _service.getLegends();

    char sortCommand;

    cout << "How do you want to sort" << endl;
    cout << "a - Alphabetical order" << endl;
    cout << "n - No particular sorting" << endl;
    cout << "g - Gender order" << endl;
    cout << "b - Year of birth order" << endl;

    cout << endl;
    cin >> sortCommand;

    sort(sortCommand, legends);


}

void ConsoleUI::CommandFind()
{
    cout << "Please enter the string you want to search" <<": ";  
        string name;
        cin >> name;
        vector <Legend> toPrint = _service.findLegend(name);
        if(toPrint.size() > 0)
        {
            cout << toPrint;
        }
        else
        {
            cout << endl <<"No results from that query!" << endl;
        }
}

void ConsoleUI::CommandDelete()
{

}




void ConsoleUI::displayCommands()
{
    cout << "Please enter one of the following commands:"<< endl;
    cout << "list - This will list all the computer scientists " << endl;
    cout << "add - This will add a computer scientists " << endl;
    cout << "find - This will find a computer scientists from the list" << endl;
    cout << "delete - This will delete a computer scientists from the list" << endl;
    cout << "quit - This will quit the program" << endl;

    cout << endl;
}

bool ConsoleUI::checkName(string name, bool flag)
{
    for(size_t i = 0; i < name.size() && flag ;i++)
    {
         if(isalpha(name[i]) || isupper(name[i]) || name[i] == ' ') //checking for a valid name
         {
            flag = true;
         }
         else
         {
            flag = false;
         }
    }


    return flag;
}

string ConsoleUI::getName(string name)
{
    bool flag = true;

    do{
        cout << "Enter the name: ";
        cin.ignore();
        getline(cin,name);

        flag = checkName(name, flag);


        if(!flag)
        {
            cout << "Please enter a valid name, only with letters" << endl;
        }

    }while(!flag);

    return name;
}

void ConsoleUI::getGender(char &gender)
{
    do
    {
        cout << "Enter the gender: ";
        cin >> gender;

        gender = toupper(gender);

        if(gender != toupper('m') && gender != toupper('f'))
        {
            cout << "Please enter a valid gender";
        }

    }while(gender != toupper('m') && gender != toupper('f'));
}

void ConsoleUI::getBorn(int &born)
{
    do
    {
        cout << "Enter the year of birth: ";
        cin >> born;

        if(born < 0 || born > 2016)
        {
             cout << "Please enter a valid year of birth" <<endl;
        }

    }while(born < 0 || born > 2016);


}

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

void ConsoleUI::getDeath(int &death, int born)
{
   if(checkIfDead())
   {
        do
        {
            cout << "Enter the year of death: ";
            cin >> death;

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

void ConsoleUI::commandAdd()
{
    string name;
    char gender;
    int born;
    int death;


    name = getName(name);

    getGender(gender); //checking for a valid gender

    getBorn(born);

    getDeath(death, born);


    _service.addLegend(name, gender, born, death);
}

void ConsoleUI::run(){

    string keepGoing;

    do{

        displayCommands();

        string command;

        cin >> command;
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
    else
    {
        if(keepGoing != "quit")
        {cout << "Invalid Command!" << endl;}
    }
        


    cout << endl;

    }while(keepGoing != "quit");

}
