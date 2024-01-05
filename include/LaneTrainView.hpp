#pragma once

#include <Views/LaneView.hpp>

class LaneTrainView : public LaneView
{
public:
	LaneTrainView(LaneType laneType);
	virtual ~LaneTrainView();

private:
	virtual void update(sf::Time dt) override;
	virtual void handleEvent(sf::Event& event) override;
	virtual void handleRealtimeInput() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	virtual bool contains(sf::Vector2f point) const override;

public:
    virtual void bind(Lane* lane, PlaygroundCamera* camera) override;

private:
	void stepTexture();
	void resetTexture();

private:
	const static float TRAIN_ANIMATION_TIME;

private:
	enum Direction
	{
		Left,
		Right
	};

private:
	sf::RectangleShape 				m_background;
	std::vector<sf::RectangleShape>	m_trains;
	std::vector<sf::Texture*>		m_trainTextures;
	sf::Time						m_animElapsedTime;
	int								m_trainTextureIndex;
	Lane* 						 	m_lastLane;
	Direction						m_direction;
};