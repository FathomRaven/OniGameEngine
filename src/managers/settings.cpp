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
    const toml::value config = toml::parse("src/config.toml");
    
    const toml::value& graphics = toml::find(config, "graphics");

    winTitle = toml::find<std::string>(graphics, "winTitle");
    winWidth = toml::find<toml::integer>(graphics, "winWidth");
    winHeight = toml::find<toml::integer>(graphics, "winHeight");
    std::vector<int> winColor = toml::find<std::vector<int>>(graphics, "winColor");

    winRefreshColor.r = winColor[0];
    winRefreshColor.g = winColor[1];
    winRefreshColor.b = winColor[2];
    winRefreshColor.a = winColor[3];
}

Settings::~Settings()
{

}