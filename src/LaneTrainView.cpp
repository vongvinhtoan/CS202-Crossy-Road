#include <LaneTrainView.hpp>
#include <LaneTrain.hpp>
#include <iostream>
#include <Utils.hpp>

LaneTrainView::LaneTrainView(LaneType laneType)
	: LaneView(laneType)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    m_background.setFillColor(sf::Color::Magenta);
}

void LaneTrainView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
}

void LaneTrainView::update(sf::Time dt)
{
}

void LaneTrainView::handleEvent(sf::Event& event)
{
}

void LaneTrainView::handleRealtimeInput()
{
}

bool LaneTrainView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneTrainView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	LaneTrain* lane = dynamic_cast<LaneTrain*>(_lane);
    auto pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    m_background.setPosition(0.f, pos);
}

LaneTrainView::~LaneTrainView()
{
}