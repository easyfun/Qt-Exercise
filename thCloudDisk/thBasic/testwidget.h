#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class TestWidget : public QFrame
{
    Q_OBJECT
public:
    explicit TestWidget(QFrame *parent = 0);

signals:

public slots:

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QLabel *labelPoint;
};

#endif // TESTWIDGET_H
