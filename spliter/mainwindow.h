#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTableWidget;
class QTextEdit;
class QSplitter;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTreeWidget* treeWidget;
    QTableWidget* tableWidget;
    QTextEdit* textEdit;

};

#endif // MAINWINDOW_H
