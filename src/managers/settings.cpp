#include "Settings.hpp"

using namespace oni;

Settings* Settings::instanceS = nullptr;

Settings* Settings::Instance()
{
    if (instanceS == nullptr)
        instanceS = new Settings();
    
    return instanceS;
}

void Settings::Release()
{
    delete instanceS;
    instanceS = nullptr;
}

Settings::Settings()
{
    winTitle = "Oni Project";
    winWidth = 1024;
    winHeight = 896;
    winRefreshColor = {255, 255, 255, 255};

    debugColliders = false;
}

Settings::~Settings()
{

}