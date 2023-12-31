#include <LaneMovingWaterView.hpp>
#include <LaneMovingWater.hpp>

LaneMovingWaterView::LaneMovingWaterView(LaneType laneType)
	: LaneView(laneType)
	, m_tiles((*getContext()->getWindow()).getSize().x / 100)
	, m_woods(0)
{
}

void LaneMovingWaterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
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

	m_woods.resize(woodPositions.size());
	for(int i = 0; i < woodPositions.size(); ++i)
	{
		m_woods[i].setSize(sf::Vector2f(woodPositions[i].second - woodPositions[i].first, 100));

		auto pos = lane->getIndex() * 100;
		pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
		pos = (*getContext()->getWindow()).getSize().y - pos;

		m_woods[i].setPosition(sf::Vector2f(woodPositions[i].first, pos));
		m_woods[i].setFillColor(sf::Color(139, 69, 19));
	}
}

LaneMovingWaterView::~LaneMovingWaterView()
{
}