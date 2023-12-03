#include <Views/RectangleButtonView.hpp>
#include <iostream>

RectangleButtonView::RectangleButtonView()
{ 
    m_tmpRectangle.setFillColor(sf::Color::Blue);
    m_tmpRectangle.setOutlineColor(sf::Color::Transparent);
    m_tmpRectangle.setOutlineThickness(0);
    setHoverEffect();
}

RectangleButtonView::~RectangleButtonView()
{
}

void RectangleButtonView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_tmpRectangle, states);
    RectangleView::draw(target, states);
}

void RectangleButtonView::setHoverEffect(sf::Color hoverColor)
{
    setOnHover([this, hoverColor](ViewNode& view) {
        sf::Color color = hoverColor;
        color.a = 128;
        m_tmpRectangle.setFillColor(color);
    });

    setOnLostHover([this](ViewNode& view) {
        m_tmpRectangle.setFillColor(sf::Color::Transparent);
    });
}