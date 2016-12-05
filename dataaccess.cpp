#include "dataaccess.h"

dataAccess::dataAccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "ComputingDatabase.sqlite";
}
/*Function readFile,@param bool @return vector<Legend>
* Reads one line at a time from a file and generates a instance of Legend
* Then pushes the Legend instance into a vector and retuns a vector<Legend>.
* sets fileOpen to true if file is open and false if it could not be open
*/
vector<Legend> dataAccess::readFile(bool &fileOpen)
{
    vector<Legend> legends;

    db.setDatabaseName(dbName);

    db.open();

    if(db.open())
    {
        fileOpen = true;
    }

    QSqlQuery query(db);


    query.exec("SELECT * FROM Legend");


    while(query.next())
    {

        string name = query.value("Name").toString().toStdString();
        char gender = query.value("Gender").toChar().toLatin1();
        int born = query.value("BirthYear").toUInt();
        int death = query.value("DeathYear").toUInt();

        legends.push_back(Legend(name, gender, born, death));
    }

    db.close();

    return legends;

}

/*Function writeFile, @param Legend and bool
* Takes a Legend and writes all information about it in a new line in a file
* sets fileOpen to true if file is open and false if it could not be open
*/

void dataAccess::writeFile(Legend writeLegend, bool &fileOpen)
{

    db.open();

    QSqlQuery query(db);

    bool isDead;

    if(writeLegend.getDeath() == 0)
    {
        isDead = 0;
    }
    else
    {
        isDead = 1;
    }


    query.prepare("INSERT INTO Legend(Name,BirthYear,DeathYear,IsDead,Gender) VALUES(:name, :born, :death, :isDead,:gender)");

    query.bindValue(":name", QString::fromStdString(writeLegend.getName()));
    query.bindValue(":born", writeLegend.getBorn());
    query.bindValue(":death", writeLegend.getDeath());
    query.bindValue(":isDead", isDead);
    query.bindValue(":gender", writeLegend.getGender());

    query.exec();

    db.close();
}
/*Function deleteLine, @param vector<Legend> and bool
* Takes the @param which is a vector of all the Legend without the deleted Legend
* writes over the file the information of all the Legend in the vector into the file.
* sets fileOpen to true if file is open and false if it could not be open
*/
void dataAccess::deleteLine(vector<Legend> &deleteLegend, bool &fileOpen)
{

}
