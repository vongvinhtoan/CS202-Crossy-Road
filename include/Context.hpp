#pragma once

#include <SFML/Graphics.hpp>
#include <ResourceHolder.hpp>
#include <Backend.hpp>

class Context
{
public:
    static Context& getInstance();
    ~Context();

private:
    Context();
    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;

public:
    sf::RenderWindow*  getWindow();
    TextureHolder*     getTextures();
    FontHolder*        getFonts();
    Backend*           getBackend();
    Json::Value*       getConfigs();

    void setWindow(sf::RenderWindow* window);
    void setTextures(TextureHolder* textures);
    void setFonts(FontHolder* fonts);
    void setBackend(Backend* backend);
    void setConfigs(Json::Value* configs);

private:
    sf::RenderWindow*  window;
    TextureHolder*     textures;
    FontHolder*        fonts;
    Backend*           backend;
    Json::Value*       configs;
};