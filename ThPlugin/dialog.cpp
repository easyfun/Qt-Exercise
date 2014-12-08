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
    // 析构飞了，很奇怪
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


    // 创建列表选项和对应视图
    if (0 != m_domXML)
    {
        QDomElement root = m_domXML->documentElement();
        QDomNodeList child = root.elementsByTagName("listwidget");
        for (int i=0; i<child.count(); i++)
        {
            QDomNode itemChild = child.item(i).toElement().firstChild();
            while (!itemChild.isNull())
            {
                QDomElement itemElement = itemChild.toElement();
                if ("item" != itemElement.tagName())
                    continue;
                QString id = itemElement.attribute("id", "");
                if ("" == id)
                    continue;

                QByteArray idBA = id.toLatin1();
                char *szID=idBA.data();
                // 用id查找，结果是0，不科学
/*                QMap<const char *, ThPluginClass*>::iterator ci = m_mapID2ThPluginClass.find(szID);
                if (ci != m_mapID2ThPluginClass.end())
                {
                    ThPluginClass *pThPluginClass = ci.value();
                    QWidget *pageView = (QWidget *)pThPluginClass->createThPuginObject();
                    if (0 != pageView)
                    {
                        stackedWidget->addWidget(pageView);
                        listWidget->addItem(itemElement.attribute("title", ""));
                    }
                }*/

                // 这个匹配算法很糟糕
                QMapIterator<const char *, ThPluginClass*> ci(m_mapID2ThPluginClass);
                while (ci.hasNext())
                {
                    ci.next();
                    if (0 == strcmp(szID, ci.key()))
                    {
                    ThPluginClass* pThPluginClass = ci.value();
                    Q_ASSERT(0 != pThPluginClass);
                    QWidget *pageView = (QWidget *)pThPluginClass->createThPuginObject();
                    if (0 != pageView)
                    {
                    stackedWidget->addWidget(pageView);
                    listWidget->addItem(itemElement.attribute("title", ""));
                    }
                    break;
                    }
                }
                itemChild = itemChild.nextSibling();
            }
        }

/*        QMapIterator<const char *, ThPluginClass*> ci(m_mapID2ThPluginClass);
        while (ci.hasNext())
        {
            ci.next();
            listWidget->addItem(ci.key());
            ThPluginClass* pThPluginClass = ci.value();
            Q_ASSERT(0 != pThPluginClass);
            QWidget *pageViewMath = (QWidget *)pThPluginClass->createThPuginObject();
            stackedWidget->addWidget(pageViewMath);

        }*/
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

    QDomElement root = m_domXML->documentElement();
    if (root.tagName() != "content")
    {
        delete m_domXML;
        m_domXML = 0;
    }
    fileXml.close();
    return m_domXML != 0;
}

bool Dialog::installThPlugin()
{
//    m_listThPlugin.append(&m_ThPluginInline);

    if (0 != m_domXML)
    {
        QDomElement root = m_domXML->documentElement();
        QDomNodeList child = root.elementsByTagName("ThPlugin");
        for (int i=0; i<child.count(); i++)
        {
            QDomNode itemChild = child.item(i).toElement().firstChild();
            while (!itemChild.isNull())
            {
                QDomElement itemElement = itemChild.toElement();
                if ("item" != itemElement.tagName())
                {
                    itemChild = itemChild.nextSibling();
                    continue;
                }
                QString fileName = itemElement.attribute("filename", "");
                if ("" == fileName)
                {
                    itemChild = itemChild.nextSibling();
                    continue;
                }

                QString strenable = itemElement.attribute("enable");
                if ("yes" != strenable)
                {
                    itemChild = itemChild.nextSibling();
                    continue;
                }

                QString dllPath = QCoreApplication::applicationDirPath() + "/ThPlugin/" + fileName;
                QLibrary* pLibrary = new QLibrary(dllPath);
                if (pLibrary->load())
                {
                    m_listDLL.append(pLibrary);
                    typedef IThPlugin* (*getThPlugin)();
                    getThPlugin pFnGetThPlugin = (getThPlugin)pLibrary->resolve("getThPlugin");
                    Q_ASSERT(0 != pFnGetThPlugin);
                    IThPlugin* pThPlugin = pFnGetThPlugin();
                    m_listThPlugin.append(pThPlugin);
                }
                itemChild = itemChild.nextSibling();
            }
        }
/*        QDomNode child = root.firstChild();
        while (!child.isNull())
        {
            if ("ThPlugin" == child.toElement().tagName())
            {
                QDomNode itemChild = child.toElement().firstChild();
                while (!itemChild.isNull())
                {
                    QDomElement itemElement = itemChild.toElement();
                    if ("item" != itemElement.tagName())
                        continue;
                    QString fileName = itemElement.attribute("filename", "");
                    if ("" == fileName)
                        continue;

                    QString dllPath = QCoreApplication::applicationDirPath() + "/ThPlugin/" + fileName;
                    QLibrary* pLibrary = new QLibrary(dllPath);
                    if (pLibrary->load())
                    {
                        m_listDLL.append(pLibrary);
                        typedef IThPlugin* (*getThPlugin)();
                        getThPlugin pFnGetThPlugin = (getThPlugin)pLibrary->resolve("getThPlugin");
                        Q_ASSERT(0 != pFnGetThPlugin);
                        IThPlugin* pThPlugin = pFnGetThPlugin();
                        m_listThPlugin.append(pThPlugin);
                    }
                    itemChild = itemChild.nextSibling();
                }
             break;
            }
            child = child.nextSibling();
        }*/
    }

    QList<IThPlugin *>::iterator itor = m_listThPlugin.begin();
    for (; itor != m_listThPlugin.end(); itor++)
    {
        (*itor)->getThResourceEntry(&m_mapID2ThPluginClass);
    }

    return true;
}
