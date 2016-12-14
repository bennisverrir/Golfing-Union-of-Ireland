/********************************************************************************
** Form generated from reading UI file 'popupjoke.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPJOKE_H
#define UI_POPUPJOKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_PopUpJoke
{
public:
    QLabel *label_joke;
    QPushButton *pushButton_getANewJoke;
    QTextEdit *textEdit_joke;

    void setupUi(QDialog *PopUpJoke)
    {
        if (PopUpJoke->objectName().isEmpty())
            PopUpJoke->setObjectName(QStringLiteral("PopUpJoke"));
        PopUpJoke->resize(400, 300);
        label_joke = new QLabel(PopUpJoke);
        label_joke->setObjectName(QStringLiteral("label_joke"));
        label_joke->setGeometry(QRect(160, 30, 59, 16));
        pushButton_getANewJoke = new QPushButton(PopUpJoke);
        pushButton_getANewJoke->setObjectName(QStringLiteral("pushButton_getANewJoke"));
        pushButton_getANewJoke->setGeometry(QRect(90, 250, 151, 21));
        textEdit_joke = new QTextEdit(PopUpJoke);
        textEdit_joke->setObjectName(QStringLiteral("textEdit_joke"));
        textEdit_joke->setGeometry(QRect(100, 100, 171, 111));
        textEdit_joke->setReadOnly(true);

        retranslateUi(PopUpJoke);

        QMetaObject::connectSlotsByName(PopUpJoke);
    } // setupUi

    void retranslateUi(QDialog *PopUpJoke)
    {
        PopUpJoke->setWindowTitle(QApplication::translate("PopUpJoke", "Dialog", 0));
        label_joke->setText(QApplication::translate("PopUpJoke", "Joke", 0));
        pushButton_getANewJoke->setText(QApplication::translate("PopUpJoke", "New Joke", 0));
    } // retranslateUi

};

namespace Ui {
    class PopUpJoke: public Ui_PopUpJoke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPJOKE_H
