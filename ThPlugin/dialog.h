#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QListWidget;
class QLabel;
class QStackedWidget;
QT_END_NAMESPACE

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QListWidget *listWidget;
    QLabel      *pageMath;
    QLabel      *pageEnglish;
    QStackedWidget  *stackedWidget;
};

#endif // DIALOG_H
