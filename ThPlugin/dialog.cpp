#include "dialog.h"
#include <QtGui>
#include "./PageView/pageviewmath.h"
#include "./ThPluginCore/ThPuginCore.cpp"

Dialog::Dialog(QWidget *parent)
    : QMainWindow(parent)
{
    initData();
    installThPlugin();
    initUI();
    initConnect();
}

Dialog::~Dialog()
{
/*    while (!m_listDLL.isEmpty()) {
        QLibrary* pDLL = m_listDLL.takeFirst();
        if (pDLL->isLoaded())
            pDLL->unload();
        delete pDLL;
    }*/
}

void Dialog::initUI()
{
    listWidget = new QListWidget;
    listWidget->addItem(tr("Math"));
    listWidget->addItem(tr("English"));
//    listWidget->addItem(tr("PageViewMath"));

    pageMath = new QLabel(tr("Math"));
    pageEnglish = new QLabel(tr("English"));
    //pageViewMath = new PageViewMath;
//    ThPluginClass* pThPlugin = (ThPluginClass *)&PageViewMath::thpluginclass;
//    pageViewMath = (QWidget *)pThPlugin->createThPuginObject();

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(pageMath);
    stackedWidget->addWidget(pageEnglish);


    QMapIterator<const char *, ThPluginClass*> ci(m_mapID2ThPluginClass);
    while (ci.hasNext())
    {
        ci.next();
        listWidget->addItem(ci.key());
        ThPluginClass* pThPluginClass = ci.value();
        Q_ASSERT(0 != pThPluginClass);
        QWidget *pageViewMath = (QWidget *)pThPluginClass->createThPuginObject();
        stackedWidget->addWidget(pageViewMath);

    }
//    stackedWidget->addWidget(pageViewMath);
    stackedWidget->setMinimumWidth(500);

    QSplitter *mainSplitter = new QSplitter;
    mainSplitter->addWidget(listWidget);
    mainSplitter->addWidget(stackedWidget);

    setCentralWidget(mainSplitter);
    resize(800, 600);

}

void Dialog::initConnect()
{
    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

}

void Dialog::initData()
{
    m_mapID2ThPluginClass.clear();
    m_mapID2ThPluginObject.clear();
    m_listThPlugin.clear();
    ReadXml();
}

bool Dialog::ReadXml()
{
    QString str=QCoreApplication::applicationDirPath() + "/ThPlugin.xml";
    QFile fileXml(str);
    if (!fileXml.open(QIODevice::ReadOnly))
    {
        m_domXML = 0;
        return false;
    }
    m_domXML = new QDomDocument("ThPlugin");
    Q_ASSERT(m_domXML);

    if (!m_domXML->setContent(&fileXml))
    {
        delete m_domXML;
        m_domXML = 0;
    }

    fileXml.close();
    return m_domXML != 0;
}

bool Dialog::installThPlugin()
{
    m_listThPlugin.append(&m_ThPluginInline);

    QDomElement root = m_domXML->documentElement();
    if ("Content" == root.tagName())
    {
        QDomNode node = root.firstChild();
        QLibrary* pLibrary = new QLibrary("./ThPluginPageView.dll");
        if (pLibrary->load())
        {
            m_listDLL.append(pLibrary);
            typedef IThPlugin* (*getThPlugin)();
            getThPlugin pFnGetThPlugin = (getThPlugin)pLibrary->resolve("getThPlugin");
            Q_ASSERT(0 != pFnGetThPlugin);
            IThPlugin* pThPlugin = pFnGetThPlugin();
            m_listThPlugin.append(pThPlugin);
        }
    }

    QList<IThPlugin *>::iterator itor = m_listThPlugin.begin();
    for (; itor != m_listThPlugin.end(); itor++)
    {
        (*itor)->getThResourceEntry(&m_mapID2ThPluginClass);
    }

    return true;
}
