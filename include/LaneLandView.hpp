#pragma once

#include <Views/LaneView.hpp>

class LaneLand;

class LaneLandView : public LaneView
{
public:
	LaneLandView(LaneType laneType);
	virtual ~LaneLandView();

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
	void renew_tiles();
	void renew_obstacles();

private:
	Lane*						    mLastLane;
	std::vector<sf::RectangleShape>	mObstacles;
	std::vector<sf::RectangleShape>	mTiles;
};