#include "mainwindow.h"
#include <QApplication>

#include "languagechooser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    LanguageChooser chooser;
    chooser.show();
    return a.exec();
}
