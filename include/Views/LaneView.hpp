#pragma once

#include <ViewNode.hpp>
#include <Lane.hpp>

class LaneView : public ViewNode
{
public:
	LaneView(LaneType laneType);
	virtual ~LaneView();

private:
	virtual void update(sf::Time dt) override;
	virtual void handleEvent(sf::Event& event) override;
	virtual void handleRealtimeInput() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	virtual bool contains(sf::Vector2f point) const override;

public:
	LaneType getLaneType() const;
	virtual void bind(Lane* lane) = 0;

private:
	LaneType m_laneType;
};
