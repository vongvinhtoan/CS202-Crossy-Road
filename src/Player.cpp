#include <Player.hpp>
#include <iostream>

Player::Player()
: m_bounds(sf::FloatRect(0, 0, 100, 100))
{
}

void Player::moveLeft()
{
    accelerate(sf::Vector2f(-1, 0));
}

void Player::moveRight()
{
    accelerate(sf::Vector2f(1, 0));
}

void Player::moveUp()
{
    accelerate(sf::Vector2f(0, 1));
}

void Player::moveDown()
{
    accelerate(sf::Vector2f(0, -1));
}

void Player::update(sf::Time dt)
{
    m_bounds.left += m_velocity.x * m_bounds.width;
    m_bounds.top += m_velocity.y * m_bounds.height;

    m_velocity = sf::Vector2f(0, 0);
}

void Player::accelerate(sf::Vector2f velocity)
{
    m_velocity += velocity;
}

sf::FloatRect Player::getBounds() const
{
    return m_bounds;
}

sf::Vector2f Player::getPosition() const
{
    return sf::Vector2f(m_bounds.left, m_bounds.top);
}