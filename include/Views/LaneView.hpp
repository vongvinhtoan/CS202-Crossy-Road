#pragma once

#include <ViewNode.hpp>
#include <Lane.hpp>
#include <PlaygroundCamera.hpp>

class LaneView : public ViewNode
{
public:
	LaneView(LaneType laneType);
	virtual ~LaneView();

public:
	virtual void update(sf::Time dt) override;
	virtual void handleEvent(sf::Event& event) override;
	virtual void handleRealtimeInput() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	virtual bool contains(sf::Vector2f point) const override;

public:
	LaneType getLaneType() const;
	virtual void bind(Lane* lane, PlaygroundCamera* camera) = 0;

protected:
	float absolutePositionTransformation(float pos, PlaygroundCamera* camera) const;

private:
	LaneType m_laneType;
};
