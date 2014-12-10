#ifndef THFRAME_H
#define THFRAME_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QToolBar;
class QStatusBar;
class QWidget;
class QVBoxLayout;
class QLabel;
QT_END_NAMESPACE
class ThTitleBar;

class ThFrame : public QFrame
{
    Q_OBJECT
public:
    explicit ThFrame(QWidget *parent = 0);

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

public:
    enum DragDirection
    {
        eLeft = 0,
        eRight,
        eTop,
        eBottom,
        eTopLeft,
        eTopRight,
        eBottomLeft,
        eBottomRight,
        eNormal
    };

private:
    void initData();
    void initUI();
    void initConnect();


    // 伸缩窗口大小鼠标样式
    void setCursorStyle(DragDirection edirection);

    // 获得伸缩方向
    DragDirection getDragDirection(int x, int y);

    // 伸缩窗口
    void dragThFrame(int x, int y, DragDirection edirection);

private:
    bool    leftMousePress;
    QPoint  globalStartPosition;
    DragDirection edragDirection;

    ThTitleBar  *thTitleBar;
    QStatusBar  *thStatusBar;
    QWidget     *thCentralWidget;
    QLabel      *labelPoint;

};

#endif // THFRAME_H
