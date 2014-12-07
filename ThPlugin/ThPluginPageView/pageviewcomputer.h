#ifndef PAGEVIEWCOMPUTER_H
#define PAGEVIEWCOMPUTER_H

#include <QWidget>
#include "../ThPluginCore/ThPuginCore.cpp"


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE
class PageViewComputer : public QWidget
{
    Q_OBJECT


public:
    static const ThPluginClass thpluginclass;
    virtual ThPluginClass* getThPluginClass() const;
    static void* createThPluginObject();


public:
    explicit PageViewComputer(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *labelComputer;
};

#endif // PAGEVIEWCOMPUTER_H
