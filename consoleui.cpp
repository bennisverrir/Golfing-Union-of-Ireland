#include "consoleui.h"
#include <string>
#include <iostream>
#include "legend.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::run(){

    char keepGoing;
    do{

    cout << "Please enter one of the following commands:"<< endl;
    cout << "list " << endl;
    cout << "add " << endl;

    string command;
    cin >> command;

    if (command == "list"){
        vector <Legend> legends = _service.getLegends();
        for (size_t i = 0; i < legends.size(); i++)
        {
            cout << legends[i].getName() << ", ";
            cout << legends[i].getGender() << ", ";
            cout << legends[i].getBorn() << endl;
        }
    } else if (command == "add"){
        string name;
        char gender;
        int born;

        int flag = 0;
        do{
            flag = 0;
        cout << "Enter the name"<< endl;


        cin >> name;
        for(int i = 0;i < name.size() && flag == 0 ;i++)
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
        cout << "Enter the gender" << endl;
        cin >> gender;
        if(gender != 'm' && gender != 'f')
        {
            cout << "Please enter a valid gender";
        }
        }
        while(gender != 'm' && gender != 'f'); //checking for a valid gender

        do{
        cout << "Enter the year of birth" << endl;
        cin >> born;
        if(born < 0 || born > 2016)
        {
            cout << "Please enter a valid year of birth";
        }
        }while(born < 0 || born > 2016); //checking for a valid birth

        Legend newLegend (name, gender, born);
        //_service.addLegend(newLegend);

    } else if (command == "delete")
    {

    }
    cout << "continue?" << endl;

    cin >> keepGoing;
    }while(keepGoing == 'y');
}
