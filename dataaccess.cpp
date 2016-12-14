#include "dataaccess.h"

dataAccess::dataAccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "ComputingRecords.sqlite";
    db.setDatabaseName(dbName);

    db.open();
}

dataAccess::~dataAccess()
{
     db.close();

     qDebug() << "ESRAR SPANEI";

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
        string bio = query.value("Bio").toString().toStdString();

        legends.push_back(Legend(ID, name, gender[0], born, death, bio));
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
        int ID = query.value("cID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        string computerType = query.value("TypeName").toString().toStdString();
        bool wasBuilt = query.value("WasBuilt").toBool();
        string bio = query.value("Bio").toString().toStdString();

        computers.push_back(Computer(ID, name, buildYear, computerType, wasBuilt, bio));
    }

    return computers;
}

/*Function writeFile, @param Legend writeLegend
* writes one legend into sql scientists table
*/

bool dataAccess::writeFile(Legend writeLegend)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO Scientists(Name, Gender, Birth,Death, Bio) VALUES(:name, :gender, :born, :death, :bio)");

    query.bindValue(":name", QString::fromStdString(writeLegend.getName()));
    query.bindValue(":gender", QChar::fromLatin1(writeLegend.getGender()));
    query.bindValue(":born", writeLegend.getBorn());
    query.bindValue(":death", writeLegend.getDeath());
    query.bindValue(":bio", QString::fromStdString(writeLegend.getBio()));


    if(!query.exec())
    {
        return false;
    }
    return true;

}

/*Function writeComputerFile ,@param Computer and int
* writes one computer and computerTypeID into sql computer table
*
*/
bool dataAccess::writeComputerFile(Computer writeComputer, int index)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO Computer(Name, BuildYear, WasBuilt, ComputerTypeID, Bio) VALUES(:name, :buildYear, :wasBuilt, :computerTypeID, :bio)");

    query.bindValue(":name", QString::fromStdString(writeComputer.getName()));
    query.bindValue(":buildYear", writeComputer.getBuildYear());
    query.bindValue(":wasBuilt", writeComputer.getWasBuilt());
    query.bindValue(":computerTypeID", index);
    query.bindValue(":bio", QString::fromStdString(writeComputer.getBio()));

    return query.exec();

}


/*Function sortLegend ,@param int and bool @return vector<Legend>
* return a vector of legend of all scientist in the sql table in any order available in the programm
*/
vector<Legend> dataAccess::sortLegend()
{
    vector<Legend> returnLegends;


    QSqlQuery query(db);

    QString command = "Select * FROM Scientists ";

    query.exec(command);

    returnLegends = pushingLegendVector(query);

    return returnLegends;
}

/*Function sortComputer ,@param int and bool  @return vector<Computer>
* return a vector of computer of all computers in the sql table in any order available in the programm
*/
vector<Computer> dataAccess::sortComputer()
{
    vector<Computer> returnLegends;



    QSqlQuery query(db);

    QString command = "Select c.ID as cID, c.Name, c.BuildYear, ct.Name AS TypeName, c.WasBuilt, c.Bio AS Bio FROM Computer c "
                      "INNER JOIN ComputerType ct "
                      "ON c.ComputerTypeID = ct.ID";
    query.exec(command);

    returnLegends = pushingComputerVector(query);

    return returnLegends;
}

/*Function findLegend ,@param int and string  @return vector<Legend>
*finds scientist by name, gender, birth or death and returns it vector of legand
*
*/

vector<Legend> dataAccess::findLegend(string find)
{
    QString findString = QString::fromStdString(find);
    vector<Legend> returnLegends;

    QSqlQuery query(db);


    QString command = "Select * FROM Scientists WHERE Name LIKE '%" + findString + "%' OR Cast(Birth As Varchar) LIKE '%" + findString + "%' OR Cast(Death As Varchar) LIKE '%" + findString + "%'";

    query.exec(command);

    returnLegends = pushingLegendVector(query);

    return returnLegends;
}

/*Function findComputer ,@param QSqlQuery and QString @return vector<Computer>
*finds computer by name, build year or type name and returns it vector of computer
*/
vector<Computer> dataAccess::findComputer(string find)
{
    QString findString = QString::fromStdString(find);

    vector<Computer> returnComputers;



    QSqlQuery query(db);

    QString command = "Select c.ID AS cID, c.Name,c.BuildYear, c.WasBuilt, ct.Name AS TypeName FROM Computer c, ComputerType ct WHERE c.ComputerTypeID = ct.ID "
                      "AND (c.Name LIKE '%" + findString + "%' OR Cast(c.BuildYear AS Varchar) LIKE '%" + findString + "%' OR TypeName LIKE '%" + findString +"%')";

    query.exec(command);

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
bool dataAccess::addComputerType(string newComputerType)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO ComputerType(Name) VALUES(:name)");

    query.bindValue(":name", QString::fromStdString(newComputerType));

    return query.exec();

}


/*Function sortRelation ,@param int and bool @return vector<Relation>
* returns a vector of relation of all relation in the sql relation table in any order available in the programm
*
*/
vector<Relation> dataAccess::sortRelation()
{
    vector<Relation> returnVector;

    QSqlQuery query(db);

    QString sqlCommand = "SELECT  s.ID AS sID, c.ID as cID, s.Name, c.Name AS ComputerName From Scientists s, Computer c, Combine co "
                         "WHERE  s.ID = co.Sc AND c.ID = co.Co ";
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
*adds a relation into the sql relation table
*
*/
bool dataAccess::addRelation(Relation relation)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO Combine(Sc,Co) Values(:sc, :co)");

    query.bindValue(":sc", relation.getScientistID());
    query.bindValue(":co", relation.getComputerID());


    return query.exec();
}

/*Function editLegend ,@param Legend
*edits a sientist in the sql table scientits
*takes the oldLegend's ID and then puts the editLegend instead
*/
bool dataAccess::editLegend(Legend oldLegend, Legend editLegend)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(editLegend.getName());
    QString ID = QString::fromStdString(to_string(oldLegend.getID()));
    QString born = QString::fromStdString(to_string(editLegend.getBorn()));
    QString death =  QString::fromStdString(to_string(editLegend.getDeath()));
    QString bio = QString::fromStdString(editLegend.getBio());

    QString command = "UPDATE Scientists"
                      " SET Name = '" + name + "', Gender = '" + editLegend.getGender() +
                      "' , Birth = " + born + ", Death = " + death + ", Bio = '" + bio +
                      "' WHERE ID = " + ID;

    qDebug() << command;

    return query.exec(command);
}

/*Function editComputer ,@param Computer and int
* edits a computer in the sql table computer
*takes the oldComputer'ID and then puts the editComputer instead
*index is the computerTypeID
*/

bool dataAccess::editComputer(Computer oldComputer, Computer editComputer, int index)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(editComputer.getName());
    QString oldName = QString::fromStdString(oldComputer.getName());
    QString ID = QString::fromStdString(to_string(oldComputer.getID()));
    QString buildYear = QString::fromStdString(to_string(editComputer.getBuildYear()));
    QString wasBuilt = QString::fromStdString(to_string(editComputer.getBuildYear() == 0 ? 0 : 1));
    QString computerType = QString::fromStdString(editComputer.getComputerType());
    QString computerTypeID = QString::number(index);
    QString bio = QString::fromStdString(editComputer.getBio());

    QString command = "UPDATE Computer"
                      " SET Name = '" + name + "',  BuildYear = '" + buildYear +
                      "' , ComputerTypeID = " + computerTypeID + ", BuildYear = " + buildYear +
                      ", WasBuilt = " + wasBuilt + ", Bio = '" + bio +
                      "' WHERE ID = " + ID;

    return query.exec(command);

}


vector<Relation> dataAccess::findRelation(string nameToFind)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(nameToFind);


    vector<Relation> returnVector;

    QString command = " SELECT  s.Name AS sName, s.ID as sID, c.ID as cID, c.Name AS cName  From Scientists s, Computer c, Combine co"
                       " ON sID = co.Sc AND cID = co.Co Where sName LIKE '%" + name + "%' OR cName LIKE '%" + name + "%'" ;

    query.prepare(command);

    qDebug() << command << query.lastError();

    query.exec();

    while(query.next())
    {
        int scientistID = query.value("sID").toUInt();
        int computerID = query.value("cID").toUInt();
        string scientistName = query.value("sName").toString().toStdString();
        string computerName = query.value("cName").toString().toStdString();

        returnVector.push_back(Relation(scientistID, computerID, scientistName, computerName));
    }


    return returnVector;
}

/*Function deleteRelation, @param Relation
* deletes Relation from the sql relation table
*
*/
bool dataAccess:: deleteRelation(Relation relationToDelete)
{
    QSqlQuery query(db);

    QString scientistID = QString::fromStdString(to_string(relationToDelete.getScientistID()));

    QString computerID = QString::fromStdString(to_string(relationToDelete.getComputerID()));


    QString command = "DELETE FROM Combine WHERE Sc = "+ scientistID +" AND Co = "+ computerID;

    query.prepare(command);

    return query.exec();

}

/*Function editRelation, @param Relation
* edits relations TODO
*
*
*/
bool dataAccess::editRelation(int scientistID, int computerID, Relation oldRelation)
{
    QSqlQuery query(db);

    QString oldScientistID = QString::number(oldRelation.getScientistID());

    QString oldComputerID = QString::number(oldRelation.getComputerID());

    return query.exec("UPDATE Combine Set Sc = " + QString::number(scientistID)  + ", Co = " + QString::number(computerID) +
               " WHERE Sc = " + oldScientistID + " AND Co = " + oldComputerID);
}

/*Function joke, @return vector<string>
*return a vector of all the jokes in the joke table in sql
*
*/
vector<string> dataAccess::joke()
{
    string joke;
    vector<string>toReturn;
    QSqlQuery query(db);
    query.exec("SELECT * FROM Jokes");

    while(query.next())
    {
        joke = query.value("col_2").toString().toStdString();
        toReturn.push_back(joke);
    }

    qDebug() << query.lastError();

    return toReturn;
}

