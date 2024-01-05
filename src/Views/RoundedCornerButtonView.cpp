#include <Views/RoundedCornerButtonView.hpp>

RoundedCornerButtonView::RoundedCornerButtonView()
{ 
}

RoundedCornerButtonView::~RoundedCornerButtonView()
{
}

void RoundedCornerButtonView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    RoundedCornerRectangleView::draw(target, states);
}

void RoundedCornerButtonView::setHoverEffect(sf::Color hoverColor)
{
    setOnHover([this, hoverColor](ViewNode& view) {
        sf::Color color = hoverColor;
        color.a = 128;
    });

    setOnLostHover([this](ViewNode& view) {
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
    return m_rounded_rectangle;
}
