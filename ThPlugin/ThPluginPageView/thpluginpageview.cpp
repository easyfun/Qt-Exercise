#include "thpluginpageview.h"
#include "pageviewcomputer.h"

ThPluginPageView::ThPluginPageView()
{
    addThResourceEntry(ThResourceEntry::THRT_PAGEVIEW, "pageViewComputer", "PageViewComputer", (ThPluginClass *)&PageViewComputer::thpluginclass);
}

ThPluginPageView::~ThPluginPageView()
{

}

ThPluginPageView g_ThPluginPageView;
