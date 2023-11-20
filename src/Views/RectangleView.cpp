#include <Views/RectangleView.hpp>

RectangleView::RectangleView()
{
}

RectangleView::~RectangleView()
{
}

void RectangleView::update(sf::Time dt)
{
}

void RectangleView::handleEvent(sf::Event& event)
{
}

void RectangleView::handleRealtimeInput()
{
}

void RectangleView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
}

bool RectangleView::contains(sf::Vector2f point) const
{
	return m_rectangle.getGlobalBounds().contains(point);
}

sf::RectangleShape& RectangleView::get()
{
	return m_rectangle;
}