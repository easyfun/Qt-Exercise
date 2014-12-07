#include "thplugin.h"
#include "./PageView/pageviewmath.h"

ThPlugin::ThPlugin()
{
    addThResourceEntry(ThResourceEntry::THRT_PAGEVIEW, "pageViewMath", "PageViewMath", (ThPluginClass *)&PageViewMath::thpluginclass);
}

ThPlugin::~ThPlugin()
{

}

