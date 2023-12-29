#include <Views/TextView.hpp>

TextView::TextView()
{
}

TextView::~TextView()
{
}

sf::Text &TextView::get()
{
    return m_text;
}

sf::Vector2f TextView::getSize() const
{
    return sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height);
}

void TextView::update(sf::Time dt)
{
}

void TextView::handleEvent(sf::Event &event)
{
    if (isEditable)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z)
            {
                char letter = static_cast<char>(event.key.code + 65);
                m_text.setString(std::string(1, letter));
                isEditable = false;
            }
        }
    }
}

void TextView::handleRealtimeInput()
{
}

void TextView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}

bool TextView::contains(sf::Vector2f point) const
{
    return m_text.getGlobalBounds().contains(point);
}

void TextView::setEditable(bool editable)
{
    isEditable = editable;
}

bool TextView::getEditable() const
{
    return isEditable;
}