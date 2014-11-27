#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    bool save();
    bool saveAs();

private:
    void createAction();
    void createMenu();
    void createToolBar();
    void createStatusBar();

    void readSettings();
    void writeSettings();
    bool maybeSave();
    void connectSignalSlot();

    void setCurrentFile(const QString& fileName);
    bool saveFile(const QString& fileName);

protected:
    void closeEvent(QCloseEvent *event);

private:
    QPlainTextEdit* textEdit;
    QString curFile;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
    QToolBar* fileToolBar;
    QToolBar* editToolBar;
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* saveAsAct;
    QAction* exitAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    QAction* aboutAct;
    QAction* aboutQtAct;
};

#endif // MAINWINDOW_H
