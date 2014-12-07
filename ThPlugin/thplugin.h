#ifndef THPLUGIN_H
#define THPLUGIN_H

#include "./ThPluginCore/ThPuginCore.cpp"

class ThPlugin : public ThPluginBase
{
public:
    ThPlugin();
    ~ThPlugin();

    const char* getThPluginName() {return "ThPluginMain";}
//    bool initPlugin(){};
//    void exitPlugin(){};
};

#endif // THPLUGIN_H
