#pragma once

#include <ViewNode.hpp>
#include <Holders/CharacterHolder.hpp>

class CharacterView : public ViewNode
{
public:
	CharacterView(const CharacterHolder& character);
	virtual ~CharacterView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	sf::RectangleShape& get() { return m_characterSprite; }
	virtual bool contains(sf::Vector2f point) const final override;
	
private:
	CharacterHolder 	m_character;
	sf::RectangleShape 	m_characterSprite;
};
