#pragma once

#include <ViewNode.hpp>

class LandView : public ViewNode
{
public:
	enum Direction {
		LEFT,
		RIGHT
	};

public:
	LandView();
	LandView(Direction direction, float speed);
	virtual ~LandView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;

public:
	void setDirection(Direction direction);
	void setSpeed(float speed);
	Direction getDirection() const;
	float getSpeed() const;

private:
	Direction mDirection;
	float mSpeed;
};
