#ifndef THPUGINCORE_H
#define THPUGINCORE_H

#define THINTERFACE struct

// 核心管理组件接口
THINTERFACE IThPluginCore
{

};

// 插件接口
THINTERFACE IThPlugin
{
    virtual bool initPlugin(IThPluginCore *pThPluginCore) = 0;
    virtual bool exitPlugin() = 0;
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
class ThPluginBase : public IThPlugin, public IThPluginCore
{
public:
    ThPluginCoreBase();
    ~ThPluginCoreBase();

protected:

};

////////////////////////////////////////////////////////
// 插件运行时
struct ThPluginClass
{
    char    *m_pszClassName;
    int     m_nObjectSize;
    int     m_nOnlyOneObject;
    void    *(*m_pfnCreatePluginObject)();
    void    *createThPuginObject()
    {
        return (0 != m_pfnCreatePluginObject) ? m_pfnCreatePluginObject() : 0;
    }
};

#define THPLUGIN_CLASS(ThPlugin_Name) ((ThPluginClass *)(&ThPlugin_Name::thpluginclass##ThPlugin_Name))
#define THPLUGIN_CREATEOBJECT(ThPlugin_Name, pTPC) ((ThPlugin_Name *)pTPC->createThPluginObject())


#endif // THPUGINCORE_H
