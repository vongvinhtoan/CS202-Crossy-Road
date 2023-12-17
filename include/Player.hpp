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
    void update(sf::Time dt);
    void accelerate(sf::Vector2f velocity);

public:
    sf::FloatRect getBounds() const;

private:
    sf::FloatRect m_bounds;
    sf::Vector2f m_velocity;
};