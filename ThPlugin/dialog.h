#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMap>
#include <QDomDocument>
#include "thplugin.h"

QT_BEGIN_NAMESPACE
class QListWidget;
class QLabel;
class QStackedWidget;
class QLibrary;
class QStringList;
QT_END_NAMESPACE

class PageViewMath;

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    void    initData();
    bool    installThPlugin();
    void    initUI();
    void    initConnect();
    bool    ReadXml();

public:

private:
    QListWidget *listWidget;
    QLabel      *pageMath;
    QLabel      *pageEnglish;
    QStackedWidget  *stackedWidget;

//    ThPlugin    m_ThPluginInline;
    QList<IThPlugin *>  m_listThPlugin;
    QMap<const char *, ThPluginClass*> m_mapID2ThPluginClass;
    QMap<const char *, ThPluginClass*> m_mapID2ThPluginObject;
    QList<QLibrary *> m_listDLL;
    QDomDocument *m_domXML;


};

#endif // DIALOG_H
