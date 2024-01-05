#include <Context.hpp>

Context::Context()
    : window(nullptr)
    , textures(nullptr)
    , fonts(nullptr)
    , music(nullptr)
    , sounds(nullptr)
    , backend(nullptr)
{
}

Context& Context::getInstance()
{
    static Context instance;
    return instance;
}

Context::~Context()
{
}

sf::RenderWindow* Context::getWindow()
{
    return window;
}

TextureHolder* Context::getTextures()
{
    return textures;
}

FontHolder* Context::getFonts()
{
    return fonts;
}

MusicPlayer* Context::getMusic()
{
    return music;
}

SoundPlayer* Context::getSounds()
{
    return sounds;
}

Backend* Context::getBackend()
{
    return backend;
}

Json::Value* Context::getConfigs()
{
    return configs;
}

void Context::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

void Context::setTextures(TextureHolder* textures)
{
    this->textures = textures;
}

void Context::setFonts(FontHolder* fonts)
{
    this->fonts = fonts;
}

void Context::setMusic(MusicPlayer* music)
{
    this->music = music;
}

void Context::setSounds(SoundPlayer* sounds)
{
    this->sounds = sounds;
}

void Context::setBackend(Backend* backend)
{
    this->backend = backend;
}

void Context::setConfigs(Json::Value* configs)
{
    this->configs = configs;
}