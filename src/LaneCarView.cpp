#include <LaneCarView.hpp>
#include <LaneCar.hpp>
#include <iostream>
#include <Utils.hpp>

LaneCarView::LaneCarView(LaneType laneType)
	: LaneView(laneType)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    m_background.setFillColor(sf::Color::Yellow);
}

void LaneCarView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
}

void LaneCarView::update(sf::Time dt)
{
}

void LaneCarView::handleEvent(sf::Event& event)
{
}

void LaneCarView::handleRealtimeInput()
{
}

bool LaneCarView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneCarView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	LaneCar* lane = dynamic_cast<LaneCar*>(_lane);
    auto pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    m_background.setPosition(0.f, pos);
}

LaneCarView::~LaneCarView()
{
}