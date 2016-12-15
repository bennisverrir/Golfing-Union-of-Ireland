#include "popupjoke.h"

PopUpJoke::PopUpJoke(vector<string> jokes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpJoke)
{
    ui->setupUi(this);

    _jokes = jokes;

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
    string joke = _jokes[rand() % _jokes.size()];

    ui->textEdit_Joke->setText(QString::fromStdString(joke));
}
