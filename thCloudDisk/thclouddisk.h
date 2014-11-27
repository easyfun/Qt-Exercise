#ifndef THCLOUDDISK_H
#define THCLOUDDISK_H

#include <QMainWindow>

class ThCloudDisk : public QMainWindow
{
    Q_OBJECT

public:
    ThCloudDisk(QWidget *parent = 0);
    ~ThCloudDisk();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    bool    leftMousePress;
    QPoint  leftTopPosition;
};

#endif // THCLOUDDISK_H
