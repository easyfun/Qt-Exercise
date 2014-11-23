#include "mainwindow.h"
#include<QtGui>

static const char* const listEntries[]={
    QT_TRANSLATE_NOOP("MainWindow","First"),
    QT_TRANSLATE_NOOP("MainWindow","Second"),
    QT_TRANSLATE_NOOP("MainWindow","Third"),
    0
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget=new QWidget;
    setCentralWidget(centralWidget);

    createGroupBox();

    listWidget=new QListWidget;
    for (int i=0; listEntries[i]; i++)
    {
        listWidget->addItem(tr(listEntries[i]));
    }

    QVBoxLayout* mainLayout=new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(listWidget);
    centralWidget->setLayout(mainLayout);

    exitAction=new QAction(tr("E&xit"), this);
    connect( exitAction, SIGNAL( triggered() ), qApp, SLOT( quit() ) );

    fileMenu=menuBar()->addMenu(tr("&File"));
    fileMenu->setPalette(QPalette(Qt::red));
    fileMenu->addAction(exitAction);

    setWindowTitle(tr("Language: %1").arg(tr("English")));
    statusBar()->showMessage(tr("Internationalization Example"));

    if (tr("LTR")=="RTL")
    {
        setLayoutDirection(Qt::RightToLeft);
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::createGroupBox()
{
    groupBox=new QGroupBox(tr("View"));
    perspectiveRadioButton = new QRadioButton(tr("Perspective"));
    isometrickRadioButton = new QRadioButton(tr("Isometric"));
    obliqueRadioButton = new QRadioButton(tr("Oblique"));
    perspectiveRadioButton->setChecked(true);

    QVBoxLayout* groupBoxLayout=new QVBoxLayout;
    groupBoxLayout->addWidget(perspectiveRadioButton);
    groupBoxLayout->addWidget(isometrickRadioButton);
    groupBoxLayout->addWidget(obliqueRadioButton);
    groupBox->setLayout(groupBoxLayout);
}
