#include <Views/ButtonView.hpp>

ButtonView::ButtonView()
{
}

ButtonView::~ButtonView()
{
}

void ButtonView::update(sf::Time dt)
{
}

void ButtonView::handleEvent(sf::Event& event)
{
}

void ButtonView::handleRealtimeInput()
{
}

void ButtonView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
}

bool ButtonView::contains(sf::Vector2f point) const
{
	return m_rectangle.getGlobalBounds().contains(point);
}

sf::RectangleShape& ButtonView::get()
{
	return m_rectangle;
}