#ifndef THPUGINCORE_H
#define THPUGINCORE_H

#include <QList>
#include <QMap>

////////////////////////////////////////////////////////
// 插件运行时
struct ThPluginClass
{
    const char *m_pszClassName;
    int m_nObjectSize;
    bool m_bOnlyOneObject;
    void* (*m_pfnCreatePluginObject)();
    void* createThPuginObject()
    {
        return (0 != m_pfnCreatePluginObject) ? m_pfnCreatePluginObject() : 0;
    }
};

#define THPLUGIN_CLASS(ThPlugin_Name) ((ThPluginClass *)(&ThPlugin_Name::thpluginclass##ThPlugin_Name))
#define THPLUGIN_CREATEOBJECT(ThPlugin_Name, pTPC) ((ThPlugin_Name *)pTPC->createThPluginObject())

#define DECLARE_THPLUGINCLASS(ThPlugin_Name)    \
    public:\
    static const ThPluginClass thpluginclass##ThPlugin_Name;\
    virtual ThPluginClass* getThPluginClass() const;\
    static void* createThPluginObject();

#define IMPLEMENT_THPLUGINCLASS(ThPlugin_Name, OnlyOneObject)\
    const ThPluginClass ThPlugin_Name::thpluginclass##ThPlugin_Name=\
    { #ThPlugin_Name,sizeof(class ThPlugin_Name),OnlyOneObject, createThPluginObject };\
    ThPluginClass* ThPlugin_Name::getThPluginClass() const\
    { return THPLUGIN_CLASS(ThPlugin_Name);}\
    void* ThPlugin_Name::createThPluginObject()\
    { return new ThPlugin_Name;}


#define THINTERFACE struct

// 核心管理组件接口
THINTERFACE IThPluginCore
{

};

// 插件接口
THINTERFACE IThPlugin
{
    virtual bool initPlugin(IThPluginCore *pThPluginCore) = 0;
    virtual void exitPlugin() = 0;
    virtual const char* getThPluginName() = 0;
    virtual void getThResourceEntry(QMap<const char *, ThPluginClass *> *map) = 0;
};

// 核心管理组件
class ThPluginCoreBase
{
public:
    ThPluginCoreBase()
    {
        m_pThPluginCore = 0;
        m_pThPlugin = 0;
    }

    ~ThPluginCoreBase()
    {

    }

    void setPluginCore(IThPluginCore *pThPluginCore)
    {
        m_pThPluginCore = pThPluginCore;
    }

    void setPlugin(IThPlugin *pThPlugin)
    {
        m_pThPlugin = pThPlugin;
    }

protected:
    IThPluginCore   *m_pThPluginCore;
    IThPlugin       *m_pThPlugin;
};

// 插件基类

class ThPluginBase : public IThPlugin//, public IThPluginCore
{
public:
    ThPluginBase()
    {
        m_listThResourceEntrys.clear();
    }

    virtual ~ThPluginBase()
    {
        while ( !m_listThResourceEntrys.isEmpty() )
            delete m_listThResourceEntrys.takeFirst();
    }

//    virtual bool initPlugin(IThPluginCore *pThPluginCore) = 0;
    virtual bool initPlugin(IThPluginCore *pThPluginCore)
    {
        pThPluginCore = 0;
        return true;
    }

    virtual void exitPlugin()
    {

    }

    void getThResourceEntry(QMap<const char *, ThPluginClass *> *map)
    {
        QList<ThResourceEntry *>::const_iterator ci = m_listThResourceEntrys.begin();
        for ( ; ci != m_listThResourceEntrys.end(); ci++)
        {
            ThResourceEntry* pRE = *ci;
            map->insert(pRE->getID(), pRE->getThPluginClass());
        }
    }

protected:
    class ThResourceEntry
    {
    public:
        typedef enum enumTHRESOURCE_TYPE
        {
            THRT_INVALID,
            THRT_PAGEVIEW,
        }THRESOURCE_TYPE;

        ThResourceEntry()
        {
            m_pThPugin = 0;
            m_pThPluginClass = 0;
            m_eType = THRT_INVALID;
            m_pszID = 0;
            m_pszName = 0;
        }
        ~ThResourceEntry(){}
        THRESOURCE_TYPE getThResourceType(){return m_eType;}
        const char* getID(){return m_pszID;}
        const char* getName(){return m_pszName;}
        ThPluginClass* getThPluginClass()
        {
/*            if (m_pThPluginClass)
            {
                if ( !m_pThPluginClass->m_bOnlyOneObject )
                    return 0;
            }*/
            return m_pThPluginClass;
        }

        bool run()
        {
            return true;
        }

    private:
        IThPlugin* m_pThPugin;
        THRESOURCE_TYPE m_eType;
        const char* m_pszID;
        const char* m_pszName;
        ThPluginClass* m_pThPluginClass;

        friend class ThPluginBase;

    };

public:
    void addThResourceEntry(ThResourceEntry::THRESOURCE_TYPE eType, const char* pszID, const char* pszName, ThPluginClass* pThPluginClass)
    {
        ThResourceEntry* pRE = new ThResourceEntry;
        Q_ASSERT(0 != pRE);
        pRE->m_pThPugin = this;
        pRE->m_eType = eType;
        pRE->m_pszID = pszID;
        pRE->m_pszName = pszName;
        pRE->m_pThPluginClass = pThPluginClass;
        m_listThResourceEntrys.append(pRE);
    }

protected:
    QList<ThResourceEntry *> m_listThResourceEntrys;
};


#endif // THPUGINCORE_H

