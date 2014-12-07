#include "pageviewcomputer.h"

#include<QtGui>


void* PageViewComputer::createThPluginObject()
{
    return new PageViewComputer;
}

const ThPluginClass PageViewComputer::thpluginclass = {"PageViewMath",
                                                   sizeof(class PageViewComputer),
                                                   false,
                                                   /*PageViewComputer::*/createThPluginObject};
ThPluginClass* PageViewComputer::getThPluginClass() const
{
    return (ThPluginClass *)(&PageViewComputer::thpluginclass);
}


PageViewComputer::PageViewComputer(QWidget *parent) :
    QWidget(parent)
{
    labelComputer = new QLabel(tr("ComputerPageView"));
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(labelComputer);
    setLayout(mainLayout);
}
