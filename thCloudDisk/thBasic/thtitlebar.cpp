#include "thtitlebar.h"
#include <QtGUI>

ThTitleBar::ThTitleBar(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void ThTitleBar::initData()
{

}

void ThTitleBar::initUI()
{
    setFixedHeight(28);
    titleLabel = new QLabel(tr("ThCloudDisk"));
    logoButton = new QToolButton;
    skinButton = new QToolButton;
    menuButton = new QToolButton;
    minButton = new QToolButton;
    maxButton = new QToolButton;
    closeButton = new QToolButton;
//    setToolButtonIcon(logoButton, "");
    setToolButtonIcon(skinButton, ":/skin/icons/appbar.clothes.shirt.png");
    setToolButtonIcon(menuButton, ":/skin/icons/appbar.control.down.png");
    setToolButtonIcon(minButton, ":/skin/icons/appbar.minus.png");
    setToolButtonIcon(maxButton, ":/skin/icons/appbar.app.png");
    setToolButtonIcon(closeButton, ":/skin/icons/appbar.close.png");

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(logoButton);
    mainLayout->addWidget(titleLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(skinButton);
    mainLayout->addWidget(menuButton);
    mainLayout->addWidget(minButton);
    mainLayout->addWidget(maxButton);
    mainLayout->addWidget(closeButton);
    mainLayout->setContentsMargins(3,3,3,0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void ThTitleBar::initConnect()
{
}

void ThTitleBar::setToolButtonIcon(QToolButton *toolButton, QString strIcon)
{
    toolButton->setIcon(QIcon(strIcon));
    toolButton->setIconSize(QSize(height(),height()));
}

void ThTitleBar::setLogoButtonVisible(bool visibleFlag)
{
    if (logoButton)
    {
        visibleFlag ? logoButton->show() : logoButton->hide();
    }
}

void ThTitleBar::setSkinButtonVisible(bool visibleFlag)
{
    if (skinButton)
    {
        visibleFlag ? skinButton->show() : skinButton->hide();
    }
}

void ThTitleBar::setMenuButtonVisible(bool visibleFlag)
{
    if (menuButton)
    {
        visibleFlag ? menuButton->show() : menuButton->hide();
    }
}

void ThTitleBar::setMinButtonVisible(bool visibleFlag)
{
    if (minButton)
    {
        visibleFlag ? minButton->show() : minButton->hide();
    }
}

void ThTitleBar::setMaxButtonVisible(bool visibleFlag)
{
    if (maxButton)
    {
        visibleFlag ? maxButton->show() : maxButton->hide();
    }
}

void ThTitleBar::setCloseButtonVisible(bool visibleFlag)
{
    if (closeButton)
    {
        visibleFlag ? closeButton->show() : closeButton->hide();
    }
}

void ThTitleBar::setTitleLableVisible(bool visibleFlag)
{
    if (titleLabel)
    {
        visibleFlag ? titleLabel->show() : titleLabel->hide();
    }

}
