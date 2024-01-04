#include <LaneMovingWaterView.hpp>
#include <LaneMovingWater.hpp>
#include <Utils.hpp>

LaneMovingWaterView::LaneMovingWaterView(LaneType laneType)
	: LaneView(laneType)
	, m_tiles((*getContext()->getWindow()).getSize().x / 100)
	, m_woods(0)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    m_background.setFillColor(utils::hexToColor("#00B0F0"));
}

void LaneMovingWaterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_background, states);
	for(auto tile : m_tiles)
	{
		target.draw(tile, states);
	}
	for(auto wood : m_woods)
	{
		target.draw(wood, states);
	}
}

void LaneMovingWaterView::update(sf::Time dt)
{
}

void LaneMovingWaterView::handleEvent(sf::Event& event)
{
}

void LaneMovingWaterView::handleRealtimeInput()
{
}

bool LaneMovingWaterView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneMovingWaterView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	auto* lane = dynamic_cast<LaneMovingWater*>(_lane);
	auto woodPositions = lane->getWoodPositions();

	auto pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    m_background.setPosition(0.f, pos);
	
	m_woods.resize(woodPositions.size());
	for(int i = 0; i < woodPositions.size(); ++i)
	{
		m_woods[i].setSize(sf::Vector2f(woodPositions[i].second - woodPositions[i].first, 100));


		m_woods[i].setPosition(sf::Vector2f(woodPositions[i].first, pos));
		m_woods[i].setFillColor(sf::Color(139, 69, 19));
	}
}

LaneMovingWaterView::~LaneMovingWaterView()
{
}