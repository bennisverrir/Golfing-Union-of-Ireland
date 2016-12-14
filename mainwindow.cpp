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
    ui->ScientistTable->hideColumn(4);
    ui->ScientistTable->setRowCount(legends.size());

    for(size_t row = 0; row < legends.size(); row++)
    {
        Legend currentLegend = legends[row];

        QString name = QString::fromStdString(currentLegend.getName());
        QChar gender = QChar::fromLatin1(currentLegend.getGender());
        QString born = QString::number(currentLegend.getBorn());
        QString death = QString::number(currentLegend.getDeath());
        QString ID = QString::number(row);

        ui->ScientistTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ScientistTable->setItem(row,1, new QTableWidgetItem(gender));
        ui->ScientistTable->setItem(row,2, new QTableWidgetItem(born));
        ui->ScientistTable->setItem(row,3, new QTableWidgetItem(death));
        ui->ScientistTable->setItem(row,4, new QTableWidgetItem(ID));
    }
}
void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->hideColumn(3);
    ui->ComputerTable->setRowCount(computers.size());

    for(size_t row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString buildYear = QString::number(currentComputer.getBuildYear());
        QString computerType = QString::fromStdString(currentComputer.getComputerType());
        QString ID = QString::number(row);

        ui->ComputerTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ComputerTable->setItem(row,1, new QTableWidgetItem(buildYear));
        ui->ComputerTable->setItem(row,2, new QTableWidgetItem(computerType));
        ui->ComputerTable->setItem(row,3, new QTableWidgetItem(ID));
    }
}
void MainWindow::displayRelations(vector<Relation> relations)
{
    ui->RelationTable->clear();
    ui->RelationTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Scientist Name"));
    ui->RelationTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Computer Name"));
    ui->RelationTable->setRowCount(relations.size());

    for(size_t row = 0; row < relations.size(); row++)
    {
        Relation currentRelation = relations[row];

        QString scientistName = QString::fromStdString(currentRelation.getLegendName());
        QString computerName = QString::fromStdString(currentRelation.getComputerName());

        ui->RelationTable->setItem(row,0, new QTableWidgetItem(scientistName));
        ui->RelationTable->setItem(row,1, new QTableWidgetItem(computerName));
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
   // string name = ui->relationScientistCombo->currentText().toStdString();

}

void MainWindow::on_ButtonAddScientist_clicked()
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

bool MainWindow::editLegend()
{
    int index = ui->ScientistTable->currentRow();

    Legend oldLegend = _service.requestLegendSort()[index];

    string name = ui->ScientistName->text().toStdString();
    string gender = ui->ScientistGender->currentText().toStdString();
    int born = ui->ScientistBorn->text().toInt();
    int death = ui->ScientistDeath->text().toInt();

    return _service.requestLegendEdit(name,gender[0],born,death,oldLegend);
}

bool MainWindow::editComputer()
{
    int index = ui->ComputerTable->currentRow();

    Computer oldComputer = _service.requestComputerSort()[index];

    string name = ui->ComputerName->text().toStdString();
    int buildYear = ui->ComputerBuilt->text().toInt();
    string computerType = ui->ComputerType->currentText().toStdString();
    int computerTypeID = ui->ComputerType->currentIndex() + 1;

    int wasBuilt = (buildYear == 0? 0 : 1);

    return _service.requestComputerEdit(name, buildYear, computerType, wasBuilt, oldComputer, computerTypeID);
}

bool MainWindow::editRelations()
{

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

    int index = ui->ScientistTable->item(row,4)->text().toInt();

    Legend oldLegend = _service.requestLegendSort()[index];

    ui->ScientistName->setText(QString::fromStdString(oldLegend.getName()));
    ui->ScientistGender->setCurrentText(QChar::fromLatin1(oldLegend.getGender()));
    ui->ScientistBorn->setText(QString::number(oldLegend.getBorn()));
    ui->ScientistDeath->setText(QString::number(oldLegend.getDeath()));
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
        fillLegendRelationComboBox();
        fillComputerTypeComboBox();
        whatTable = 2;
    }

    ui->ScientistTable->setSortingEnabled(true);
    ui->ComputerTable->setSortingEnabled(true);
    ui->RelationTable->setSortingEnabled(true);
}

void MainWindow::on_ButtonAddComputer_clicked()
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

void MainWindow::fillComputerTypeComboBox()
{
    vector<string> computerTypes = _service.requestComputerTypes();

    for(size_t i = 0; i < computerTypes.size(); i++)
    {
        ui->ComputerType->addItem(QString::fromStdString(computerTypes[i]));
    }
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

    int index = ui->ComputerTable->item(row,3)->text().toInt();


    Computer oldComputer = _service.requestComputerSort()[index];

    ui->ComputerName->setText(QString::fromStdString(oldComputer.getName()));
    ui->ComputerBuilt->setText(QString::number(oldComputer.getBuildYear()));
    ui->ComputerType->setCurrentText(QString::fromStdString(oldComputer.getComputerType()));
}
