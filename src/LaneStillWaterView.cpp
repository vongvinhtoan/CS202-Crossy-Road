#include <LaneStillWaterView.hpp>
#include <LaneStillWater.hpp>
#include <iostream>
#include <Utils.hpp>

LaneStillWaterView::LaneStillWaterView(LaneType laneType)
	: LaneView(laneType)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    m_background.setFillColor(utils::hexToColor("#00B0F0"));
}

void LaneStillWaterView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
    for(auto& leaf : m_leafs)
    {
        target.draw(leaf, states);
    }
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

    auto leafs = lane->getLeafs();
    m_leafs.resize(leafs.size());
    for(int i=0; i<leafs.size(); ++i)
    {
        auto &texture = getContext()->getTextures()->get(TextureID::LaneStillWater_leaf);
        m_leafs[i].setTexture(&texture);
        sf::Vector2f size = {float(texture.getSize().x), float(texture.getSize().y)};
        m_leafs[i].setSize(size);
        m_leafs[i].setPosition({leafs[i] * 100.f + 50.f, pos + 50.f});
        m_leafs[i].setOrigin(size / 2.f);
    }
}

LaneStillWaterView::~LaneStillWaterView()
{
}