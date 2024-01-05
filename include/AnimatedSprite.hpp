#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <ViewNode.hpp>

class AnimatedSprite
    : public sf::RectangleShape
{
private:
    std::vector<sf::Texture*>   m_textures;
    sf::Time                    m_timePerFrame;
    sf::Time                    m_currentTime;
    int                         m_currentFrame;

public:
    AnimatedSprite();
    AnimatedSprite(std::vector<sf::Texture*> textures, sf::Time timePerFrame);

public:
    void setTextures(std::vector<sf::Texture*> textures);
    void setTimePerFrame(sf::Time timePerFrame);
    std::vector<sf::Texture*> getTextures() const;
    sf::Time getTimePerFrame() const;

    void update(sf::Time dt);
};