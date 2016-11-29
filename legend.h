#ifndef LEGEND_H
#define LEGEND_H

#include <string>
using namespace std;


class Legend
{
public:
    Legend();
    Legend (string name, string gender, int born);

    string getName() const {
        return _name;
    }
    string getGender() const{
        return _gender;
    }
    int getBorn () const {
        return _born;
    }
    /*
    int getDeath (){
        return _death;
    }
    */

private:
    string _name;
    string _gender;
    int _born;
    //int _death;
};

#endif // LEGEND_H
