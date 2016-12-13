#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _service.setCaseField(4);
    displayLegends(_service.requestLegendSort());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayLegends(vector<Legend> legends)
{
    whatTable = 0;

    whatTable = 1;

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Birth Year"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Death Year"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("ID"));
    ui->tableWidget->showColumn(2);
    ui->tableWidget->showColumn(3);
    ui->tableWidget->hideColumn(4);
    ui->tableWidget->setRowCount(legends.size());

    for(size_t row = 0; row < legends.size(); row++)
    {
        Legend currentLegend = legends[row];

        QString name = QString::fromStdString(currentLegend.getName());
        QChar gender = QChar::fromLatin1(currentLegend.getGender());
        QString born = QString::number(currentLegend.getBorn());
        QString death = QString::number(currentLegend.getDeath());
        QString ID = QString::number(row);

        ui->tableWidget->setItem(row,0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(gender));
        ui->tableWidget->setItem(row,2, new QTableWidgetItem(born));
        ui->tableWidget->setItem(row,3, new QTableWidgetItem(death));
        ui->tableWidget->setItem(row,4, new QTableWidgetItem(ID));
    }
}
void MainWindow::displayComputers(vector<Computer> computers)
{
    whatTable = 3;

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Build Year"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Computer Type"));
    ui->tableWidget->showColumn(2);
    ui->tableWidget->hideColumn(3);
    ui->tableWidget->setRowCount(computers.size());

    for(size_t row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString buildYear = QString::number(currentComputer.getBuildYear());
        QString computerType = QString::fromStdString(currentComputer.getComputerType());

        ui->tableWidget->setItem(row,0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(buildYear));
        ui->tableWidget->setItem(row,2, new QTableWidgetItem(computerType));
    }
}
void MainWindow::displayRelations(vector<Relation> relations)
{
    whatTable = 2;

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Scientist Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Computer Name"));
    ui->tableWidget->hideColumn(2);
    ui->tableWidget->hideColumn(3);
    ui->tableWidget->setRowCount(relations.size());

    for(size_t row = 0; row < relations.size(); row++)
    {
        Relation currentRelation = relations[row];

        QString scientistName = QString::fromStdString(currentRelation.getLegendName());
        QString computerName = QString::fromStdString(currentRelation.getComputerName());

        ui->tableWidget->setItem(row,0, new QTableWidgetItem(scientistName));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(computerName));

    }
}

void MainWindow::on_findText_textChanged(const QString &arg1)
{
    string nameToFind = ui->findText->text().toStdString();\

    _service.setCaseField(1);
    _service.setSearchField(nameToFind);

    if(whatTable == 1)
    {
        displayLegends(_service.requestLegendSearch());
    }
    else if(whatTable == 2)
    {
        displayRelations(_service.requestRelationSearch());
    }
    else if(whatTable == 3)
    {
        displayComputers(_service.requestComputerSearch());
    }

}

void MainWindow::on_LegendButton_clicked()
{
    _service.setCaseField(4);
    displayLegends(_service.requestLegendSort());
}

void MainWindow::on_ComputerButton_clicked()
{
    _service.setCaseField(1);
    displayComputers(_service.requestComputerSort());
}

void MainWindow::on_RelationButton_clicked()
{
    _service.setCaseField(1);
    displayRelations(_service.requestRelationSort());

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
    int index = ui->tableWidget->currentRow();

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

void MainWindow::on_tableWidget_cellClicked()
{
    ui->EditName->setEnabled(true);
    ui->EditGender->setEnabled(true);
    ui->EditBorn->setEnabled(true);
    ui->EditDeath->setEnabled(true);
    ui->EditButton->setEnabled(true);

    int row = ui->tableWidget->currentRow();

    int index = ui->tableWidget->item(row,4)->text().toInt();

    qDebug() << "ROW: " << row << "COLUMN " << index;

    _service.setCaseField(4);

    Legend oldLegend = _service.requestLegendSort()[index];

    ui->EditName->setText(QString::fromStdString(oldLegend.getName()));
    ui->EditGender->setCurrentText(QChar::fromLatin1(oldLegend.getGender()));
    ui->EditBorn->setText(QString::number(oldLegend.getBorn()));
    ui->EditDeath->setText(QString::number(oldLegend.getDeath()));
}
