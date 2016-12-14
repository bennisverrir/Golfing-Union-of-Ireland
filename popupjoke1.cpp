#include "popupjoke.h"
#include "ui_popupjoke.h"
#include "service.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

PopUpJoke::PopUpJoke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpJoke)
{
    ui->setupUi(this);
}

PopUpJoke::~PopUpJoke()
{
    delete ui;
}

void PopUpJoke::on_pushButton_getANewJoke_clicked()
{

    ui->textEdit_joke->setText(QString::fromStdString(_service.getJoke()));

}




