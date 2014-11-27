#include "mainwindow.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter* rightSplitter = new QSplitter(Qt::Vertical);
    tableWidget = new QTableWidget;
    tableWidget->setStyleSheet("background-color:red;");
    textEdit = new QTextEdit;
    textEdit->setStyleSheet("background-color:black;");
    rightSplitter->addWidget(tableWidget);
    rightSplitter->addWidget(textEdit);
    rightSplitter->setStretchFactor(0,0);
    rightSplitter->setHandleWidth(1);

    QSplitter* mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->setStyleSheet("background-color:yellow;border:0px");
    treeWidget = new QTreeWidget;
    treeWidget->setStyleSheet("background-color:blue;");
    mainSplitter->addWidget(treeWidget);
    mainSplitter->addWidget(rightSplitter);
    mainSplitter->setStretchFactor(0,0);
    mainSplitter->setHandleWidth(1);

    setCentralWidget(mainSplitter);
    setWindowTitle(tr("Splitter"));
}

MainWindow::~MainWindow()
{

}
