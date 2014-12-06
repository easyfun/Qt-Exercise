#ifndef PAGEVIEWMATH_H
#define PAGEVIEWMATH_H

#include <QWidget>
#include "ThPluginCore/ThPuginCore.h"

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class PageViewMath : public QWidget
{
    Q_OBJECT

public:
    static const ThPluginClass thpluginclass;
    virtual ThPluginClass* getThPluginClass() const;
    static void* createThPluginObject();

public:
    explicit PageViewMath(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *labelMath;
};

#endif // PAGEVIEWMATH_H
