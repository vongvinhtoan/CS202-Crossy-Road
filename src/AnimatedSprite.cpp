#include <AnimatedSprite.hpp>
#include <iostream>

AnimatedSprite::AnimatedSprite()
    : m_textures(),
      m_timePerFrame(sf::Time::Zero),
      m_currentTime(sf::Time::Zero),
      m_currentFrame(0)
{
}

AnimatedSprite::AnimatedSprite(std::vector<sf::Texture*> textures, sf::Time timePerFrame)
    : m_textures(textures),
      m_timePerFrame(timePerFrame),
      m_currentTime(sf::Time::Zero),
      m_currentFrame(0)
{
    setTexture(m_textures[m_currentFrame]);
}

void AnimatedSprite::update(sf::Time dt)
{
    m_currentTime += dt;
    while(m_currentTime >= m_timePerFrame)
    {
        m_currentTime -= m_timePerFrame;
        m_currentFrame = (m_currentFrame + 1) % m_textures.size();
        setTexture(m_textures[m_currentFrame]);
    }
}

void AnimatedSprite::setTextures(std::vector<sf::Texture*> textures)
{
    m_textures = textures;
    setTexture(m_textures[m_currentFrame]);
}

void AnimatedSprite::setTimePerFrame(sf::Time timePerFrame)
{
    m_timePerFrame = timePerFrame;
}

std::vector<sf::Texture*> AnimatedSprite::getTextures() const
{
    return m_textures;
}

sf::Time AnimatedSprite::getTimePerFrame() const
{
    return m_timePerFrame;
}