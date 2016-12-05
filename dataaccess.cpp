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


    query.exec("SELECT * FROM Scientists");


    while(query.next())
    {

        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int born = query.value("Birth").toUInt();
        int death = query.value("Death").toUInt();

        legends.push_back(Legend(name, gender[0], born, death));
    }

    db.close();

    return legends;

}

vector<Computer> dataAccess::readComputerFile(bool &fileOpen)
{
    vector<Computer> legends;

    db.setDatabaseName(dbName);

    db.open();

    if(db.open())
    {
        fileOpen = true;
    }

    QSqlQuery query(db);


    query.exec("SELECT * FROM Computer");


    while(query.next())
    {

        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        string computerType = query.value("ComputerType").toString().toStdString();
        bool wasBuilt = query.value("wasBuilt").toBool();

        legends.push_back(Computer(name, buildYear, computerType[0], wasBuilt));
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


    query.prepare("INSERT INTO Scientists(Name, Gender, Birth,Death,IsDead) VALUES(:name, :gender, :born, :death, :isDead)");

    query.bindValue(":name", QString::fromStdString(writeLegend.getName()));
    query.bindValue(":gender", QChar::fromLatin1(writeLegend.getGender()));
    query.bindValue(":born", writeLegend.getBorn());
    query.bindValue(":death", writeLegend.getDeath());
    query.bindValue(":isDead", isDead);

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
