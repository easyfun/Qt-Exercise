#include <QtGui>
#include "thframe.h"
#include "thtitlebar.h"

ThFrame::ThFrame(QWidget *parent)
    : QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void ThFrame::initData()
{
    // init member data
    leftMousePress = false;
    edragDirection = eNormal;
}

void ThFrame::initUI()
{
    // set up all child widgets
    thTitleBar = new ThTitleBar;
    thTitleBar->setMouseTracking(true);

    thCentralWidget = new QWidget;
    thCentralWidget->setMouseTracking(true);
    thStatusBar = new QStatusBar;
    thStatusBar->setMouseTracking(true);

    labelPoint = new QLabel(tr("Point:x=%1 y=%2"));
    labelPoint->setMouseTracking(true);

    QVBoxLayout* mainLayout = new QVBoxLayout;

    // set layout
    mainLayout->addWidget(thTitleBar);
    mainLayout->addWidget(labelPoint);
    mainLayout->addWidget(thCentralWidget);
    mainLayout->addWidget(thStatusBar);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);

    // set mainwindow
    setGeometry(100, 100, 800, 600);
    setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true);
//    setStyleSheet("QFrame {background-color:blue;border:0px solid white;}");

}

void ThFrame::initConnect()
{

}

void ThFrame::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = true;
        globalStartPosition = event->globalPos();
    }
    event->ignore();
}

void ThFrame::mouseReleaseEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        leftMousePress = false;
//        if (eNormal != edragDirection)
//        {
//            edragDirection = eNormal;
//            setCursorStyle(edragDirection);
//        }
    }
    event->ignore();
}

void ThFrame::mouseMoveEvent(QMouseEvent *event)
{
    // 移动窗口
    if (leftMousePress)
    {
        if (eNormal == edragDirection)
        {
            // 移动窗口
            QRect rectFrame = geometry();
            move(rectFrame.left()+event->globalX()-globalStartPosition.x(),
                 rectFrame.top()+event->globalY()-globalStartPosition.y());
            globalStartPosition = event->globalPos();
        }
        else
        {
            // 调整窗口大小
            dragThFrame(event->globalX(),event->globalY(),edragDirection);
            globalStartPosition = event->globalPos();//QPoint(event->globalX(), event->globalY());
        }
    }
    // 调整窗口大小
    else
    {
        edragDirection = getDragDirection(event->globalX(), event->globalY());
        setCursorStyle(edragDirection);
    }
    event->ignore();
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


void ThFrame::setCursorStyle(DragDirection edirection)
{
    switch(edirection)
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
        setCursor(Qt::SizeFDiagCursor);
        break;

    case eTopRight:
    case eBottomLeft:
        setCursor(Qt::SizeBDiagCursor);
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
    QRect rect = geometry();
    int left = rect.left();
    int right = rect.right();
    int top = rect.top();
    int bottom = rect.bottom();

/*    labelPoint->setText(tr("left=%1,right=%2,top=%3,bottom=%4,Point:x=%5,y=%6")
                        .arg(left)
                        .arg(right)
                        .arg(top)
                        .arg(bottom)
                        .arg(x)
                        .arg(y));*/

    if (left <= x && x <= left+1 && top <= y && y <= top+1)
        return eTopLeft;

    if (left <= x && x <= left+1 && top+1 < y && y < bottom-3)
        return eLeft;

    if (left <= x && x <= left+1 && bottom-1 <= y && y <= bottom)
        return eBottomLeft;


    if (left+3 < x && x < right-3 && top <= y && y <= top+1)
        return eTop;

    if (left+3 < x && x < right-3 && bottom-1 <= y && y <= bottom)
        return eBottom;


    if (right-1 <= x && x <= right && top <= y && y <= top+1)
        return eTopRight;

    if (right-1 <= x && x <= right && top+3 < y && y < bottom-3)
        return eRight;

    if (right-1 <= x && x <= right && bottom-3 <= y && y <= bottom)
        return eBottomRight;

    return eNormal;

}

void ThFrame::dragThFrame(int x, int y, DragDirection edirection)
{
    //计算偏差
    int dX = x - globalStartPosition.x();
    int dY = y - globalStartPosition.y();
    //获得主窗口位置信息
    QRect rectWindow = geometry();
    //判别方向
    if(edirection == eTop)
    {
        rectWindow.setTop(rectWindow.top()+dY);
    }
    else if(edirection == eBottom)
    {
        rectWindow.setBottom(rectWindow.bottom()+dY);
    }
    else if(edirection == eLeft)
    {
        rectWindow.setLeft(rectWindow.left()+dX);
    }
    else if(edirection == eRight)
    {
        rectWindow.setRight(rectWindow.right()+dX);
    }
    else if (edirection == eTopLeft)
    {
        rectWindow.setTop(rectWindow.top() + dY);
        rectWindow.setLeft(rectWindow.left() + dX);
    }
    else if (edirection == eBottomRight)
    {
        rectWindow.setBottom(rectWindow.bottom() + dY);
        rectWindow.setRight(rectWindow.right() + dX);
    }
    else if (edirection == eTopRight)
    {
        rectWindow.setTop(rectWindow.top() + dY);
        rectWindow.setRight(rectWindow.right() + dX);
    }
    else if (edirection == eBottomLeft)
    {
        rectWindow.setBottom(rectWindow.bottom() + dY);
        rectWindow.setLeft(rectWindow.left() + dX);
    }


    if(rectWindow.width()< minimumWidth() || rectWindow.height()<minimumHeight())
    {
        return;
    }

    // 重新设置窗口位置为新位置信息
    setGeometry(rectWindow);
}
