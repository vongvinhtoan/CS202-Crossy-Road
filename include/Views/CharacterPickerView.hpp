#pragma once

#include <ViewNode.hpp>
#include <vector>
#include <Holders/CharacterHolder.hpp>
#include <SecondOrderDynamics.hpp>

class RectangleView;
class CharacterView;

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

public:
	CharacterHolder getSelectedCharacter() const;
	void setSelectedCharacter(int index);

private:
	virtual bool contains(sf::Vector2f point) const final override;

private:
	void previousCharacter();
	void nextCharacter();
	void resetAnimFunction();
	std::tuple<int, int, int, int> getCharacterIds(float T) const;
	void updateCharacterPositions(float T);

private:
	inline static const sf::Vector2f MIDDLE_CHARACTER_POSITION = sf::Vector2f(800.f, 494.f);
	inline static const sf::Vector2f LEFT_CHARACTER_POSITION = MIDDLE_CHARACTER_POSITION - sf::Vector2f(438.5f, 0.f) - sf::Vector2f(0.f, 28.f);
	inline static const sf::Vector2f RIGHT_CHARACTER_POSITION = MIDDLE_CHARACTER_POSITION + sf::Vector2f(438.5f, 0.f) - sf::Vector2f(0.f, 28.f);
	inline static const sf::Vector2f MIDDLE_CHARACTER_SIZE = sf::Vector2f(512.f, 512.f);
	inline static const sf::Vector2f SIDE_CHARACTER_SIZE = sf::Vector2f(288.f, 288.f);
    inline static const sf::Color opaque = sf::Color(255, 255, 255, 255);
    inline static const sf::Color semiTransparent = sf::Color(255, 255, 255, 75);
    inline static const sf::Color transparent = sf::Color(255, 255, 255, 0);

private:
	RectangleView* m_leftArrow;
	RectangleView* m_rightArrow;
	std::vector<std::unique_ptr<CharacterView>> m_characters;
	int m_currentCharacter;
	float m_currentViewCharacter;
	sf::Time m_animTime;
	sf::Time m_animElapsedTime;
	std::function<float(float)> m_animFunction;
	std::unique_ptr<SecondOrderDynamics<float>> m_animDynamics;
};
