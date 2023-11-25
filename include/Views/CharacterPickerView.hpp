#pragma once

#include <ViewNode.hpp>
#include <vector>
#include <Holders/CharacterHolder.hpp>

class RectangleView;

class CharacterPickerView : public ViewNode
{
public:
	CharacterPickerView(const std::vector<CharacterHolder>& characters);
	virtual ~CharacterPickerView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

private:
	virtual bool contains(sf::Vector2f point) const final override;

private:
	void previousCharacter();
	void nextCharacter();

private:
	RectangleView* m_leftArrow;
	RectangleView* m_rightArrow;
	std::vector<ViewNode*> m_characters;
	int m_currentCharacter;
};
