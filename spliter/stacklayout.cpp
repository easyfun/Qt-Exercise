#include "stacklayout.h"
#include<QtGui>

StackLayout::StackLayout(QWidget *parent) :
    QMainWindow(parent)
{
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);

    listWidget = new QListWidget;
    listWidget->addItem(tr("Stock Trade"));
    listWidget->addItem(tr("Nuclear Technology"));
//    listWidget->setMinimumWidth(80);
//    listWidget->setMaximumWidth(160);

    stackedWidget = new QStackedWidget;
    pageStockTrade = new QLabel(tr("Stock Trade"));
    pageNuclearTechnology = new QLabel(tr("Nuclear Technology"));

    stackedWidget->addWidget(pageStockTrade);
    stackedWidget->addWidget(pageNuclearTechnology);

    mainSplitter->addWidget(listWidget);
    mainSplitter->addWidget(stackedWidget);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    setCentralWidget(mainSplitter);
}
