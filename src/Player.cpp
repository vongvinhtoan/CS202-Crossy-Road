#include <Player.hpp>
#include <iostream>

Player::Player()
: m_bounds(sf::FloatRect(0, 0, 100, 100))
, m_isInvincible(false)
{
}

void Player::moveLeft()
{
    accelerate(sf::Vector2f(-100.f, 0));
}

void Player::moveRight()
{
    accelerate(sf::Vector2f(100.f, 0));
}

void Player::moveUp()
{
    accelerate(sf::Vector2f(0, 100.f));
}

void Player::moveDown()
{
    accelerate(sf::Vector2f(0, -100.f));
}

void Player::moveTo(sf::Vector2f position)
{
    accelerate(position - getPosition());
}

void Player::update(sf::Time dt)
{
    m_bounds.left += m_velocity.x;
    m_bounds.top += m_velocity.y;

    m_velocity = sf::Vector2f(0, 0);
}

void Player::accelerate(sf::Vector2f velocity)
{
    m_velocity += velocity;
}

void Player::setInvincible(bool isInvincible)
{
    m_isInvincible = isInvincible;
}

bool Player::isInvincible() const
{
    return m_isInvincible;
}

sf::FloatRect Player::getBounds() const
{
    return m_bounds;
}

sf::Vector2f Player::getPosition() const
{
    return sf::Vector2f(m_bounds.left, m_bounds.top);
}

sf::Vector2f Player::getSize() const
{
    return sf::Vector2f(m_bounds.width, m_bounds.height);
}

sf::Vector2f Player::getVelocity() const
{
    return m_velocity;
}

sf::Color Player::getFillColor() const
{
    return sf::Color::Red;
}

void Player::setPosition(sf::Vector2f position)
{
    m_bounds.left = position.x;
    m_bounds.top = position.y;
}