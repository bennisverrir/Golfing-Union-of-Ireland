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

    QFile defaultImage(":/Images/default");

    QFile::copy(defaultImage.fileName(), filePath);

    QPixmap defaultPixmap(filePath);

    ui->setupUi(this);

    whatTable = ui->TableView->currentIndex();

    qDebug() << whatTable;

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

void MainWindow::displayLegends(vector<Legend> legends)
{
    ui->ScientistTable->setSortingEnabled(false);

    ui->ScientistTable->clear();
    ui->ScientistTable->hideColumn(4);
    ui->ScientistTable->hideColumn(5);
    ui->ScientistTable->setRowCount(legends.size());

    ui->ScientistTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->ScientistTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->ScientistTable->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth Year"));
    ui->ScientistTable->setHorizontalHeaderItem(3,new QTableWidgetItem("Death Year"));

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
void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->setSortingEnabled(false);

    ui->ComputerTable->clear();
    ui->ComputerTable->hideColumn(3);
    ui->ComputerTable->hideColumn(4);
    ui->ComputerTable->setRowCount(computers.size());

    ui->ComputerTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->ComputerTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Build Year"));
    ui->ComputerTable->setHorizontalHeaderItem(2,new QTableWidgetItem("Computer Type"));

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
void MainWindow::displayRelations(vector<Relation> relations)
{
    ui->RelationTable->setSortingEnabled(false);

    ui->RelationTable->clear();
    ui->RelationTable->hideColumn(2);
    ui->RelationTable->hideColumn(3);
    ui->RelationTable->setRowCount(relations.size());

    ui->RelationTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Scientist Name"));
    ui->RelationTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Computer Name"));

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

bool MainWindow::addLegend()
{
    string name = ui->ScientistName->text().toStdString();
    string gender = ui->ScientistGender->currentText().toStdString();
    int born = ui->ScientistBorn->text().toInt();
    int death = ui->ScientistDeath->text().toInt();
    string bio = ui->ScientistBio->toPlainText().toStdString();

    return _service.requestLegendAdd(name, gender[0], born, death, bio);
}

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

bool MainWindow::addRelation()
{
   int scientistID = ui->RelationScientistName->currentIndex() + 1;
   int computerID = ui->RelationComputerName->currentIndex() + 1;

   return _service.requestRelationAdd(scientistID, computerID);
}

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

            ui->labelErrorScientist->setText("<span style='color: red'>Error!! Scientist was not added!</span>");
        }
    }
}

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

void MainWindow::fillLegendRelationComboBox()
{
    vector<Legend> legends = _service.requestLegendSort();

    for(size_t i = 0; i < legends.size(); i++)
    {
        ui->RelationScientistName->addItem(QString::fromStdString(legends[i].getName()));
    }
}

void MainWindow::fillComputerRelationComboBox()
{
    QStringList list;

    vector<Computer> computers = _service.requestComputerSort();

    for(size_t i = 0; i < computers.size(); i++)
    {
        ui->RelationComputerName->insertItem(i, QString::fromStdString(computers[i].getName()));
    }

}

void MainWindow::on_ButtonEditScientist_clicked()
{
    if(editLegend())
    {
        ui->labelErrorEdidScienti->setText("");
        displayLegends(_service.requestLegendSort());
    }
    else
    {
        ui->labelErrorEdidScienti->setText("<span style='color: red'>Error!! Scientist was not edited!</span>");
    }
    
    ui->ButtonEditScientist->setEnabled(false);
}

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

void MainWindow::displayPicture()
{
    QPixmap pixMap(getFilePath(false));

    QPixmap newPixmap = pixMap.scaled(QSize(300,500), Qt::KeepAspectRatio);

    ui->PictureLabel->setPixmap(newPixmap);
}

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
             ui->labelErrorComptuer->setText("<span style='color: red'>Error!! Computer was not added!</span>");
        }
    }
}

void MainWindow::fillComputerTypeComboBox()
{
    vector<string> computerTypes = _service.requestComputerTypes();

    for(size_t i = 0; i < computerTypes.size(); i++)
    {
        ui->ComputerType->addItem(QString::fromStdString(computerTypes[i]));
    }

    ui->ComputerType->addItem(QString::fromStdString("Other"));
}

void MainWindow::on_ButtonEditComputer_clicked()
{
    ui->ButtonEditComputer->setEnabled(false);

    if(editComputer())
    {
        ui->labelErrorEditComputer->setText("");
        displayComputers(_service.requestComputerSort());
        ui->ComputerName->clear();
        ui->ComputerBuilt->clear();
    }
    else
    {
        ui->labelErrorEditComputer->setText("<span style='color: red'>Error!! Computer was not edited!</span>");
    }

}

void MainWindow::on_ComputerTable_cellClicked()
{
    ui->ButtonEditComputer->setEnabled(true);

    int row = ui->ComputerTable->currentRow();

    ui->ComputerName->setText(ui->ComputerTable->item(row, 0)->text());
    ui->ComputerBuilt->setText(ui->ComputerTable->item(row, 1)->text());
    ui->ComputerType->setCurrentText(ui->ComputerTable->item(row,2)->text());
    ui->ComputerBio->setText(ui->ComputerTable->item(row, 4)->text());
}

void MainWindow::on_ButtonAddRelation_clicked()
{
    if(addRelation())
    {
        ui->labelErrorAddRelation->setText("");
        displayRelations(_service.requestRelationSort());
    }
    else
    {
        ui->labelErrorAddRelation->setText("<span style='color: red'>Error!! Relation was not added!</span>");
    }
}

void MainWindow::on_RelationTable_cellClicked()
{
    ui->ButtonEditRelation->setEnabled(true);

    int row = ui->RelationTable->currentRow();

    ui->RelationScientistName->setCurrentText(ui->RelationTable->item(row, 0)->text());
    ui->RelationComputerName->setCurrentText(ui->RelationTable->item(row, 1)->text());
}

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
         ui->labelErrorEditRelation->setText("<span style='color: red'>Error!! Relation was not edited!</span>");

    }
}

void MainWindow::on_ButtonDeleteRelation_clicked()
{
    if(deleteRelations())
    {
        ui->labelErrorAddRelation->setText("");
        displayRelations(_service.requestRelationSort());
    }
    else
    {
         ui->labelErrorDeleteRelation->setText("<span style='color: red'>Error!! Relation was not delete!</span>");
    }
}

bool MainWindow::addScientisInputIsValid()
{
    bool isValid = true;

    if(ui->ScientistName->text().isEmpty())
    {
        ui->ScientistName->setPlaceholderText("<span style = 'color: red'>Name cannot be empty</span>");

        isValid = false;
    }
    if(ui->ScientistBorn->text().isEmpty())
    {
        ui->ScientistBorn->setPlaceholderText("Year born cannot be emty");

        isValid = false;
    }

    return isValid;
}

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

void MainWindow::on_JokeButton_clicked()
{
    PopUpJoke  *joke = new PopUpJoke(_service.getJoke());

    joke->exec();

    delete joke;
}

void MainWindow::on_ButtonQuit_clicked()
{
    exit(1);
}

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

void MainWindow::on_ButtonAddImage_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Import Image"),"C:/", "Jpg Files(*.jpg);;Png Files(*.png)");

    QFile newFile(filePath);

    QFileInfo newInfo(newFile);

    bool justRemoved = false;

    QFile oldFile(getFilePath(justRemoved));

    QFileInfo oldInfo(oldFile);


    if(oldFile.exists() && oldInfo.fileName() != "default")
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

    ui->ButtonAddImage->setEnabled(false);
}

