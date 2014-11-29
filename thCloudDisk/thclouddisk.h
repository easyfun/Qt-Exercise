#ifndef THCLOUDDISK_H
#define THCLOUDDISK_H

#include <QFrame>
#include "thBasic/thframe.h"

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

// http://www.cnblogs.com/appsucc/archive/2012/03/28/2421225.html
class ThCloudDisk : public ThFrame
{
    Q_OBJECT

public:
    ThCloudDisk(QWidget *parent = 0);
    ~ThCloudDisk();

};

#endif // THCLOUDDISK_H
