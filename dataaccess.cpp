#include "dataaccess.h"

dataAccess::dataAccess()
{

}

vector<Legend> dataAccess::readFile()
{
    ifstream file;

    vector<Legend> returnVector;

    file.open("legend.txt");
    string line;
    string name;
    char gender;
    int born;
    int death;

    if(file.is_open())
    {
        while(getline(file,line))
        {
            stringstream linestream(line);

            string sBorn;
            string sDeath;
            string sGender;

            getline(linestream, name, ',');
            getline(linestream, sGender, ',');
            getline(linestream, sBorn, ',');
            getline(linestream, sDeath, ',');

            born = atoi(sBorn.c_str());
            death = atoi(sDeath.c_str());
            gender = sGender[0];

            Legend tempLegend(name, gender, born, death);

            returnVector.push_back(tempLegend);

        }
    }

    file.close();

    return returnVector;
}
void dataAccess::writeFile(Legend writeLegend)
{
    ofstream file;

    file.open("legend.txt", ios::app);

    if(file.is_open())
    {
        file << endl << writeLegend.getName() << "," << writeLegend.getGender() << ","
             << writeLegend.getBorn() << "," << writeLegend.getDeath();
    }

    file.close();
}
