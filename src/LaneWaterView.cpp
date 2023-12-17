#include <LaneWaterView.hpp>

LaneWaterView::LaneWaterView(LaneType laneType)
	: LaneView(laneType)
{
}

void LaneWaterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void LaneWaterView::update(sf::Time dt)
{
}

void LaneWaterView::handleEvent(sf::Event& event)
{
}

void LaneWaterView::handleRealtimeInput()
{
}

bool LaneWaterView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneWaterView::bind(Lane* lane)
{
}

LaneWaterView::~LaneWaterView()
{
}