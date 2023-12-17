#include <LaneLandView.hpp>

LaneLandView::LaneLandView(LaneType laneType)
	: LaneView(laneType)
{
}

void LaneLandView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void LaneLandView::update(sf::Time dt)
{
}

void LaneLandView::handleEvent(sf::Event& event)
{
}

void LaneLandView::handleRealtimeInput()
{
}

bool LaneLandView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneLandView::bind(Lane* lane)
{
}

LaneLandView::~LaneLandView()
{
}