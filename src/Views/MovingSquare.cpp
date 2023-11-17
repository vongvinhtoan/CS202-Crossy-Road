#include <Views/MovingSquare.hpp>
#include <iostream>

MovingSquare::MovingSquare(sf::FloatRect bounds)
    : m_bounds(bounds)
{
    m_square = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 150.f));
    m_square->setFillColor(sf::Color::Red);
}

MovingSquare::~MovingSquare()
{
}

void MovingSquare::update(sf::Time dt)
{
    sf::Vector2f position = this->getPosition(); 
    position += m_velocity * dt.asSeconds();

    if (position.x + m_square->getSize().x >= m_bounds.left + m_bounds.width)
    {
        position.x = m_bounds.left + m_bounds.width - m_square->getSize().x;
        m_velocity.x = -m_velocity.x;
    }
    else if (position.x <= m_bounds.left)
    {
        position.x = m_bounds.left;
        m_velocity.x = -m_velocity.x;
    }

    if (position.y + m_square->getSize().y >= m_bounds.top + m_bounds.height)
    {
        position.y = m_bounds.top + m_bounds.height - m_square->getSize().y;
        m_velocity.y = -m_velocity.y;
    }
    else if (position.y <= m_bounds.top)
    {
        position.y = m_bounds.top;
        m_velocity.y = -m_velocity.y;
    }

    this->setPosition(position);
}

void MovingSquare::handleEvent(sf::Event& event)
{
}

void MovingSquare::handleRealtimeInput()
{
}

void MovingSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*m_square, states);
}

bool MovingSquare::contains(sf::Vector2f point) const
{
    // std::cout << "Checking if square contains point" << std::endl;
    return m_square->getGlobalBounds().contains(point);
}

sf::Vector2f MovingSquare::getVelocity() const
{
    return m_velocity;
}

void MovingSquare::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}