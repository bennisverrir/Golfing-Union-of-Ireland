#include "consoleui.h"
#include <string>
#include <iostream>
#include "legend.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::run(){
    cout << "Please enter one of the following commands:"<< endl;
    cout << "list - " << endl;
    cout << "add - " << endl;

    string command;
    cin >> command;

    if (command == "list"){
        vector <Legend> legends = _service.getLegends();
        for (size_t i = 0; i < legends.size(); i++){
            cout << legends[i].getName() << ", ";
            cout << legends[i].getGender() << ", ";
            cout << legends[i].getBorn() << endl;
        }
    } else if (command == "add"){
        string name;
        string gender;
        int born;
        cin >> name;
        cin >> gender;
        cin >> born;
        Legend newLegend (name, gender, born);
        //_service.addLegend(newLegend);

    } else if (command == "delete"){

    }
}
