#include <QtGui>

#include "languagechooser.h"
#include "mainwindow.h"

LanguageChooser::LanguageChooser(QWidget *parent) :
    QDialog(parent)
{
    groupBox = new QGroupBox("Languages");

    QGridLayout* groupBoxLayout = new QGridLayout;

    QStringList qmFiles=findQmFiles();
    for (int i=0; i<qmFiles.size(); i++)
    {
        QCheckBox* checkBox=new QCheckBox(languageName(qmFiles[i]));
        qmFileForCheckBoxMap.insert(checkBox, qmFiles[i]);
        groupBoxLayout->addWidget(checkBox,i/2,i%2);
        connect(checkBox,SIGNAL(toggled(bool)),this,SLOT(checkBoxToggled()));
    }
    groupBox->setLayout(groupBoxLayout);

    buttonBox=new QDialogButtonBox;
    showAllButton=buttonBox->addButton("show all", QDialogButtonBox::ActionRole);
    hideAllButton=buttonBox->addButton("hide all", QDialogButtonBox::ActionRole);

    connect(showAllButton,SIGNAL(clicked()),this,SLOT(showAll()));
    connect(hideAllButton,SIGNAL(clicked()),this,SLOT(hideAll()));

    QVBoxLayout* mainLayout=new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle("First Qt Application");
}

void LanguageChooser::checkBoxToggled()
{
    QCheckBox* checkBox=qobject_cast<QCheckBox* >(sender());
    MainWindow* window=mainWindowForCheckBoxMap[checkBox];
    if (!window)
    {
        QTranslator translator;
        translator.load(qmFileForCheckBoxMap[checkBox]);
        qApp->installTranslator(&translator);

        window=new MainWindow;
        window->setPalette(colorForLanguage(checkBox->text()));

        window->installEventFilter(this);
        mainWindowForCheckBoxMap.insert(checkBox, window);
    }
    window->setVisible(checkBox->isChecked());
}

QColor LanguageChooser::colorForLanguage(const QString &language)
{
    uint hashValue = qHash(language);
    int red = 156 + (hashValue & 0x3F);
    int green = 156 + ((hashValue >> 6) & 0x3F);
    int blue = 156 + ((hashValue >> 12) & 0x3F);
    return QColor(red, green, blue);
}

void LanguageChooser::showAll()
{
    foreach (QCheckBox* checkBox, qmFileForCheckBoxMap.keys())
        checkBox->setChecked(true);
}

void LanguageChooser::hideAll()
{
    foreach (QCheckBox* checkBox, qmFileForCheckBoxMap.keys())
        checkBox->setChecked(false);
}


void LanguageChooser::closeEvent(QCloseEvent *event)
{
    qApp->quit();
}

bool LanguageChooser::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Close)
    {
        MainWindow* window=qobject_cast<MainWindow *>(object);
        if (window)
        {
            QCheckBox* checkBox=mainWindowForCheckBoxMap.key(window);
            if (checkBox)
            {
                checkBox->setChecked(false);
            }
        }
    }
    return QDialog::eventFilter(object, event);
}

QStringList LanguageChooser::findQmFiles()
{
    QDir dir("E:\\yjbProjects\\c and c++\\Qt\\thbin\\translations\\");
    QStringList fileNames = dir.entryList(QStringList("*.qm"),QDir::Files,QDir::Name);
    QMutableStringListIterator i(fileNames);
    while (i.hasNext())
    {
        i.next();
        i.setValue(dir.filePath(i.value()));
    }
    return fileNames;
}

QString LanguageChooser::languageName(const QString &qmFile)
{
    QTranslator translator;
    translator.load(qmFile);
    return translator.translate("MainWindow","English");
}
