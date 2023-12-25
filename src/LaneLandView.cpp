#include <LaneLandView.hpp>
#include <LaneLand.hpp>
#include <iostream>

LaneLandView::LaneLandView(LaneType laneType)
	: LaneView(laneType)
{
}

void LaneLandView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mShape, states);
	for(int i = 0; i < mObstacles.size(); ++i)
	{
		target.draw(mObstacles[i], states);
	}
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

void LaneLandView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	LaneLand* lane = dynamic_cast<LaneLand*>(_lane);
	auto windowWidth = (*getContext()->getWindow()).getSize().x;
	mShape.setSize(sf::Vector2f(windowWidth, 100));
	mShape.setFillColor(sf::Color::Green);
	
	auto pos = lane->getIndex() * 100;
	pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
	pos = (*getContext()->getWindow()).getSize().y - pos;
	mShape.setPosition(0, pos);

	auto obstacles = lane->getObstacles();
	mObstacles.resize(obstacles.size());
	for(int i = 0; i < obstacles.size(); ++i)
	{
		mObstacles[i].setSize(sf::Vector2f(50.f, 50.f));
		auto pos = -25.f + lane->getIndex() * 100;
		pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
		pos = (*getContext()->getWindow()).getSize().y - pos;
		mObstacles[i].setPosition(obstacles[i] * 100 + 25, pos);
		mObstacles[i].setFillColor(sf::Color::Yellow);
	}
}

LaneLandView::~LaneLandView()
{
}