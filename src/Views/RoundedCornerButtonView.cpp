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

sf::Vector2f RoundedCornerButtonView::getPosition() const
{
   return RoundedCornerRectangleView::getPosition();
}

sf::Vector2f RoundedCornerButtonView::getSize() const
{
    return RoundedCornerRectangleView::getSize();
}

RoundedCornerRectangleShape& RoundedCornerButtonView::get()
{
    m_tmpRectangle.setPosition(getPosition());
    return m_rounded_rectangle;
}