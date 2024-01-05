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
		for(auto w : wood)
		{
			target.draw(w, states);
		}
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
		m_woods[i].clear();
		for(float j = woodPositions[i].first; j < woodPositions[i].second - 50.f; j += 100.f)
		{
			m_woods[i].emplace_back(sf::Vector2f(100, 100));
			m_woods[i].back().setPosition(sf::Vector2f(j, pos));
		}
	}

	for(auto& woods : m_woods)
	{
		woods[0].setTexture(&getContext()->getTextures()->get(TextureID::LaneMovingWater_log_head));
		woods.back().setTexture(&getContext()->getTextures()->get(TextureID::LaneMovingWater_log_tail));
		for(int i = 1; i < woods.size() - 1; ++i)
		{
			woods[i].setTexture(&getContext()->getTextures()->get(TextureID::LaneMovingWater_log_body));
		}
		for(auto wood : woods)
		{
			wood.setTextureRect(sf::IntRect(0, 0, wood.getSize().x, wood.getSize().y));
			wood.setOrigin(0, wood.getSize().y / 2.f);
			wood.move(0.f, 50.f);
		}
	}
}

LaneMovingWaterView::~LaneMovingWaterView()
{
}