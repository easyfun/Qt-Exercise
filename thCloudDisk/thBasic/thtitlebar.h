#ifndef THTITLEBAR_H
#define THTITLEBAR_H

#include <QFrame>
#include <QMap>

QT_BEGIN_NAMESPACE
class QIcon;
class QLabel;
class QToolButton;
QT_END_NAMESPACE

class ThTitleBar : public QFrame
{
    Q_OBJECT

private:
//    QIcon *logoIcon;
//    QIcon *skinIcon;
//    QIcon *menuIcon;
//    QIcon *minIcon;
//    QIcon *maxIcon;
//    QIcon *closeIcon;
//    QMap<QString, QIcon*> mapString2Icon;
    QLabel *titleLabel;
    QToolButton *logoButton;
    QToolButton *skinButton;
    QToolButton *menuButton;
    QToolButton *minButton;
    QToolButton *maxButton;
    QToolButton *closeButton;

public:
    explicit ThTitleBar(QWidget *parent = 0);

    void setTitleLableVisible(bool visibleFlag);
    void setLogoButtonVisible(bool visibleFlag);
    void setSkinButtonVisible(bool visibleFlag);
    void setMenuButtonVisible(bool visibleFlag);
    void setMinButtonVisible(bool visibleFlag);
    void setMaxButtonVisible(bool visibleFlag);
    void setCloseButtonVisible(bool visibleFlag);

signals:

public slots:

private:
    void initData();
    void initUI();
    void initConnect();

    void setToolButtonIcon(QToolButton *toolButton, QString strIcon);
};

#endif // THTITLEBAR_H
