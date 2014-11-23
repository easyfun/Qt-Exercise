#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centrallWidget = new QWidget;
    setCentralWidget(centrallWidget);

    chineseButton = new QPushButton("Chinese", this);
    englshButton = new QPushButton("English", this);
    labelTs = new QLabel(tr("View"), this);

/*    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(chineseButton);
    buttonLayout->addWidget(chineseButton);
    buttonLayout->addWidget(englshButton);
*/
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chineseButton);
    mainLayout->addWidget(englshButton);
    mainLayout->addWidget(labelTs);
    centrallWidget->setLayout(mainLayout);
//    setLayout(mainLayout);
    setWindowTitle(tr("Multi Language Test"));

    connect(chineseButton, SIGNAL(clicked()),this,SLOT(chineseClick()));
    connect(englshButton, SIGNAL(clicked()),this,SLOT(englshClick()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::chineseClick()
{
    QTranslator translator;
    translator.load("E:\\yjbProjects\\c and c++\\Qt\\thbin\\translations\\i18n_zh.qm");
    qApp->installTranslator(&translator);

    labelTs->setText(tr("View"));
    chineseButton->setText(tr("English"));
    englshButton->setText(tr("English"));
}

void MainWindow::englshClick()
{
    QTranslator translator;
    translator.load("E:\\yjbProjects\\c and c++\\Qt\\thbin\\translations\\i18n_en.qm");
    qApp->installTranslator(&translator);

    labelTs->setText(tr("View"));
    chineseButton->setText(tr("English"));
    englshButton->setText(tr("English"));
}
