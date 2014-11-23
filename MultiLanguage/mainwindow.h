#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void chineseClick();
    void englshClick();

private:
    QWidget* centrallWidget;
    QLabel* labelTs;
    QPushButton* chineseButton;
    QPushButton* englshButton;
};

#endif // MAINWINDOW_H
