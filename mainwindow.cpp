#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    ui->ScientistTable->clear();
    ui->ScientistTable->hideColumn(4);
    ui->ScientistTable->setRowCount(legends.size());

    for(size_t row = 0; row < legends.size(); row++)
    {
        Legend currentLegend = legends[row];

        QString name = QString::fromStdString(currentLegend.getName());
        QChar gender = QChar::fromLatin1(currentLegend.getGender());
        QString born = QString::number(currentLegend.getBorn());
        QString death = QString::number(currentLegend.getDeath());
        QString ID = QString::number(currentLegend.getID());

        ui->ScientistTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ScientistTable->setItem(row,1, new QTableWidgetItem(gender));
        ui->ScientistTable->setItem(row,2, new QTableWidgetItem(born));
        ui->ScientistTable->setItem(row,3, new QTableWidgetItem(death));
        ui->ScientistTable->setItem(row,4, new QTableWidgetItem(ID));
    }
}
void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->clear();
    ui->ComputerTable->hideColumn(3);
    ui->ComputerTable->setRowCount(computers.size());

    for(size_t row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString buildYear = QString::number(currentComputer.getBuildYear());
        QString computerType = QString::fromStdString(currentComputer.getComputerType());
        QString ID = QString::number(currentComputer.getID());

        ui->ComputerTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ComputerTable->setItem(row,1, new QTableWidgetItem(buildYear));
        ui->ComputerTable->setItem(row,2, new QTableWidgetItem(computerType));
        ui->ComputerTable->setItem(row,3, new QTableWidgetItem(ID));
    }
}
void MainWindow::displayRelations(vector<Relation> relations)
{
    ui->RelationTable->clear();
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

    return _service.requestLegendAdd(name, gender[0], born, death);
}

bool MainWindow::addComputer()
{
    string name = ui->ComputerName->text().toStdString();
    int buildYear = ui->ComputerBuilt->text().toInt();
    string computerType = ui->ComputerType->currentText().toStdString();
    int computerTypeID = ui->ComputerType->currentIndex() + 1;

    qDebug() << computerTypeID;

    int wasBuilt = (buildYear == 0 ? 0 : 1);

    return _service.requestComputerAdd(name,buildYear,computerType,wasBuilt, computerTypeID);
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
            displayLegends(_service.requestLegendSort());
            ui->ScientistName->clear();
            ui->ScientistBorn->clear();
            ui->ScientistDeath->clear();
        }
        else
        {
            //TODO:
            qDebug() << "ERROR";
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

    qDebug() << "OLDID" << oldID;

    Legend oldLegend(oldID, oldName, oldGender[0], oldBorn, oldDeath);

    string name = ui->ScientistName->text().toStdString();
    string gender = ui->ScientistGender->currentText().toStdString();
    int born = ui->ScientistBorn->text().toInt();
    int death = ui->ScientistDeath->text().toInt();

    return _service.requestLegendEdit(name,gender[0],born,death,oldLegend);
}

bool MainWindow::editComputer()
{
    int row = ui->ComputerTable->currentRow();

    string oldName = ui->ComputerTable->item(row, 0)->text().toStdString();
    int oldBuildYear = ui->ComputerTable->item(row, 1)->text().toInt();
    bool oldWasBuilt = (oldBuildYear == 0 ? 0 : 1);
    string oldComputerType = ui->ComputerTable->item(row, 0)->text().toStdString();
    int oldID = ui->ComputerTable->item(row, 3)->text().toInt();

    Computer oldComputer(oldID,oldName,oldBuildYear, oldComputerType, oldWasBuilt);

    string name = ui->ComputerName->text().toStdString();
    int buildYear = ui->ComputerBuilt->text().toInt();
    string computerType = ui->ComputerType->currentText().toStdString();
    int computerTypeID = ui->ComputerType->currentIndex() + 1;

    int wasBuilt = (buildYear == 0? 0 : 1);

    return _service.requestComputerEdit(name, buildYear, computerType, wasBuilt, oldComputer, computerTypeID);
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
        //ui->RelationComputerName->setInsertPolicy(QComboBox::NoInsert);
        ui->RelationComputerName->insertItem(i, QString::fromStdString(computers[i].getName()));
    }

}

void MainWindow::on_ButtonEditScientist_clicked()
{
    if(editLegend())
    {
        displayLegends(_service.requestLegendSort());
    }
    else
    {
        //TODO:
        qDebug() << "ERROR";
    }
    ui->ButtonEditScientist->setEnabled(false);

}

void MainWindow::on_ScientistTable_cellClicked()
{
    ui->ButtonEditScientist->setEnabled(true);

    int row = ui->ScientistTable->currentRow();

    ui->ScientistName->setText(ui->ScientistTable->item(row, 0)->text());
    ui->ScientistGender->setCurrentText(ui->ScientistTable->item(row, 1)->text());
    ui->ScientistBorn->setText(ui->ScientistTable->item(row, 2)->text());
    ui->ScientistDeath->setText(ui->ScientistTable->item(row, 3)->text());
}

void MainWindow::on_TableView_tabBarClicked(int index)
{
    ui->ScientistTable->setSortingEnabled(false);
    ui->ComputerTable->setSortingEnabled(false);
    ui->RelationTable->setSortingEnabled(false);

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

    ui->ScientistTable->setSortingEnabled(true);
    ui->ComputerTable->setSortingEnabled(true);
    ui->RelationTable->setSortingEnabled(true);
}

void MainWindow::on_ButtonAddComputer_clicked()
{

    if(addComputerInputIsValid())
    {
        if(addComputer())
        {
            displayComputers(_service.requestComputerSort());
            ui->ComputerName->clear();
            ui->ComputerBuilt->clear();
        }
        else
        {
            //TODO
            qDebug() << "ERRORERROR";
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

    if(editComputer())
    {
        displayComputers(_service.requestComputerSort());
        ui->ComputerName->clear();
        ui->ComputerBuilt->clear();
    }
    else
    {
        //TODO
        qDebug() << "ERRORERROR";
    }

}

void MainWindow::on_ComputerTable_cellClicked()
{
    ui->ButtonEditComputer->setEnabled(true);

    int row = ui->ComputerTable->currentRow();

    ui->ComputerName->setText(ui->ComputerTable->item(row, 0)->text());
    ui->ComputerBuilt->setText(ui->ComputerTable->item(row, 1)->text());
    ui->ComputerType->setCurrentText(ui->ComputerTable->item(row,2)->text());
}

void MainWindow::on_ButtonAddRelation_clicked()
{
    if(addRelation())
    {
        displayRelations(_service.requestRelationSort());
    }
    else
    {
        //TODO:
        qDebug() << "ERRORERROR";
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
    if(editRelations())
    {
        displayRelations(_service.requestRelationSort());
    }
    else
    {
        //TODO:
        qDebug() << "ERRORERROR";
    }
}

void MainWindow::on_ButtonDeleteRelation_clicked()
{
    if(deleteRelations())
    {
        displayRelations(_service.requestRelationSort());
    }
    else
    {
        //TODO:
        qDebug() << "ERRORERROR";
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
