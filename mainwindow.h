#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "service.h"
#include "computer.h"
#include "legend.h"
#include "relation.h"
#include "popupjoke.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void displayLegends(vector<Legend> legends);

    void displayComputers(vector<Computer> computers);

    void displayRelations(vector<Relation> relations);

    void on_findText_textChanged(const QString &arg1);

    bool addLegend();

    bool addComputer();

    bool addRelation();

    bool editLegend();

    bool editComputer();

    bool editRelations();

    bool deleteRelations();

    void fillLegendRelationComboBox();

    void fillComputerRelationComboBox();

    void on_ButtonAddScientist_clicked();

    void on_ButtonEditScientist_clicked();

    void on_ScientistTable_cellClicked();

    void on_TableView_tabBarClicked(int index);

    void on_ButtonAddComputer_clicked();

    void fillComputerTypeComboBox();

    void on_ButtonEditComputer_clicked();

    void on_ComputerTable_cellClicked();

    void on_ButtonAddRelation_clicked();

    void on_RelationTable_cellClicked();

    void on_ButtonEditRelation_clicked();

    void on_ButtonDeleteRelation_clicked();

    bool addScientisInputIsValid();

    bool addComputerInputIsValid();

    void on_JokeButton_clicked();

    void on_ButtonQuit_clicked();

    void on_ButtonAddImage_clicked();

    QString getFilePath(bool justRemoved);

    void displayPicture();

private:
    Service _service;
    Ui::MainWindow *ui;
    int whatTable;

};

#endif // MAINWINDOW_H
