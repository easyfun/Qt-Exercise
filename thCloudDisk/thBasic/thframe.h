#ifndef THFRAME_H
#define THFRAME_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QToolBar;
class QStatusBar;
class QWidget;
class QVBoxLayout;
QT_END_NAMESPACE

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
    // 伸缩窗口大小鼠标样式
    void setCursorStyle(DragDirection eDirection);

    // 获得伸缩方向
    DragDirection getDragDirection(int x, int y);

    // 伸缩窗口
    void dragThFrame(DragDirection eDirection);

private:
    bool    leftMousePress;
    QPoint  leftTopPosition;
    DragDirection edragDirection;

    QToolBar    *thToolBar;
    QStatusBar  *thStatusBar;
    QWidget     *thCentralWidget;

};

#endif // THFRAME_H
