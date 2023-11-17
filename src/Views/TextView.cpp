#include <Views/TextView.hpp>

TextView::TextView()
{
}

TextView::TextView(const sf::Text& text)
    : m_text(text)
{
}

TextView::~TextView()
{
}

sf::Text& TextView::text()
{
    return m_text;
}

void TextView::update(sf::Time dt)
{
}

void TextView::handleEvent(sf::Event& event)
{
}

void TextView::handleRealtimeInput()
{
}

void TextView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}

bool TextView::contains(sf::Vector2f point) const
{
    return m_text.getGlobalBounds().contains(point);
}