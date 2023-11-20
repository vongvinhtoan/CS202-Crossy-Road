#include <Backend.hpp>
#include <fstream>

Backend::Backend()
{
}

Backend::~Backend()
{
}

Backend& Backend::getInstance()
{
    static Backend instance;
    return instance;
}

void Backend::save()
{
}

void Backend::loadFonts(FontHolder& fonts)
{
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
    fonts.load(FontID::Tourney, "res/fonts/Tourney_SemiCondensed-Light.ttf");
    fonts.load(FontID::Tourney_Bold, "res/fonts/Tourney_SemiCondensed-Bold.ttf");
}

void Backend::loadConfigs(Json::Value& configs)
{
    std::ifstream file("res/configs/configs.json"); 
    file >> configs;
    file.close();
}