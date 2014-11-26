#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(mwApplication);

    QApplication a(argc, argv);
    a.setOrganizationName("TianHeYJB");
    a.setApplicationName("MainWindow Application");

    MainWindow w;
    w.show();

    return a.exec();
}
