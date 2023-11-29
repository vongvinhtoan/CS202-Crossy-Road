#include <Views/CharacterView.hpp>
#include <iostream>

CharacterView::CharacterView(const CharacterHolder& character, const sf::Vector2f& size)
    : m_character(character)
    , m_characterSprite(size)
{
    std::cout << character.m_texture << std::endl;
}

CharacterView::~CharacterView()
{
}

void CharacterView::update(sf::Time dt)
{
    m_characterSprite.setTexture(m_character.m_texture);
    m_characterSprite.setOrigin(m_characterSprite.getSize() / 2.f);
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

void CharacterView::setSize(const sf::Vector2f& size)
{
    m_characterSprite.setSize(size);
    m_characterSprite.setOrigin(size / 2.f);
}