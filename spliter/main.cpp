#include "mainwindow.h"
#include <QApplication>
#include "stacklayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    StackLayout w;
    w.show();

    return a.exec();
}
