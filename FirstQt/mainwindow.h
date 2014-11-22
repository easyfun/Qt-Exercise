#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QGroupBox;
class QLabel;
class QListWidget;
class QMenu;
class QRadioButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createGroupBox();

private:
    QWidget* centralWidget;
    QLabel* label;
    QGroupBox* groupBox;
    QListWidget* listWidget;
    QRadioButton* perspectiveRadioButton;
    QRadioButton* isometrickRadioButton;
    QRadioButton* obliqueRadioButton;
    QMenu* fileMenu;
    QAction* exitAction;
};

#endif // MAINWINDOW_H
