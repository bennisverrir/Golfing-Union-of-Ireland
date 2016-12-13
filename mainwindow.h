#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "service.h"
#include "computer.h"
#include "legend.h"
#include "relation.h"

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

    void on_ButtonAddScientist_clicked();

    void on_ButtonEditScientist_clicked();

    void on_ScientistTable_cellClicked();

    void on_TableView_tabBarClicked(int index);

    void on_ComputerAdd_clicked();

    void fillComputerTypeComboBox();

    void on_ComputerEdit_clicked();

    void on_ComputerTable_cellClicked();

private:
    Service _service;
    Ui::MainWindow *ui;
    int whatTable;
};

#endif // MAINWINDOW_H
