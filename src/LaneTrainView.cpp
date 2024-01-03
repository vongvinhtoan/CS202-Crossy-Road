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
    for(auto& train : m_trains)
    {
        target.draw(train, states);
    }
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

    m_trains.resize(lane->getSize());
    auto trainPos = lane->getPosition();
    for(int i=0; i<m_trains.size(); i++)
    {
        m_trains[i].setSize({100.f, 100.f});
        m_trains[i].setPosition({trainPos + i * 100.f, pos});
        m_trains[i].setFillColor(sf::Color::Red);
    }
}

LaneTrainView::~LaneTrainView()
{
}