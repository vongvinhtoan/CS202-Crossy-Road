#include <LaneStillWaterView.hpp>
#include <LaneStillWater.hpp>
#include <iostream>
#include <Utils.hpp>

LaneStillWaterView::LaneStillWaterView(LaneType laneType)
	: LaneView(laneType)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    m_background.setFillColor(sf::Color::Blue);
}

void LaneStillWaterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
}

void LaneStillWaterView::update(sf::Time dt)
{
}

void LaneStillWaterView::handleEvent(sf::Event& event)
{
}

void LaneStillWaterView::handleRealtimeInput()
{
}

bool LaneStillWaterView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneStillWaterView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	LaneStillWater* lane = dynamic_cast<LaneStillWater*>(_lane);
    auto pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    m_background.setPosition(0.f, pos);
}

LaneStillWaterView::~LaneStillWaterView()
{
}