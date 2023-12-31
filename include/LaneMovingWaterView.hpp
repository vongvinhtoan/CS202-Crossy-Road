#pragma once

#include <Views/LaneView.hpp>

class LaneMovingWaterView : public LaneView
{
public:
	LaneMovingWaterView(LaneType laneType);
	virtual ~LaneMovingWaterView();

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
	std::vector<sf::RectangleShape> m_tiles;
	std::vector<sf::RectangleShape> m_woods;
};