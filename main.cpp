#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool hitOk = false;

    QTranslator translator;

    QStringList languages;
    languages << "English" << "Íslenska";

    QInputDialog dialog;

    QString lang = dialog.getItem(NULL, "Language", "Select Language", languages,0,true, &hitOk);


    if(hitOk)
    {
        if(lang == "Íslenska")
        {
            translator.load(":/Languages/Islenska.qm");

        }
        a.installTranslator(&translator);
    }
    else
    {
        exit(1);
    }

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
