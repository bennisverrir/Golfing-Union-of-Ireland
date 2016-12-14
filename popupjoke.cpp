#include "popupjoke.h"

PopUpJoke::PopUpJoke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpJoke)
{
    ui->setupUi(this);
    printJoke();
}

PopUpJoke::~PopUpJoke()
{
    delete ui;
}

void PopUpJoke::on_GetANewJoke_clicked()
{
    printJoke();
}

void PopUpJoke::printJoke()
{
    ui->textEdit_Joke->setText(QString::fromStdString(_service.getJoke()));
}
