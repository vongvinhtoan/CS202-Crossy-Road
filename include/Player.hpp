#pragma once

#include <SFML/Graphics.hpp>

class Player 
{
public:
    Player();
public:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveTo(sf::Vector2f position);
    void update(sf::Time dt);
    void accelerate(sf::Vector2f velocity);
    void setInvincible(bool isInvincible);
    bool isInvincible() const;

public:
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getVelocity() const;
    sf::Color getFillColor() const;

private:
    sf::FloatRect m_bounds;
    sf::Vector2f m_velocity;
    bool m_isInvincible;
};