#include "thclouddisk.h"
#include "thBasic/testwidget.h"
#include "thBasic/thframe.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThCloudDisk w;
    w.show();

//    TestWidget w;
//    w.show();

//    ThFrame w;
//    w.show();

    return a.exec();
}
