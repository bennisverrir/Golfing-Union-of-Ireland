#ifndef POPUPJOKE_H
#define POPUPJOKE_H

#include <QDialog>
#include <vector>
#include <cstdlib>
#include "ui_popupjoke.h"
#include "service.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class PopUpJoke;
}

class PopUpJoke : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpJoke(vector<string> jokes, QWidget *parent = 0);
    ~PopUpJoke();

private slots:
    void on_GetANewJoke_clicked();

    void printJoke();

private:

    vector<string> _jokes;
    Ui::PopUpJoke *ui;
};

#endif // POPUPJOKE_H
