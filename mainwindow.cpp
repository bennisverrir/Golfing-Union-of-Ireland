#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDir dir;

    dir.relativeFilePath("/Images/");

    if(dir.exists())
    {
        dir.mkdir("Images");
    }

    QString filePath = dir.currentPath() + "/Images/" + "default";

    QFile defaultImage(":/Images/default.png");

    QFile::copy(defaultImage.fileName(), filePath);

    QPixmap defaultPixMap(filePath);

    ui->setupUi(this);

    QPixmap newPixmap = defaultPixMap.scaled(QSize(150,350), Qt::KeepAspectRatio);

    ui->PictureLabel->setPixmap(newPixmap);

    whatTable = ui->TableView->currentIndex();

    displayLegends(_service.requestLegendSort());
    displayComputers(_service.requestComputerSort());
    displayRelations(_service.requestRelationSort());

    fillComputerTypeComboBox();
    fillLegendRelationComboBox();
    fillComputerRelationComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Function displayLegends, @Param vector<Legend>, @return void
 * Loops throught the vector and displays Name, gender, birth year and death year
 * of each Legend and puts it in in a QWidgetTable
 */
void MainWindow::displayLegends(vector<Legend> legends)
{
    ui->ScientistTable->setSortingEnabled(false);

    ui->ScientistTable->clearContents();
    ui->ScientistTable->hideColumn(4);
    ui->ScientistTable->hideColumn(5);
    ui->ScientistTable->setRowCount(legends.size());

    for(size_t row = 0; row < legends.size(); row++)
    {
        Legend currentLegend = legends[row];

        QString name = QString::fromStdString(currentLegend.getName());
        QChar gender = QChar::fromLatin1(currentLegend.getGender());
        QString born = QString::number(currentLegend.getBorn());
        QString death = (currentLegend.getDeath() == 0 ? "" : QString::number(currentLegend.getDeath()));
        QString ID = QString::number(currentLegend.getID());
        QString bio = QString::fromStdString(currentLegend.getBio());

        ui->ScientistTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ScientistTable->setItem(row,1, new QTableWidgetItem(gender));
        ui->ScientistTable->setItem(row,2, new QTableWidgetItem(born));
        ui->ScientistTable->setItem(row,3, new QTableWidgetItem(death));
        ui->ScientistTable->setItem(row,4, new QTableWidgetItem(ID));
        ui->ScientistTable->setItem(row,5, new QTableWidgetItem(bio));
    }

    ui->ScientistTable->setSortingEnabled(true);
}

/*Function displayComputers, @param vector<Computer>, @return void
 * Loops throught the vector and displays Name, Build year and computerType
 * of each Computer and puts it in a QWidgetTable
 */

void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->setSortingEnabled(false);

    ui->ComputerTable->clearContents();
    ui->ComputerTable->hideColumn(3);
    ui->ComputerTable->hideColumn(4);
    ui->ComputerTable->setRowCount(computers.size());

    for(size_t row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString buildYear = (currentComputer.getBuildYear() == 0 ? "" : QString::number(currentComputer.getBuildYear()));
        QString computerType = QString::fromStdString(currentComputer.getComputerType());
        QString ID = QString::number(currentComputer.getID());
        QString bio = QString::fromStdString(currentComputer.getBio());

        ui->ComputerTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ComputerTable->setItem(row,1, new QTableWidgetItem(buildYear));
        ui->ComputerTable->setItem(row,2, new QTableWidgetItem(computerType));
        ui->ComputerTable->setItem(row,3, new QTableWidgetItem(ID));
        ui->ComputerTable->setItem(row,4, new QTableWidgetItem(bio));
    }

    ui->ComputerTable->setSortingEnabled(true);
}

/*Function displayRelations, @param vector<Computer>, @return void
 * Loops throught the vector and displays Scientistname and Computername
 * of each Relation and puts it in a QWidgetTable
 */

void MainWindow::displayRelations(vector<Relation> relations)
{
    ui->RelationTable->setSortingEnabled(false);

    ui->RelationTable->clearContents();
    ui->RelationTable->hideColumn(2);
    ui->RelationTable->hideColumn(3);
    ui->RelationTable->setRowCount(relations.size());

    for(size_t row = 0; row < relations.size(); row++)
    {
        Relation currentRelation = relations[row];

        QString scientistName = QString::fromStdString(currentRelation.getLegendName());
        QString computerName = QString::fromStdString(currentRelation.getComputerName());
        QString scientistID = QString::number(currentRelation.getScientistID());
        QString computerID = QString::number(currentRelation.getComputerID());

        ui->RelationTable->setItem(row,0, new QTableWidgetItem(scientistName));
        ui->RelationTable->setItem(row,1, new QTableWidgetItem(computerName));
        ui->RelationTable->setItem(row,2, new QTableWidgetItem(scientistID));
        ui->RelationTable->setItem(row,3, new QTableWidgetItem(computerID));
    }

    ui->RelationTable->setSortingEnabled(true);
}

/*Function on_findText_textChanged
 * The function is called when some text is put in the find box
 * it then calls the appropriate display function witch displays all information
 * that includes the find string
 */
void MainWindow::on_findText_textChanged(const QString &arg1)
{
    string nameToFind = ui->findText->text().toStdString();

    _service.setSearchField(nameToFind);

    if(whatTable == 0)
    {
        displayLegends(_service.requestLegendSearch());
    }
    else if(whatTable == 1)
    {
         displayComputers(_service.requestComputerSearch());
    }
    else if(whatTable == 2)
    {
         displayRelations(_service.requestRelationSearch());
    }

}

/*Function addLegend, @return bool
 * Takes the text from the appropriate text boxes or combo boxes and
 * passes the information to the requestLegendAdd in the service layer,
 * returns true if adding the Legend was successfull
 */

bool MainWindow::addLegend()
{
    string name = ui->ScientistName->text().toStdString();
    string gender = ui->ScientistGender->currentText().toStdString();
    int born = ui->ScientistBorn->text().toInt();
    int death = ui->ScientistDeath->text().toInt();
    string bio = ui->ScientistBio->toPlainText().toStdString();

    for(size_t i = 0; i < bio.size(); i++)
    {
        if(bio.at(i) == '\'')
        {
            bio.insert(i-1,"'",1);
        }
    }

    qDebug() << QString::fromStdString(bio);

    return _service.requestLegendAdd(name, gender[0], born, death, bio);
}

/*Function addComputer, @return bool
 * Takes the text from the appropriate text boxes or combo boxes and
 * passes the information to the requestComputerAdd in the service layer,
 * returns true if adding the Computer was successfull
 */

bool MainWindow::addComputer()
{
    string name = ui->ComputerName->text().toStdString();
    int buildYear = ui->ComputerBuilt->text().toInt();
    string computerType = ui->ComputerType->currentText().toStdString();
    int computerTypeID = ui->ComputerType->currentIndex() + 1;
    string bio = ui->ComputerBio->toPlainText().toStdString();

    qDebug() << computerTypeID;

    int wasBuilt = (buildYear == 0 ? 0 : 1);

    return _service.requestComputerAdd(name,buildYear,computerType,wasBuilt, computerTypeID, bio);
}

/*Function addRelation, @return bool
 * Takes the text from the appropriate combo boxes and
 * passes the information to the requestRelationAdd in the service layer,
 * returns true if adding the Relation was successfull
 */

bool MainWindow::addRelation()
{
   int scientistID = ui->RelationScientistName->currentIndex() + 1;
   int computerID = ui->RelationComputerName->currentIndex() + 1;

   return _service.requestRelationAdd(scientistID, computerID);
}

/*Function on_ButtonAddScientist_clicked
 * is called when the ButtonAddScientist button is clicked
 * checks if it is successfull to add the scientist and calls the addLegend function
 *
 */
void MainWindow::on_ButtonAddScientist_clicked()
{
    if(addScientisInputIsValid())
    {
        if(addLegend())
        {
            ui->labelErrorScientist->setText("");
            displayLegends(_service.requestLegendSort());
            ui->ScientistName->clear();
            ui->ScientistBorn->clear();
            ui->ScientistDeath->clear();
        }
        else
        {

            ui->labelErrorScientist->setText("Error!! Scientist was not added!");
        }
    }
}

/*Function editLegend, @return bool
 * Checks what scientist is selected in the Scientist table
 * Then takes the information from the appropriate text boxes or combo boxes
 * and passes those information to requestLegendEdit in the service layer
 */

bool MainWindow::editLegend()
{
    int row = ui->ScientistTable->currentRow();

    string oldName = ui->ScientistTable->item(row, 0)->text().toStdString();
    string oldGender = ui->ScientistTable->item(row, 1)->text().toStdString();
    int oldBorn = ui->ScientistTable->item(row, 2)->text().toInt();
    int oldDeath = ui->ScientistTable->item(row, 3)->text().toInt();
    int oldID = ui->ScientistTable->item(row,4)->text().toInt();
    string oldBio = ui->ScientistTable->item(row,5)->text().toStdString();

    Legend oldLegend(oldID, oldName, oldGender[0], oldBorn, oldDeath, oldBio);

    string name = ui->ScientistName->text().toStdString();
    string gender = ui->ScientistGender->currentText().toStdString();
    int born = ui->ScientistBorn->text().toInt();
    int death = ui->ScientistDeath->text().toInt();
    string bio = ui->ScientistBio->toPlainText().toStdString();

    return _service.requestLegendEdit(name,gender[0],born,death, bio, oldLegend);
}

/*Function editComputer, @return bool
 * Checks what scientist is selected in the Computer table
 * Then takes the information from the appropriate text boxes or combo boxes
 * and passes those information to requestComputerEdit in the service layer
 */
bool MainWindow::editComputer()
{
    int row = ui->ComputerTable->currentRow();

    string oldName = ui->ComputerTable->item(row, 0)->text().toStdString();
    int oldBuildYear = ui->ComputerTable->item(row, 1)->text().toInt();
    bool oldWasBuilt = (oldBuildYear == 0 ? 0 : 1);
    string oldComputerType = ui->ComputerTable->item(row, 2)->text().toStdString();
    int oldID = ui->ComputerTable->item(row, 3)->text().toInt();
    string oldBio = ui->ComputerTable->item(row,4)->text().toStdString();

    Computer oldComputer(oldID,oldName,oldBuildYear, oldComputerType, oldWasBuilt, oldBio);

    string name = ui->ComputerName->text().toStdString();
    int buildYear = ui->ComputerBuilt->text().toInt();
    string computerType = ui->ComputerType->currentText().toStdString();
    int computerTypeID = ui->ComputerType->currentIndex() + 1;
    string bio = ui->ComputerBio->toPlainText().toStdString();

    int wasBuilt = (buildYear == 0? 0 : 1);

    return _service.requestComputerEdit(name, buildYear, computerType, wasBuilt, oldComputer, computerTypeID, bio);
}

/*Function editRelation, @return bool
 * Checks what scientist is selected in the Relation table
 * Then takes the information from the appropriate combo boxes
 * and passes those information to requestRelationEdit in the service layer
 */
bool MainWindow::editRelations()
{
    int scientistID = ui->RelationScientistName->currentIndex() + 1;
    int computerID = ui->RelationComputerName->currentIndex() + 1;

    int row = ui->RelationTable->currentRow();

    string oldScientistName = ui->RelationTable->item(row, 0)->text().toStdString();
    string oldComputerName = ui->RelationTable->item(row, 1)->text().toStdString();
    int oldScientistID = ui->RelationTable->item(row,2)->text().toInt();
    int oldComputerID = ui->RelationTable->item(row,3)->text().toInt();

    Relation oldRelation(oldScientistID, oldComputerID, oldScientistName, oldComputerName);


    return _service.requestRelationEdit(scientistID, computerID, oldRelation);

}

/*Function deleteRelations @return bool
 *checks what relation is selected in the relationTable
 * passes the information about it to the deleteRelation function in the service layer
 * returns true if relation was deleted
 */

bool MainWindow::deleteRelations()
{
    int row = ui->RelationTable->currentRow();

    string deleteScientistName = ui->RelationTable->item(row, 0)->text().toStdString();
    string deleteComputerName = ui->RelationTable->item(row, 1)->text().toStdString();
    int deleteScientistID = ui->RelationTable->item(row,2)->text().toInt();
    int deleteComputerID = ui->RelationTable->item(row,3)->text().toInt();

    Relation deleteRelation(deleteScientistID, deleteComputerID, deleteScientistName, deleteComputerName);

    return _service.requestRelationDelete(deleteRelation);
}

/* Function fillLegendRelationComboBox @return void
 * Fills the scientist name combo box in the relation section
 *  with all Scientist names in the database
 */
void MainWindow::fillLegendRelationComboBox()
{
    vector<Legend> legends = _service.requestLegendSort();

    for(size_t i = 0; i < legends.size(); i++)
    {
        ui->RelationScientistName->addItem(QString::fromStdString(legends[i].getName()));
    }
}

/* Function fillComputerRelationComboBox @return void
 * Fills the computer name combo box in the relation section
 *  with all Computer names in the database
 */
void MainWindow::fillComputerRelationComboBox()
{
    QStringList list;

    vector<Computer> computers = _service.requestComputerSort();

    for(size_t i = 0; i < computers.size(); i++)
    {
        ui->RelationComputerName->insertItem(i, QString::fromStdString(computers[i].getName()));
    }

}


/*Function on_ButtonEditScientist_clicked
 * Is called when the ButtonEditScientist button is clicked
 * checks if the input is valid and then calls the editLegend function
 */
void MainWindow::on_ButtonEditScientist_clicked()
{
   if(addScientisInputIsValid())
   {
        if(editLegend())
        {
            ui->labelErrorEdidScienti->setText("");
            displayLegends(_service.requestLegendSort());
        }
        else
        {
            ui->labelErrorEdidScienti->setText("Error!! Scientist was not edited!");
        }
   }
    
    ui->ButtonEditScientist->setEnabled(false);
}

/*Function on_ScientistTable_cellClicked
 * Is called when row in the ScientistTable is clicked
 * puts the information about the selected scientist in
 * the appropriate text boxes or combo boxes.
 */
void MainWindow::on_ScientistTable_cellClicked()
{
    ui->ButtonEditScientist->setEnabled(true);
    ui->ButtonAddImage->setEnabled(true);

    int row = ui->ScientistTable->currentRow();

    ui->ScientistName->setText(ui->ScientistTable->item(row, 0)->text());
    ui->ScientistGender->setCurrentText(ui->ScientistTable->item(row, 1)->text());
    ui->ScientistBorn->setText(ui->ScientistTable->item(row, 2)->text());
    ui->ScientistDeath->setText(ui->ScientistTable->item(row, 3)->text());
    ui->ScientistBio->setText(ui->ScientistTable->item(row, 5)->text());

    displayPicture();
}

/*Function displayPicture, return @void
 * Puts a picture from a filePath in a label
 */
void MainWindow::displayPicture()
{
    QPixmap pixMap(getFilePath(false));

    QPixmap newPixmap = pixMap.scaled(QSize(150,350), Qt::KeepAspectRatio);

    ui->PictureLabel->setPixmap(newPixmap);
}

/*Function on_TableView_tabBarClicked @param int, @return void
 * is called when one of the tabs on the tab bar is clicked
 * takes a index witch tells the function what tab is selected.
 */
void MainWindow::on_TableView_tabBarClicked(int index)
{
    if(index == 0)
    {
        displayLegends(_service.requestLegendSort());
        whatTable = 0;
    }
    else if(index == 1)
    {
        displayComputers(_service.requestComputerSort());
        whatTable = 1;
    }
    else if(index == 2)
    {
        displayRelations(_service.requestRelationSort());
        ui->RelationComputerName->clear();
        ui->RelationScientistName->clear();
        fillLegendRelationComboBox();
        fillComputerRelationComboBox();
        whatTable = 2;
    }
}

/* Function on_ButtonAddComputer_clicked
* is called when the ButtonAddComputer button is clicked
* checks if it is possible to add the Computer and calls the addComputer function
*
*/
void MainWindow::on_ButtonAddComputer_clicked()
{
    if(addComputerInputIsValid())
    {
        if(addComputer())
        {
            ui->labelErrorEdidScienti->setText("");
            displayComputers(_service.requestComputerSort());
            ui->ComputerName->clear();
            ui->ComputerBuilt->clear();
        }
        else
        {
             ui->labelErrorComptuer->setText("Error!! Computer was not added!");
        }
    }
}

/* Function fillComputerTypeComboBox @return void
 * Fills the Computer Type combo box in the Computer section
 *  with all Computer Type names in the database
 */
void MainWindow::fillComputerTypeComboBox()
{
    vector<string> computerTypes = _service.requestComputerTypes();

    for(size_t i = 0; i < computerTypes.size(); i++)
    {
        ui->ComputerType->addItem(QString::fromStdString(computerTypes[i]));
    }

    ui->ComputerType->addItem(QString::fromStdString("Other"));
}

/*Function on_ButtonEditComputer_clicked
 * Is called when the ButtonEditComputer button is clicked
 * checks if the input is valid and then calls the editComputer function
 */
void MainWindow::on_ButtonEditComputer_clicked()
{
    ui->ButtonEditComputer->setEnabled(false);

    if(addComputerInputIsValid())
    {
        if(editComputer())
        {
            ui->labelErrorEditComputer->setText("");
            displayComputers(_service.requestComputerSort());
            ui->ComputerName->clear();
            ui->ComputerBuilt->clear();
        }
        else
        {
            ui->labelErrorEditComputer->setText("Error!! Computer was not edited!");
        }
    }

}

/*Function on_ComputerTable_cellClicked
 * Is called when row in the ComputerTable is clicked
 * puts the information about the selected computer in
 * the appropriate text boxes or combo boxes.
 */
void MainWindow::on_ComputerTable_cellClicked()
{
    ui->ButtonEditComputer->setEnabled(true);

    int row = ui->ComputerTable->currentRow();

    ui->ComputerName->setText(ui->ComputerTable->item(row, 0)->text());
    ui->ComputerBuilt->setText(ui->ComputerTable->item(row, 1)->text());
    ui->ComputerType->setCurrentText(ui->ComputerTable->item(row,2)->text());
    ui->ComputerBio->setText(ui->ComputerTable->item(row, 4)->text());
}

/* Function on_ButtonAddRelation_clicked
* is called when the ButtonAddRelation button is clicked
* calls the addRelation function
*/
void MainWindow::on_ButtonAddRelation_clicked()
{
    if(addRelation())
    {
        ui->labelErrorAddRelation->setText("");
        displayRelations(_service.requestRelationSort());
    }
    else
    {
        ui->labelErrorAddRelation->setText("Error!! Relation was not added!");
    }
}

/*Function on_RelationTable_cellClicked
 * Is called when row in the RelationTable is clicked
 * puts the information about the selected Relation in
 * the appropriate combo boxes.
 */
void MainWindow::on_RelationTable_cellClicked()
{
    ui->ButtonEditRelation->setEnabled(true);

    int row = ui->RelationTable->currentRow();

    ui->RelationScientistName->setCurrentText(ui->RelationTable->item(row, 0)->text());
    ui->RelationComputerName->setCurrentText(ui->RelationTable->item(row, 1)->text());
}

/*Function on_ButtonEditRelation_clicked
 * Is called when the ButtonEditRelation button is clicked
 * and then calls the editRelation function
 */
void MainWindow::on_ButtonEditRelation_clicked()
{
    ui->ButtonEditRelation->setEnabled(false);

    if(editRelations())
    {
        ui->labelErrorAddRelation->setText("");
        displayRelations(_service.requestRelationSort());
    }
    else
    {
         ui->labelErrorEditRelation->setText("Error!! Relation was not edited!");

    }
}

/*Function on_ButtonDeleteRelation_clicked
 * Is called when the ButtonDeleteRelation button is clicked
 * and then calls the deleteRelations function
 */
void MainWindow::on_ButtonDeleteRelation_clicked()
{
    if(deleteRelations())
    {
        ui->labelErrorAddRelation->setText("");
        displayRelations(_service.requestRelationSort());
    }
    else
    {
         ui->labelErrorDeleteRelation->setText("Error!! Relation was not delete!");
    }
}

/*Function addScientistInputIsValid @return bool
 * Checks if its valid to add scientist
 */
bool MainWindow::addScientisInputIsValid()
{
    bool isValid = true;

    if(ui->ScientistName->text().isEmpty())
    {
        ui->ScientistName->setPlaceholderText("Name cannot be empty");

        isValid = false;
    }
    if(ui->ScientistBorn->text().isEmpty())
    {
        ui->ScientistBorn->setPlaceholderText("Year born cannot be emty");

        isValid = false;
    }

    return isValid;
}
/*Function addComputerInputIsValid @return bool
 * Checks if its valid to add computer
 */
bool MainWindow::addComputerInputIsValid()
{
    bool isValid = true;

    if(ui->ComputerName->text().isEmpty())
    {
        ui->ComputerName->setPlaceholderText("Name cannot be empty");

        isValid = false;
    }

    return isValid;

}

/*Function on_JokeButton_clicked
 * is called when the Joke button is clicked
 * opens another PopUpWindow.
 */
void MainWindow::on_JokeButton_clicked()
{
    PopUpJoke  *joke = new PopUpJoke(_service.getJoke());

    joke->exec();

    delete joke;
}

/*Function on_ButtonQuit_clicked
 * is called when quit button is clicked
 * quits the application
 */
void MainWindow::on_ButtonQuit_clicked()
{
    exit(1);
}

/*Function getFilePath, @param bool, @return QString
 * returns the newFilePath of the scientist Image selected
 * sets the name of the image to the ID of the scientist
 */
QString MainWindow::getFilePath(bool justRemoved)
{
    QDir dir;

    dir.relativeFilePath("/Images/");

    QString path = dir.currentPath() + "/Images";

    QString newFilePath;

    newFilePath = path  + "/" +
                  ui->ScientistTable->item(ui->ScientistTable->currentRow(), 4)->text();

    QFile file(newFilePath);

    if(!file.exists() && !justRemoved)
    {
        newFilePath = path  + "/default";
    }

    return newFilePath;
}
/*Function on_ButtonAddImage_clicked
 * Is called when the ButtonAddImage button is clicked
 * opens a file dialog and copies the image selected in the
 * image folder witch keeps all the scientist Images
 */
void MainWindow::on_ButtonAddImage_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Import Image"),"C:/", "Jpg Files(*.jpg);;Png Files(*.png)");

    QFile newFile(filePath);

    QFileInfo newInfo(newFile);

    bool justRemoved = false;

    QFile oldFile(getFilePath(justRemoved));

    QFileInfo oldInfo(oldFile);


    if(oldFile.exists() && oldInfo.fileName() != "default" && !filePath.isEmpty())
    {
        justRemoved = true;

        oldFile.remove();
    }
    else
    {
        justRemoved = true;
    }


    QFile::copy(filePath,getFilePath(justRemoved));
    displayPicture();
}

/*Function on_ButtonClearScientist_clicked
 * Is called when ButtonClearScientist button is clicked
 * clears the text boxes and image
 */
void MainWindow::on_ButtonClearScientist_clicked()
{
    ui->ScientistName->clear();
    ui->ScientistBorn->clear();
    ui->ScientistDeath->clear();
    ui->ScientistBio->clear();
    ui->ButtonEditScientist->setEnabled(false);

    QPixmap defaultPixmap(":/Images/default.png");

    QPixmap newPixmap = defaultPixmap.scaled(QSize(150,350), Qt::KeepAspectRatio);

    ui->PictureLabel->setPixmap(newPixmap);
}
/*Function on_ButtonClearComputer_clicked
 * Is called when ButtonClearComputer button is clicked
 * clears the text boxes and image
 */
void MainWindow::on_ButtonClearComputer_clicked()
{
    ui->ComputerName->clear();
    ui->ComputerBuilt->clear();
    ui->ComputerBio->clear();
    ui->ButtonEditComputer->setEnabled(false);
}
