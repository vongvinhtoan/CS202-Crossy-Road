#pragma once

#include <Views/LaneView.hpp>
#include <AnimatedSprite.hpp>

class LaneCarView : public LaneView
{
public:
	LaneCarView(LaneType laneType);
	virtual ~LaneCarView();

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
	void resetTexture();
	void setCarsTexture();

private:
	Lane* 							m_lastLane;
	sf::RectangleShape 				m_background;
	sf::RectangleShape 				m_trafficLight;
	std::vector<AnimatedSprite> 	m_cars;
	int 							m_carSize;
	int 							m_carTextureIndex;
	int 							m_direction;
};