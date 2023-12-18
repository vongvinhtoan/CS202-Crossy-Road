#include <LaneLandView.hpp>
#include <iostream>

LaneLandView::LaneLandView(LaneType laneType)
	: LaneView(laneType)
{
}

void LaneLandView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mShape, states);
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

void LaneLandView::bind(Lane* lane, PlaygroundCamera* camera)
{
	auto windowWidth = (*getContext()->getWindow()).getSize().x;
	mShape.setSize(sf::Vector2f(windowWidth, 100));
	mShape.setOrigin(sf::Vector2f(0, 50));
	mShape.setFillColor(sf::Color::Green);
	
	auto pos = lane->getIndex() * 100;
	pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
	pos = (*getContext()->getWindow()).getSize().y - pos;
	mShape.setPosition(0, pos);
}

LaneLandView::~LaneLandView()
{
}