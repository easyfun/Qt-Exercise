#include "testwidget.h"
#include<QtGui>

TestWidget::TestWidget(QFrame *parent) :
    QFrame(parent)
{
    labelPoint = new QLabel(tr("Point:x= y="), this);
    labelPoint->setMouseTracking(true);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelPoint);
    setLayout(mainLayout);

    setGeometry(100,100, 400, 400);
    setWindowFlags(Qt::FramelessWindowHint);
//    setMouseTracking(true);
}

void TestWidget::mouseMoveEvent(QMouseEvent *event)
{
    labelPoint->setText(tr("Point:x=%1 y=%2").arg(event->x()).arg(event->y()));
}

void TestWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        qApp->quit();
        break;
    default:
        break;
    }
}
