#include <Views/RoundedCornerRectangleView.hpp>

void RoundedCornerRectangleShape::setFillColor(const sf::Color& color) 
{
    m_rectangle.setFillColor(color);
    m_topLeftCorner.setFillColor(color);
    m_topRightCorner.setFillColor(color);
    m_bottomLeftCorner.setFillColor(color);
    m_bottomRightCorner.setFillColor(color);
    m_topEdge.setFillColor(color);
    m_bottomEdge.setFillColor(color);
    m_leftEdge.setFillColor(color);
    m_rightEdge.setFillColor(color);
}

void RoundedCornerRectangleShape::setTexture(const sf::Texture* texture) 
{
    m_rectangle.setTexture(texture);
    m_topLeftCorner.setFillColor(sf::Color::Transparent);
    m_topRightCorner.setFillColor(sf::Color::Transparent);
    m_bottomLeftCorner.setFillColor(sf::Color::Transparent);
    m_bottomRightCorner.setFillColor(sf::Color::Transparent);
    m_topEdge.setFillColor(sf::Color::Transparent);
    m_bottomEdge.setFillColor(sf::Color::Transparent);
    m_leftEdge.setFillColor(sf::Color::Transparent);
    m_rightEdge.setFillColor(sf::Color::Transparent);
}

void RoundedCornerRectangleShape::setPosition(const sf::Vector2f& position) 
{
    m_rectangle.setPosition(position);

    m_topLeftCorner.setPosition(m_rectangle.getPosition());
    m_topRightCorner.setPosition(
        m_rectangle.getPosition().x + m_rectangle.getSize().x, m_rectangle.getPosition().y
    );
    m_bottomLeftCorner.setPosition(
        m_rectangle.getPosition().x, m_rectangle.getPosition().y + m_rectangle.getSize().y
    );
    m_bottomRightCorner.setPosition(
        m_rectangle.getPosition().x + m_rectangle.getSize().x,
        m_rectangle.getPosition().y + m_rectangle.getSize().y
    );

    m_topEdge.setPosition(
        m_rectangle.getPosition().x, m_rectangle.getPosition().y - m_topEdge.getSize().y
    );
    m_bottomEdge.setPosition(
        m_rectangle.getPosition().x, m_rectangle.getPosition().y + m_rectangle.getSize().y
    );
    m_leftEdge.setPosition(
        m_rectangle.getPosition().x - m_leftEdge.getSize().x, m_rectangle.getPosition().y
    );
    m_rightEdge.setPosition(
        m_rectangle.getPosition().x + m_rectangle.getSize().x, m_rectangle.getPosition().y
    );
}

sf::Vector2f RoundedCornerRectangleShape::getPosition() const 
{
    return m_rectangle.getPosition();
}

sf::Vector2f RoundedCornerRectangleShape::getSize() const 
{
    return m_rectangle.getSize();
}

RoundedCornerRectangleView::RoundedCornerRectangleView() 
{
}

RoundedCornerRectangleView::~RoundedCornerRectangleView() 
{
}

void RoundedCornerRectangleView::update(sf::Time dt) 
{
}

void RoundedCornerRectangleView::handleEvent(sf::Event& event) 
{
}

void RoundedCornerRectangleView::handleRealtimeInput() 
{
}

void RoundedCornerRectangleView::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(m_rounded_rectangle.m_rectangle, states);
    target.draw(m_rounded_rectangle.m_topEdge, states);
    target.draw(m_rounded_rectangle.m_bottomEdge, states);
    target.draw(m_rounded_rectangle.m_leftEdge, states);
    target.draw(m_rounded_rectangle.m_rightEdge, states);
    target.draw(m_rounded_rectangle.m_topLeftCorner, states);
    target.draw(m_rounded_rectangle.m_topRightCorner, states);
    target.draw(m_rounded_rectangle.m_bottomLeftCorner, states);
    target.draw(m_rounded_rectangle.m_bottomRightCorner, states);
}

bool RoundedCornerRectangleView::contains(sf::Vector2f point) const 
{
    return m_rounded_rectangle.m_rectangle.getGlobalBounds().contains(point);
}

RoundedCornerRectangleShape& RoundedCornerRectangleView::get() 
{
    return m_rounded_rectangle;
}

RoundedCornerRectangleShape RoundedCornerRectangleView::getRectangle() const 
{
    return m_rounded_rectangle;
}

sf::Vector2f RoundedCornerRectangleView::getPosition() const 
{
    return m_rounded_rectangle.getPosition();
}

sf::Vector2f RoundedCornerRectangleView::getSize() const 
{
    return m_rounded_rectangle.getSize();
}