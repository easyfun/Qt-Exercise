#ifndef THPUGINCORE_H
#define THPUGINCORE_H

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
    virtual char* getPluginName() = 0;
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
    ThPluginBase();
    ~ThPluginBase();

//    virtual bool initPlugin(IThPluginCore *pThPluginCore) = 0;
    virtual bool initPlugin()
    {
        return true;
    }

    virtual void exitPlugin()
    {

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

public:
    ThResourceEntry();
    ~ThResourceEntry();
    THRESOURCE_TYPE getThResourceType(){return m_eType;}
    const char* getID(){return m_pszID;}
    const char* getName(){return m_pszName;}
    ThPluginClass* getThPluginClass()
    {
        if (m_pThPluginClass)
        {
            if ( !m_pThPluginClass->m_bOnlyOneObject )
                return 0;
        }
        return m_pThPluginClass;
    }

    bool run()
    {
        return true;
    }

public:
    IThPlugin* m_pThPugin;
    THRESOURCE_TYPE m_eType;
    const char* m_pszID;
    const char* m_pszName;
    ThPluginClass* m_pThPluginClass;
};

protected:

};


#endif // THPUGINCORE_H

