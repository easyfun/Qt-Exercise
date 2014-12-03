#include "dialog.h"
#include <QtGui>

Dialog::Dialog(QWidget *parent)
    : QMainWindow(parent)
{
    listWidget = new QListWidget;
    listWidget->addItem(tr("Math"));
    listWidget->addItem(tr("English"));

    pageMath = new QLabel(tr("Math"));
    pageEnglish = new QLabel(tr("English"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(pageMath);
    stackedWidget->addWidget(pageEnglish);
    stackedWidget->setMinimumWidth(500);

    QSplitter *mainSplitter = new QSplitter;
    mainSplitter->addWidget(listWidget);
    mainSplitter->addWidget(stackedWidget);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    setCentralWidget(mainSplitter);
    resize(800, 600);
}

Dialog::~Dialog()
{

}
