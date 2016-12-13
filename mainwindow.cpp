#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _service.setCaseField(4);
    displayLegends(_service.requestLegendSort());
    displayComputers(_service.requestComputerSort());
    displayRelations(_service.requestRelationSort());
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
    ui->ComputerTable->clear();
    ui->ComputerTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->ComputerTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Build Year"));
    ui->ComputerTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Computer Type"));
    ui->ComputerTable->showColumn(2);
    ui->ComputerTable->hideColumn(3);
    ui->ComputerTable->setRowCount(computers.size());

    for(size_t row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString buildYear = QString::number(currentComputer.getBuildYear());
        QString computerType = QString::fromStdString(currentComputer.getComputerType());

        ui->ComputerTable->setItem(row,0, new QTableWidgetItem(name));
        ui->ComputerTable->setItem(row,1, new QTableWidgetItem(buildYear));
        ui->ComputerTable->setItem(row,2, new QTableWidgetItem(computerType));
    }
}
void MainWindow::displayRelations(vector<Relation> relations)
{
    ui->RelationTable->clear();
    ui->RelationTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Scientist Name"));
    ui->RelationTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Computer Name"));
    ui->RelationTable->hideColumn(2);
    ui->RelationTable->hideColumn(3);
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
        displayRelations(_service.requestRelationSearch());
    }
    else if(whatTable == 2)
    {
        displayComputers(_service.requestComputerSearch());
    }

}

bool MainWindow::addLegend()
{
    string name = ui->addName->text().toStdString();
    string gender = ui->addGender->currentText().toStdString();
    int born = ui->addBorn->text().toInt();
    int death = ui->addDeath->text().toInt();

    return _service.requestLegendAdd(name, gender[0], born, death);

}


void MainWindow::on_AddLegend_clicked()
{
    if(addLegend())
    {
        displayLegends(_service.requestLegendSort());
        ui->addName->clear();
        ui->addBorn->clear();
        ui->addDeath->clear();
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

    _service.setCaseField(4);

    Legend oldLegend = _service.requestLegendSort()[index];

    string name = ui->EditName->text().toStdString();
    string gender = ui->EditGender->currentText().toStdString();
    int born = ui->EditBorn->text().toInt();
    int death = ui->EditDeath->text().toInt();

    return _service.requestLegendEdit(name,gender[0],born,death,oldLegend);
}

void MainWindow::on_EditButton_clicked()
{
    if(editLegend())
    {
        _service.setCaseField(4);
        displayLegends(_service.requestLegendSort());
    }
    else
    {
        //TODO:
        qDebug() << "ERROR";
    }
    ui->EditName->setEnabled(false);
    ui->EditGender->setEnabled(false);
    ui->EditBorn->setEnabled(false);
    ui->EditDeath->setEnabled(false);
    ui->EditButton->setEnabled(false);

}

void MainWindow::on_ScientistTable_cellClicked()
{
    ui->EditName->setEnabled(true);
    ui->EditGender->setEnabled(true);
    ui->EditBorn->setEnabled(true);
    ui->EditDeath->setEnabled(true);
    ui->EditButton->setEnabled(true);

    int row = ui->ScientistTable->currentRow();

    int index = ui->ScientistTable->item(row,4)->text().toInt();


    _service.setCaseField(4);

    Legend oldLegend = _service.requestLegendSort()[index];

    ui->EditName->setText(QString::fromStdString(oldLegend.getName()));
    ui->EditGender->setCurrentText(QChar::fromLatin1(oldLegend.getGender()));
    ui->EditBorn->setText(QString::number(oldLegend.getBorn()));
    ui->EditDeath->setText(QString::number(oldLegend.getDeath()));
}

void MainWindow::on_Relations_tabBarClicked(int index)
{
    if(index == 0)
    {
        _service.setCaseField(4);
        displayLegends(_service.requestLegendSort());
        whatTable = 0;
    }
    else if(index == 1)
    {
        _service.setCaseField(3);
        displayComputers(_service.requestComputerSort());
        whatTable = 1;
    }
    else if(index == 2)
    {
        _service.setCaseField(3);
        displayRelations(_service.requestRelationSort());
        whatTable = 2;
    }
}