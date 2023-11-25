#include <Views/CharacterView.hpp>

CharacterView::CharacterView(const CharacterHolder& character)
    : m_character(character)
{
}

CharacterView::~CharacterView()
{
}

void CharacterView::update(sf::Time dt)
{
    m_characterSprite.setSize(sf::Vector2f(m_character.m_texture->getSize()));
    m_characterSprite.setTexture(m_character.m_texture);
}

void CharacterView::handleEvent(sf::Event& event)
{
}

void CharacterView::handleRealtimeInput()
{
}

void CharacterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_characterSprite, states);
}

bool CharacterView::contains(sf::Vector2f point) const
{
	return m_characterSprite.getGlobalBounds().contains(point);
}