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

/*Function on_GetANewJoke_clicked
 * is called when GetANewJoke button is clicked
 * calls the printJoke function
 */
void PopUpJoke::on_GetANewJoke_clicked()
{
    printJoke();
}
/* Function printJoke @return void
 * prints a random joke from the jokes in the database
 */
void PopUpJoke::printJoke()
{
    string joke = _jokes[rand() % _jokes.size()];

    ui->textEdit_Joke->setText(QString::fromStdString(joke));
}
