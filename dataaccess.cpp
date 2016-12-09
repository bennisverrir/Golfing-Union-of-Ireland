#include "dataaccess.h"
#include <QDebug>

dataAccess::dataAccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "ComputingDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();
}

dataAccess::~dataAccess()
{
     db.close();

}

/*Function pushingLegendVector ,@param QSqlQuery query @return vector<Legend>
* takes in SQlQuery and pushes the values from the query in to a vector of legend
*/
vector<Legend> dataAccess::pushingLegendVector(QSqlQuery query)
{
    vector<Legend> legends;

    while(query.next())
    {
        int ID = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int born = query.value("Birth").toUInt();
        int death = query.value("Death").toUInt();

        legends.push_back(Legend(ID, name, gender[0], born, death));
    }

    return legends;
}


/*Function pushingComputerVector ,@param QSqlQuery  @return vector<Computer>
* takes in SQlQuery and pushes  the value from the query in to a vector of computer
*/
vector<Computer> dataAccess::pushingComputerVector(QSqlQuery query)
{
    vector<Computer> computers;

    while(query.next())
    {
        int ID = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        string computerType = query.value("TypeName").toString().toStdString();
        bool wasBuilt = query.value("WasBuilt").toBool();

        computers.push_back(Computer(ID, name, buildYear, computerType, wasBuilt));
    }

    return computers;
}

/*Function writeFile, @param Legend writeLegend
* writes one legend into sql scientists table
*/

void dataAccess::writeFile(Legend writeLegend)
{

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

}

/*Function writeComputerFile ,@param Computer and int
* writes one computer and computerTypeID into sql computer table
*
*/
void dataAccess::writeComputerFile(Computer writeComputer, int index)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO Computer(Name, BuildYear, WasBuilt, ComputerTypeID) VALUES(:name, :buildYear, :wasBuilt, :computerTypeID)");

    query.bindValue(":name", QString::fromStdString(writeComputer.getName()));
    query.bindValue(":buildYear", writeComputer.getBuildYear());
    query.bindValue(":wasBuilt", writeComputer.getWasBuilt());
    query.bindValue(":computerTypeID", index);

    query.exec();

}


/*Function sortLegend ,@param int and bool @return vector<Legend>
* return a vector of legend of all scientist in the sql table in any order available in the programm
*/
vector<Legend> dataAccess::sortLegend(int sort, bool ascDesc)
{
    QString sortString = "";
    QString reverse = "";
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
            sortString = "";
    }

    if(sort == 4)
    {
        sortString = "";
        order = "";
    }
    else if (ascDesc)
    {
        reverse = " ASC";
    }
    else
    {
        reverse = " DESC";
    }

    vector<Legend> returnLegends;



    QSqlQuery query(db);

    QString command = "Select * FROM Scientists " + order + sortString + reverse;


    query.exec(command);

    returnLegends = pushingLegendVector(query);

    return returnLegends;
}

/*Function sortComputer ,@param int and bool  @return vector<Computer>
* return a vector of computer of all computers in the sql table in any order available in the programm
*/
vector<Computer> dataAccess::sortComputer(int sort, bool ascDesc)
{
    QString sortString;
    QString reverse;
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
            sortString = "";
    }

    if (sort == 4)
    {
         reverse = "";
         order = "";
    }
    else if (ascDesc)
    {
        reverse = " ASC";
    }
    else
    {
        reverse = " DESC";
    }

    vector<Computer> returnLegends;



    QSqlQuery query(db);

    QString command = "Select c.ID, c.Name, c.BuildYear, ct.Name AS TypeName, c.WasBuilt FROM Computer c "
                         "INNER JOIN ComputerType ct "
                         "ON c.ComputerTypeID = ct.ID " + order + sortString + reverse;
    query.exec(command);

    returnLegends = pushingComputerVector(query);

    return returnLegends;
}

/*Function findLegend ,@param int and string  @return vector<Legend>
*finds scientist by name, gender, birth or death and returns it vector of legand
*
*/

vector<Legend> dataAccess::findLegend(int whatToFind, string find)
{
    QString findString = QString::fromStdString(find);
    QString collumnToFind;
    QString keyWord;

    switch(whatToFind)
    {
        case 0:
            collumnToFind = "Name ";
            keyWord = "LIKE ";
            findString  = "'%" + findString + "%'";
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


    vector<Legend> returnLegends;



    QSqlQuery query(db);

    QString command = "Select * FROM Scientists WHERE " + collumnToFind + keyWord +  findString;

    query.exec(command);

    returnLegends = pushingLegendVector(query);

    return returnLegends;
}

/*Function findComputer ,@param QSqlQuery and QString @return vector<Computer>
*finds computer by name, build year or type name and returns it vector of computer
*/
vector<Computer> dataAccess::findComputer(int whatToFind, string find)
{
    QString findString = QString::fromStdString(find);
    QString collumnToFind;
    QString keyWord;

    switch(whatToFind)
    {
        case 0:
            collumnToFind = "c.Name ";
            keyWord = "LIKE ";
            findString  = "'%" + findString + "%'";

        break;
        case 1:
            collumnToFind = "c.BuildYear ";
            keyWord = "= ";
        break;

        case 2:
            collumnToFind = "TypeName ";
            findString  = "'" + findString + "'";
            keyWord = " LIKE ";
        break;
    }


    vector<Computer> returnComputers;



    QSqlQuery query(db);

    QString command = "Select c.Name,c.BuildYear, c.WasBuilt, ct.Name AS TypeName "
                       "FROM Computer c, ComputerType ct WHERE c.ComputerTypeID = ct.ID AND " + collumnToFind + keyWord +  findString;

    query.exec(command);

    qDebug() << "COMMAND: " << command;

    returnComputers = pushingComputerVector(query);

    return returnComputers;
}

/*Function getComputerTypes ,@return vector<string>
*gets computer type and returns in a vector of string
*
*/
vector<string> dataAccess::getComputerTypes()
{
    vector<string> returnVector;

    QSqlQuery query(db);

    query.exec("Select Name FROM ComputerType");

    while(query.next())
    {
        returnVector.push_back(query.value("Name").toString().toStdString());
    }

    return returnVector;
}

/*Function addComputerType ,@param string
*adds a computer type into the sql computerType table
*/
void dataAccess::addComputerType(string newComputerType)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO ComputerType(Name) VALUES(:name)");

    query.bindValue(":name", QString::fromStdString(newComputerType));

    query.exec();

}

/*Function sortRelation ,@param int and bool @return vector<Relation>
* returns a vector of relation of all relation in the sql relation table in any order available in the programm
*
*/
vector<Relation> dataAccess::sortRelation(int sort, bool ascDesc)
{
    QString order = "";
    QString orderCommand = " Order By ";
    QString reverse;

    if (ascDesc)
    {
        reverse = " ASC";
    }
    else
    {
        reverse = " DESC";
    }

    switch(sort)
    {
        case 0:
            order = "s.Name";
        break;

        case 1:
            order = "c.Name";
        break;

        case 2:
            order = "";
            orderCommand = "";
            reverse = "";
        break;
    }

    vector<Relation> returnVector;

    QSqlQuery query(db);

    QString sqlCommand = "SELECT  s.ID AS sID, c.ID as cID, s.Name, c.Name AS ComputerName From Scientists s, Computer c, Combine co "
                         "WHERE  s.ID = co.Sc AND c.ID = co.Co " + orderCommand + order + reverse;
    string scientistName;
    string computerName;

    query.prepare(sqlCommand);

    query.exec();

    while(query.next())
    {
        int scientistID = query.value("sID").toUInt();
        int computerID = query.value("cID").toUInt();
        scientistName = query.value("Name").toString().toStdString();
        computerName = query.value("ComputerName").toString().toStdString();

        returnVector.push_back(Relation(scientistID, computerID, scientistName, computerName));
    }

    return returnVector;
}

/*Function addRelation ,@paramRelation
*
*
*/
void dataAccess::addRelation(Relation relation)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO Combine(Sc,Co) Values(:sc, :co)");

    query.bindValue(":sc", relation.getScientistID());
    query.bindValue(":co", relation.getComputerID());


    query.exec();
}

/*Function editLegend ,@param Legend
* TODO
*
*
*/
void dataAccess::editLegend(Legend oldLegend, Legend editLegend)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(editLegend.getName());
    QString oldName = QString::fromStdString(oldLegend.getName());
    QString ID = QString::fromStdString(to_string(oldLegend.getID()));
    QString isDead = QString::fromStdString(to_string((editLegend.getDeath() == 0 ? 0 : 1)));
    QString born = QString::fromStdString(to_string(editLegend.getBorn()));
    QString death =  QString::fromStdString(to_string(editLegend.getDeath()));

    QString command = "UPDATE Scientists"
                      " SET Name = '" + name + "', Gender = '" + editLegend.getGender() +
                      "' , Birth = " + born + ", Death = " + death +
                      ", IsDead = " + isDead +
                      " WHERE ID = " + ID;

    query.exec(command);

}

/*Function editComputer ,@param Computer and int
* TODO
*
*
*/

void dataAccess::editComputer(Computer oldComputer, Computer editComputer, int index)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(editComputer.getName());
    QString oldName = QString::fromStdString(oldComputer.getName());
    QString ID = QString::fromStdString(to_string(oldComputer.getID()));
    QString buildYear = QString::fromStdString(to_string(editComputer.getBuildYear()));
    QString wasBuilt = QString::fromStdString(to_string(editComputer.getBuildYear() == 0 ? 0 : 1));
    QString computerType = QString::fromStdString(editComputer.getComputerType());

    query.exec("SELECT * FROM ComputerType WHERE Name LIKE " + computerType);

    QString computerTypeID = QString::fromStdString(to_string(index));

    QString command = "UPDATE Computer"
                      " SET Name = '" + name + "',  BuildYear = '" + buildYear +
                      "' , ComputerTypeID = " + computerTypeID + ", BuildYear = " + buildYear +
                      ", WasBuilt = " + wasBuilt +
                      " WHERE ID = " + ID;

    query.exec(command);
}

/*Function getID ,@param QSqlQuery and QString @return int
* TODO
*
*
*
int dataAccess::getID(QSqlQuery query,  QString name, QString tableName)
{

    query.exec("SELECT ID, Name FROM " + tableName + " WHERE Name LIKE '" + name + "'");
    query.first();

    int returnInt = query.value("ID").toUInt();

    return returnInt;
}*/

/*void dataAccess::editRelation(Relation relation, Relation oldRelation)
{

    QSqlQuery query(db);
    QString scientistName = QString::fromStdString(relation.getLegendName());
    QString computerName = QString::fromStdString(relation.getComputerName());
    QString oldScientistName = QString::fromStdString(relation.getLegendName());
    QString oldComputerName = QString::fromStdString(relation.getComputerName());
    QString scientistID ;
    QString computerID ;
    QString oldScientistID;
    QString oldComputerID;

    scientistID = QString::fromStdString(to_string(getID(query, scientistName, "Scientists")));

    computerID =  QString::fromStdString(to_string(getID(query, computerName, "Computer")));

    oldScientistID = QString::fromStdString(to_string(getID(query, oldScientistName, "Scientists")));

    oldComputerID =  QString::fromStdString(to_string(getID(query, oldComputerName, "Computer")));

    query.prepare("UPDATE Combine"
                  " SET Sc = " + scientistID + ", Co = " + computerID +
                  " WHERE Sc = " + oldScientistID + " AND Co + " + oldComputerID);

    query.exec();

}*/



/*Function findRelation ,@param string  @return vector<Relation>
* TODO
*
*
*/
vector<Relation> dataAccess::findRelation(string nameToFind)
{
    QSqlQuery query(db);

    string scientistName;
    string computerName;
    int scientistID;
    int computerID;
    QString name = QString::fromStdString(nameToFind);


    vector<Relation> returnVector;

    QString command = " SELECT  s.Name, s.ID as sID, c.ID ad cID, c.Name AS ComputerName  From Scientists s, Computer c, Combine co"
                       " ON s.ID = co.Sc AND c.ID = co.Co Where s.Name LIKE '%" + name + "%' OR ComputerName LIKE '%" + name + "%'";

    query.prepare(command);


    query.exec();

    qDebug() << command;

    while(query.next())
    {
        scientistID = query.value("sID").toUInt();
        computerID = query.value("cID").toUInt();
        scientistName = query.value("Name").toString().toStdString();
        computerName = query.value("ComputerName").toString().toStdString();

        returnVector.push_back(Relation(scientistID, computerID, scientistName, computerName));
    }


    return returnVector;
}

/*Function deleteRelation, @param Relation
* deletes Relation from the sql
* TODO
*
*/
void dataAccess:: deleteRelation(Relation relationToDelete)
{
    QSqlQuery query(db);

    QString scientistID = QString::fromStdString(to_string(relationToDelete.getScientistID()));

    QString computerID = QString::fromStdString(to_string(relationToDelete.getComputerID()));


    QString command = "DELETE FROM Combine WHERE Sc = "+ scientistID +" AND Co = "+ computerID;

    query.prepare(command);

    query.exec();

    qDebug() << command;

}

/*Function editRelation, @param Relation
* edits relations TODO
*
*
*/
void dataAccess::editRelation(Relation oldRelation, Relation editedRelation)
{
    QSqlQuery query(db);

    QString scientistID = QString::fromStdString(to_string(editedRelation.getScientistID()));

    QString computerID = QString::fromStdString(to_string(editedRelation.getComputerID()));

    QString oldScientistID = QString::fromStdString(to_string(oldRelation.getScientistID()));

    QString oldComputerID = QString::fromStdString(to_string(oldRelation.getComputerID()));


    query.exec("UPDATE Combine Set Sc = " + scientistID  + ", Co = " + computerID +
               " WHERE Sc = " + oldScientistID + " AND Co = " + oldComputerID);
}

