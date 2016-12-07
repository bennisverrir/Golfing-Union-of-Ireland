#include "dataaccess.h"
#include <QDebug>

dataAccess::dataAccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "ComputingDatabase.sqlite";
    db.setDatabaseName(dbName);
}

vector<Legend> dataAccess::pushingLegendVector(QSqlQuery query)
{
    vector<Legend> legends;

    while(query.next())
    {

        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int born = query.value("Birth").toUInt();
        int death = query.value("Death").toUInt();

        legends.push_back(Legend(name, gender[0], born, death));
    }

    return legends;
}

vector<Computer> dataAccess::pushingComputerVector(QSqlQuery query)
{
    vector<Computer> computers;

    while(query.next())
    {
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        string computerType = query.value("TypeName").toString().toStdString();
        bool wasBuilt = query.value("WasBuilt").toBool();

        computers.push_back(Computer(name, buildYear, computerType, wasBuilt));
    }

    return computers;
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


void dataAccess::writeComputerFile(Computer writeComputer, bool &fileOpen, int index)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO Computer(Name, BuildYear, WasBuilt, ComputerTypeID) VALUES(:name, :buildYear, :wasBuilt, :computerTypeID)");

    query.bindValue(":name", QString::fromStdString(writeComputer.getName()));
    query.bindValue(":buildYear", writeComputer.getBuildYear());
    query.bindValue(":wasBuilt", writeComputer.getWasBuilt());
    query.bindValue(":computerTypeID", index);

    query.exec();

    db.close();
}

/*Function deleteLine, @param vector<Legend> and bool
* Takes the @param which is a vector of all the Legend without the deleted Legend
* writes over the file the information of all the Legend in the vector into the file.
* sets fileOpen to true if file is open and false if it could not be open
*/
void dataAccess::deleteLine(vector<Legend> &deleteLegend, bool &fileOpen){}

vector<Legend> dataAccess::sortLegend(int sort)
{
    QString sortString;
    QString order = "ORDER BY ";

    switch(sort)
    {
        case 0:
            sortString = "Name";
        break;
        case 1:
            sortString = "Gender";
        break;
        case 2:
            sortString = "Birth";
        break;
        case 3:
            sortString = "Death";
        break;
        case 4:
            order = "";
        break;
    }

    vector<Legend> returnLegends;

    db.open();

    QSqlQuery query(db);
    query.exec("Select * FROM Scientists " + order + sortString + " ASC");

    returnLegends = pushingLegendVector(query);

    db.close();

    return returnLegends;
}

vector<Computer> dataAccess::sortComputer(int sort)
{
    QString sortString;
    QString order = "ORDER BY ";

    switch(sort)
    {
        case 0:
            sortString = "c.Name";
        break;
        case 1:
            sortString = "BuildYear";
        break;
        case 2:
            sortString = "ct.Name";
        break;
        case 3:
            sortString = "c.WasBuilt";
        break;
        case 4:
            order = "";
        break;
    }

    vector<Computer> returnLegends;

    db.open();

    QSqlQuery query(db);

    QString sqlCommand = "Select c.Name, c.BuildYear, ct.Name AS TypeName, c.WasBuilt FROM Computer c "
                         "INNER JOIN ComputerType ct "
                         "ON c.ComputerTypeID = ct.ID "+ order + sortString + " ASC";

    query.exec(sqlCommand);

    qDebug() << "COMMAND: " << sqlCommand;

    returnLegends = pushingComputerVector(query);

    db.close();

    return returnLegends;
}

vector<Legend> dataAccess::findLegend(int whatToFind, string find, bool &fileOpen)
{
    QString findString = QString::fromStdString(find);
    QString collumnToFind;
    QString keyWord;

    switch(whatToFind)
    {
        case 0:
            collumnToFind = "Name ";
            keyWord = "LIKE ";
            findString  = "'" + findString + "%'";
        break;
        case 1:
            collumnToFind = "Gender ";
            keyWord = "= ";
            findString = "'" + findString + "'";
        break;
        case 2:
            collumnToFind = "Birth ";
            keyWord = "= ";
        break;
        case 3:
            collumnToFind = "Death ";
            keyWord = "= ";
        break;
    }

    qDebug() << "STRING " << findString << endl;

    vector<Legend> returnLegends;

    db.open();

    if(db.isOpen())
    {
        fileOpen = true;
    }
    else
    {
        fileOpen = false;
    }

    QSqlQuery query(db);

    QString command = "Select * FROM Scientists WHERE " + collumnToFind + keyWord +  findString;

    query.exec(command);

    qDebug() << "COMMAND " << command;

    returnLegends = pushingLegendVector(query);

    db.close();

    return returnLegends;
}

vector<string> dataAccess::getComputerTypes()
{
    vector<string> returnVector;

    db.open();

    QSqlQuery query(db);

    query.exec("Select Name FROM ComputerType");

    while(query.next())
    {
        returnVector.push_back(query.value("Name").toString().toStdString());
    }

    db.close();

    return returnVector;
}

void dataAccess::addComputerType(string newComputerType)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO ComputerType(Name) VALUES(:name)");

    query.bindValue(":name", QString::fromStdString(newComputerType));

    query.exec();

    db.close();
}
