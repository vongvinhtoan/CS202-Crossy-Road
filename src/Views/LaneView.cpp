#include <Views/LaneView.hpp>
#include <iostream>

LaneView::LaneView(LaneType laneType)
	: m_laneType(laneType)
{
}

LaneView::~LaneView()
{
}

void LaneView::update(sf::Time dt)
{
}

void LaneView::handleEvent(sf::Event& event)
{
}

void LaneView::handleRealtimeInput()
{
}

void LaneView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

bool LaneView::contains(sf::Vector2f point) const
{
	return false;
}

LaneType LaneView::getLaneType() const
{
	return m_laneType;
}

float LaneView::absolutePositionTransformation(float pos, PlaygroundCamera* camera) const
{
	pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
	pos = (*getContext()->getWindow()).getSize().y - pos;
    return pos;
}