#include <QtGui>
#include "thframe.h"

ThFrame::ThFrame(QWidget *parent)
    : QFrame(parent)
{
    // init member data
    leftMousePress = false;

    // set up all child widgets
    thToolBar = new QToolBar;
    thToolBar->setFixedHeight(40);

    thCentralWidget = new QWidget;

    thStatusBar = new QStatusBar;

    QVBoxLayout* mainLayout = new QVBoxLayout;

    // set layout
    mainLayout->addWidget(thToolBar);
    mainLayout->addWidget(thCentralWidget);
    mainLayout->addWidget(thStatusBar);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);

    // set mainwindow
    setGeometry(300, 300, 400, 300);
    setWindowFlags(Qt::FramelessWindowHint);
//    setStyleSheet("QFrame {background-color:black;border:1px solid black;}");

}


void ThFrame::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = true;
        leftTopPosition = event->pos();
    }
    event->ignore();
//    QFrame::mousePressEvent(event);
}

void ThFrame::mouseReleaseEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = false;
    }
    event->ignore();
//    QFrame::mouseReleaseEvent(event);
}

void ThFrame::mouseMoveEvent(QMouseEvent *event)
{
    // 移动窗口
    if (leftMousePress)
    {
        move(event->globalPos() - leftTopPosition);
    }
    // 调整窗口大小
    else
    {
        edragDirection = getDragDirection(event->x(), event->y());
        setCursorStyle(edragDirection);
//        dragThFrame(edragDirection);
    }
    event->ignore();
//    QFrame::mouseMoveEvent(event);
}

void ThFrame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        qApp->quit();
        break;
    default:
        break;
    }

    QFrame::keyPressEvent(event);
}


void ThFrame::setCursorStyle(DragDirection eDirection)
{
    switch(eDirection)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;

    case eLeft:
    case eRight:
        setCursor(Qt::SizeHorCursor);
        break;

    case eTopLeft:
    case eBottomRight:
        setCursor(Qt::SizeBDiagCursor);
        break;

    case eTopRight:
    case eBottomLeft:
        setCursor(Qt::SizeFDiagCursor);
        break;

    case eNormal:
        setCursor(Qt::ArrowCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

ThFrame::DragDirection ThFrame::getDragDirection(int x, int y)
{
    QRect rect = frameGeometry();
    int left = rect.left();
    int right = rect.right();
    int top = rect.top();
    int bottom = rect.bottom();

    if (left-3 <= x && x <= left+3 && top-3 <= y && y <= top+3)
        return eTopLeft;

    if (left-3 <= x && x <= left+3 && top+3 <= y && y < bottom-3)
        return eLeft;

    if (left-3 <= x && x <= left+3 && bottom-3 <= y && y <= bottom+3)
        return eBottomLeft;

    if (left+3 < x && x < right-3 && top-3 <= y && y <= top+3)
        return eTop;

    if (left+3 < x && x < right-3 && bottom-3 <= y && y <= bottom+3)
        return eBottom;

    if (right-3 <= x && x <= right+3 && top-3 <= y && y <= top+3)
        return eTopLeft;

    if (right-3 <= x && x <= right+3 && top-3 < y && y < top+3)
        return eRight;

    if (right-3 <= x && x <= right+3 && bottom-3 <= y && y <= bottom+3)
        return eBottomRight;

    return eNormal;

}

void ThFrame::dragThFrame(DragDirection eDirection)
{

}
