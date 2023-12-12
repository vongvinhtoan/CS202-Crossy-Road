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

bool RoundedCornerRectangleView::contains(sf::Vector2f point) const{
    return m_rounded_rectangle.m_rectangle.getGlobalBounds().contains(point);
}

RoundedCornerRectangleShape& RoundedCornerRectangleView::get()
{
    return m_rounded_rectangle;
}