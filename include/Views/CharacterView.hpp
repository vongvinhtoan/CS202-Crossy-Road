#pragma once

#include <ViewNode.hpp>
#include <Holders/CharacterHolder.hpp>

class CharacterView : public ViewNode
{
friend class CharacterPickerView;
public:
	CharacterView(const CharacterHolder& character, const sf::Vector2f& size = sf::Vector2f(0.f, 0.f));
	virtual ~CharacterView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	sf::RectangleShape& get() { return m_characterSprite; }
	virtual bool contains(sf::Vector2f point) const final override;
	void setSize(const sf::Vector2f& size);
	
private:
	CharacterHolder 	m_character;
	sf::RectangleShape 	m_characterSprite;
};
