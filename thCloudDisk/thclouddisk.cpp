#include "thclouddisk.h"
#include <QtGui>

ThCloudDisk::ThCloudDisk(QWidget *parent)
    : QMainWindow(parent)
{
    leftMousePress = false;

    setGeometry(300, 300, 400, 300);
    setWindowFlags(Qt::FramelessWindowHint);
}

ThCloudDisk::~ThCloudDisk()
{

}

void ThCloudDisk::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = true;
        leftTopPosition = event->pos();
    }
}

void ThCloudDisk::mouseReleaseEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = false;
    }
}

void ThCloudDisk::mouseMoveEvent(QMouseEvent *event)
{
    if (leftMousePress)
    {
        move(event->globalPos() - leftTopPosition);
    }
}
