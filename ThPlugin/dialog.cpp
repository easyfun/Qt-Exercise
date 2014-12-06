#include "dialog.h"
#include <QtGui>
#include "./PageView/pageviewmath.h"
#include "./ThPluginCore/ThPuginCore.h"

Dialog::Dialog(QWidget *parent)
    : QMainWindow(parent)
{
    listWidget = new QListWidget;
    listWidget->addItem(tr("Math"));
    listWidget->addItem(tr("English"));
    listWidget->addItem(tr("PageViewMath"));

    pageMath = new QLabel(tr("Math"));
    pageEnglish = new QLabel(tr("English"));
    //pageViewMath = new PageViewMath;
    ThPluginClass* pThPlugin = (ThPluginClass *)&PageViewMath::thpluginclass;
    pageViewMath = (QWidget *)pThPlugin->createThPuginObject();

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(pageMath);
    stackedWidget->addWidget(pageEnglish);
    stackedWidget->addWidget(pageViewMath);
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
