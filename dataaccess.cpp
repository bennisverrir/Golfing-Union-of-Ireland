#include "dataaccess.h"
#include <cstdio>


dataAccess::dataAccess()
{

}

vector<Legend> dataAccess::readFile()
{
    ifstream file;

    vector<Legend> returnVector;

    file.open(fileName);
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
void dataAccess::writeFile(Legend writeLegend, string fileName)
{
    ofstream file;

    file.open(fileName, ios::app);

    if(file.is_open())
    {
        file << endl << writeLegend.getName() << "," << writeLegend.getGender() << ","
             << writeLegend.getBorn() << "," << writeLegend.getDeath();
    }
    file.close();
}

void dataAccess::deleteLine(vector<Legend> deleteLegend)
{
    ofstream file;

    file.open(fileName, ios::trunc);

    if(file.is_open())
    {
        for(size_t i = 0; i < deleteLegend.size(); i++)
        {
            file << deleteLegend[i].getName() << "," << deleteLegend[i].getGender() << ","
                 << deleteLegend[i].getBorn() << "," << deleteLegend[i].getDeath();

            if(i != (deleteLegend.size() - 1))
            {
                file << endl;
            }
        }
    }

    file.close();

}
