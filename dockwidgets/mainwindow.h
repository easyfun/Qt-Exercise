#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTextEdit;
class QListWidget;
class QMenu;
class QAction;
class QToolBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createAction();
    void createMenu();
    void createToolBar();
    void createStatuBar();
    void createDockWidgets();

private:
    QTextEdit* textEdit;
    QListWidget* customerList;
    QListWidget* paragraphList;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* viewMenu;
    QMenu* helpMenu;

    QToolBar* fileToolBar;
    QToolBar* editToolBar;

    QAction* newLetterAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* quitAct;

    QAction* undoAct;

    QAction* aboutAct;
    QAction* aboutQtAct;
};

#endif // MAINWINDOW_H
