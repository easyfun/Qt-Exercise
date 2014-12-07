#ifndef THPLUGINPAGEVIEW_H
#define THPLUGINPAGEVIEW_H

#include "thpluginpageview_global.h"
#include "../ThPluginCore/ThPuginCore.cpp"


class ThPluginPageView : public ThPluginBase
{
public:
    ThPluginPageView();
    ~ThPluginPageView();

    const char* getThPluginName() {return "ThPluginPageView";}
//    bool initPlugin(){};
//    void exitPlugin(){};
};
extern ThPluginPageView g_ThPluginPageView;

extern "C"
{
    IThPlugin* THPLUGINPAGEVIEWSHARED_EXPORT getThPlugin()
    {
     return (IThPlugin *)&g_ThPluginPageView;
    }
}

#endif // THPLUGINPAGEVIEW_H
