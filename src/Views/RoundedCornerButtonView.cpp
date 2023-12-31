#include <Views/RoundedCornerButtonView.hpp>

RoundedCornerButtonView::RoundedCornerButtonView()
{ 
}

RoundedCornerButtonView::~RoundedCornerButtonView()
{
}

void RoundedCornerButtonView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_tmpRectangle, states);
    RoundedCornerRectangleView::draw(target, states);
}

void RoundedCornerButtonView::setHoverEffect(sf::Color hoverColor)
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