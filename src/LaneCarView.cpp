#include <LaneCarView.hpp>
#include <LaneCar.hpp>
#include <iostream>
#include <Utils.hpp>

LaneCarView::LaneCarView(LaneType laneType)
	: LaneView(laneType)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
}

void LaneCarView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
    for(auto& car : m_cars)
        target.draw(car, states);
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

    auto cars = lane->getCars();
    m_carSize = lane->getCarSize();
    m_cars.resize(cars.size());

    pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    for(int i = 0; i < cars.size(); ++i)
    {
        m_cars[i].setSize({m_carSize * 100.f, 100.f});
        m_cars[i].setPosition(cars[i], pos);
        m_cars[i].setFillColor(sf::Color::Red);
    }

    auto* texture = &getContext()->getTextures()->get(TextureID::LaneCar_background_1);
    if(m_carSize == 2)
        texture = &getContext()->getTextures()->get(TextureID::LaneCar_background_2);

    texture->setRepeated(true);
    m_background.setTexture(texture);
    m_background.setTextureRect({0, 0, m_background.getSize().x, m_background.getSize().y});
}

LaneCarView::~LaneCarView()
{
}