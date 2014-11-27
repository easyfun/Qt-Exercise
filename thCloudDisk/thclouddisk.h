#ifndef THCLOUDDISK_H
#define THCLOUDDISK_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QToolBar;
class QStatusBar;
class QWidget;
class QVBoxLayout;
QT_END_NAMESPACE

// http://www.cnblogs.com/appsucc/archive/2012/03/28/2421225.html
class ThCloudDisk : public QFrame
{
    Q_OBJECT

public:
    ThCloudDisk(bool haveTitleBar = false, bool haveToolBar = false, bool haveStatusBar = false, QWidget *parent = 0);
    ~ThCloudDisk();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    bool    leftMousePress;
    QPoint  leftTopPosition;

    QToolBar    *thToolBar;
    QStatusBar  *thStatusBar;
    QWidget     *thCentralWidget;
//    QVBoxLayout* mainLayout;
};

#endif // THCLOUDDISK_H
