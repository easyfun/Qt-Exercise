#ifndef STACKLAYOUT_H
#define STACKLAYOUT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QListWidget;
class QStackedLayout;
class QStackedWidget;
class QSplitter;
class QLabel;
QT_END_NAMESPACE

class StackLayout : public QMainWindow
{
    Q_OBJECT
public:
    explicit StackLayout(QWidget *parent = 0);

signals:

public slots:

private:
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QLabel *pageStockTrade;
    QLabel *pageNuclearTechnology;
};

#endif // STACKLAYOUT_H
