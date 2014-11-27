#include "thclouddisk.h"
#include <QtGui>

ThCloudDisk::ThCloudDisk(bool haveTitleBar, bool haveToolBar, bool haveStatusBar, QWidget *parent)
    : QFrame(parent)
{
    // init member data
    leftMousePress = false;

    // set up all child widgets
    if (haveTitleBar)
        ;

    if (haveToolBar){
        thToolBar = new QToolBar;
        thToolBar->setFixedHeight(40);
    }
    else{
        thToolBar = 0;
    }

    thCentralWidget = new QWidget;

    if (haveStatusBar){
        thStatusBar = new QStatusBar;
    }
    else{
        thStatusBar = 0;
    }

    QVBoxLayout* mainLayout = new QVBoxLayout;

    // set layout
    if ( haveTitleBar ){
        mainLayout->addWidget(thToolBar);
    }

    mainLayout->addWidget(thCentralWidget);

    if ( haveStatusBar ){
        mainLayout->addWidget(thStatusBar);
    }

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);

    // set mainwindow
    setGeometry(300, 300, 400, 300);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame {background-color:black;border:1px solid black;}");

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

    QFrame::mousePressEvent(event);
}

void ThCloudDisk::mouseReleaseEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = false;
    }

    QFrame::mouseReleaseEvent(event);
}

void ThCloudDisk::mouseMoveEvent(QMouseEvent *event)
{
    if (leftMousePress)
    {
        move(event->globalPos() - leftTopPosition);
    }

    QFrame::mouseMoveEvent(event);
}

void ThCloudDisk::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        qApp->quit();
        break;
    default:
        break;
    }

    QFrame::keyPressEvent(event);
}
