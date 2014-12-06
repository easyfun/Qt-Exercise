#include <QtGui>
#include "pageviewmath.h"


void* PageViewMath::createThPluginObject()
{
    return new PageViewMath;
}

const ThPluginClass PageViewMath::thpluginclass = {"PageViewMath",
                                                   sizeof(class PageViewMath),
                                                   false,
                                                   /*PageViewMath::*/createThPluginObject};
ThPluginClass* PageViewMath::getThPluginClass() const
{
    return (ThPluginClass *)(&PageViewMath::thpluginclass);
}


PageViewMath::PageViewMath(QWidget *parent) :
    QWidget(parent)
{
    labelMath = new QLabel(tr("MathPageView"));
    labelMath->setFixedHeight(40);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(labelMath);
    setLayout(mainLayout);
}
