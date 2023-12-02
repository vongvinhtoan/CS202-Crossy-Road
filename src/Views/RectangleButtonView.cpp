#include <Views/RectangleButtonView.hpp>

RectangleButtonView::RectangleButtonView()
{ 
    m_tmpRectangle.setFillColor(sf::Color::Blue);
    setHoverEffect();
}

RectangleButtonView::~RectangleButtonView()
{
}

void RectangleButtonView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // if (m_isOnHover)
    // {
    //     target.draw(m_tmpRectangle, states);

    // }
    target.draw(m_tmpRectangle, states);
   // target.draw(getRectangle(), states);
}

bool RectangleButtonView::contains(sf::Vector2f point) const
{
    return getRectangle().getGlobalBounds().contains(point);
}

void RectangleButtonView::setHoverEffect(sf::Color hoverColor)
{
    setOnHover([this, hoverColor](ViewNode& view) {
        m_isOnHover = true;
        
        m_tmpRectangle.setOutlineColor(sf::Color::Transparent);
        m_tmpRectangle.setOutlineThickness(0);
        m_tmpRectangle.setFillColor(hoverColor);
    });

}

void RectangleButtonView::setOnLostHover(std::function<void(ViewNode&)> onLostHover)
{
    m_tmpRectangle.setFillColor(sf::Color::Blue);
}