#include "consoleui.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "legend.h"

using namespace std;

ostream& operator << (ostream& out,const vector<Legend>& rhs)
{
    for (size_t i = 0; i < rhs.size(); i++)
    {
        out << rhs[i].getName() << " ";
        out << rhs[i].getGender() << " ";
        out << rhs[i].getBorn() << " ";
        if(rhs[i].getDeath() != 0)
        {
            out << rhs[i].getDeath();
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
}

ConsoleUI::ConsoleUI(){}

void ConsoleUI::run(){

    string keepGoing;
    do{

    cout << "Please enter one of the following commands:"<< endl;
    cout << "list - This will list all the computer scientists " << endl;
    cout << "add - This will add a computer scientists " << endl;
    cout << "find" << endl;
    cout << "delete" << endl;
    cout << "quit" << endl;


    string command;
    cin >> command;
    keepGoing = command;

    if (command == "list"){
        vector <Legend> legends = _service.getLegends();

        char sortCommand;

        cout << "How do you want to sort" << endl;
        cout << "a - Alphabetical order" << endl;
        cout << "n - No particular sorting" << endl;

        cin >> sortCommand;

        sort(sortCommand, legends);

    } else if (command == "add"){

        string name;
        char gender;
        int born;
        int death;
        int flag = 0;

        do{
            flag = 0;
            cout << "Enter the name: ";
            cin >> name;

            for(size_t i = 0;i < name.size() && flag == 0 ;i++)
            {
             if(isalpha(name[i]) || isupper(name[i])) //checking for a valid name
             {
              flag = 0;
             }
             else
             {
                flag = 1;
             }
        }
        if(flag == 1)
        {
            cout << "Please enter a valid name, only with letters" << endl;
        }
        }while(flag == 1);

        do{
        cout << "Enter the gender: ";
        cin >> gender;
        if(gender != toupper('m') && gender != toupper('f'))
        {
            cout << "Please enter a valid gender";
        }
        }
        while(gender != toupper('m') && gender != toupper('f')); //checking for a valid gender

        do{
        cout << "Enter the year of birth: ";
        cin >> born;
        if(born < 0 || born > 2016)
        {
            cout << "Please enter a valid year of birth"<<endl;
        }
        }while(born < 0 || born > 2016);

        do{
        cout << "Enter the year of death: ";
        cin >> death;
        if(death < born || death > 2016)
        {
            cout << "Please enter a valid year of death"<<endl;
        }
        }while(death < born || death > 2016);//checking for a valid death

        _service.addLegend(name, gender, born, death);

    } else if (command == "delete")
    {

    }
    else if (command == "find")
    {
        cout << "Please enter the string you want to search" <<": ";  
        string name;
        cin >> name;
        _service.findLegend(name);
    }
        
    //cout << "continue?" << endl;

    cout << endl;
    //cin >> keepGoing;
    }while(keepGoing != "quit");

}
