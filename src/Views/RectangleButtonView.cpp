#include <Views/RectangleButtonView.hpp>
#include <iostream>

RectangleButtonView::RectangleButtonView()
{
}

RectangleButtonView::~RectangleButtonView()
{
}

void RectangleButtonView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_tmpRectangle, states);
    RectangleView::draw(target, states);
}

void RectangleButtonView::setHoverEffect(sf::Color hoverColor)
{
    setOnHover([this, hoverColor](ViewNode &view)
               {
        sf::Color color = hoverColor;
        color.a = 128;
        m_tmpRectangle.setFillColor(color); });

    setOnLostHover([this](ViewNode &view)
                   { m_tmpRectangle.setFillColor(sf::Color::Transparent); });
}

void RectangleButtonView::setButtonColor(const sf::Color &color)
{
    m_rectangle.setFillColor(color);
}