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
    for(auto& car : m_cars)
        car.update(dt);
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
    if(m_carSize == 2)
        m_carTextureIndex = 3;
    m_direction = lane->getDirection();
    m_cars.resize(cars.size());

    if(m_lastLane != lane)
    {
        m_lastLane = lane;
        resetTexture();
    }

    pos = absolutePositionTransformation(lane->getIndex() * 100, camera);
    for(int i = 0; i < cars.size(); ++i)
    {
        m_cars[i].setSize({m_carSize * 100.f, 100.f});
        m_cars[i].setPosition(cars[i], pos); 
    }
    setCarsTexture();
}

void LaneCarView::resetTexture()
{
    auto* texture = &getContext()->getTextures()->get(TextureID::LaneCar_background_1);
    if(m_carSize == 2)
        texture = &getContext()->getTextures()->get(TextureID::LaneCar_background_2);

    texture->setRepeated(true);
    m_background.setTexture(texture);
    m_background.setTextureRect({0, 0, int(m_background.getSize().x), int(m_background.getSize().y)});

    m_carTextureIndex = utils::random(0, 2);
}

void LaneCarView::setCarsTexture()
{
    const static std::vector<sf::Texture*> normalCars = {
        &getContext()->getTextures()->get(TextureID::LaneCar_normal_car_1),
        &getContext()->getTextures()->get(TextureID::LaneCar_normal_car_2)
    };

    const static std::vector<sf::Texture*> walkingCars = {
        &getContext()->getTextures()->get(TextureID::LaneCar_walking_car_1),
        &getContext()->getTextures()->get(TextureID::LaneCar_walking_car_2),
        &getContext()->getTextures()->get(TextureID::LaneCar_walking_car_3),
        &getContext()->getTextures()->get(TextureID::LaneCar_walking_car_4)
    };

    const static std::vector<sf::Texture*> runningCats = {
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_1),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_2),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_3),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_4),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_5),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_6),
        &getContext()->getTextures()->get(TextureID::LaneCar_running_cat_7)
    };

    const static std::vector<sf::Texture*> vroomCars = {
        &getContext()->getTextures()->get(TextureID::LaneCar_vroom_car_1),
        &getContext()->getTextures()->get(TextureID::LaneCar_vroom_car_2),
        &getContext()->getTextures()->get(TextureID::LaneCar_vroom_car_3)
    };

    auto pick = m_carTextureIndex;
    for(int i = 0; i < m_cars.size(); ++i)
    {
        if(pick == 0)
        {
            m_cars[i].setTextures(normalCars);
            m_cars[i].setTimePerFrame(sf::seconds(0.5f));
            m_cars[i].setTextureRect({0, 0, 100, 100});
        }
        else if(pick == 1)
        {
            m_cars[i].setTextures(walkingCars);
            m_cars[i].setTimePerFrame(sf::seconds(0.2f));
            m_cars[i].setTextureRect({0, 0, 100, 100});
        }
        else if(pick == 2)
        {
            m_cars[i].setTextures(runningCats);
            m_cars[i].setTimePerFrame(sf::seconds(0.1f));
            m_cars[i].setTextureRect({0, 0, 100, 100});
        }
        else if(pick == 3)
        {
            m_cars[i].setTextures(vroomCars);
            m_cars[i].setTextureRect({0, 0, 200, 100});
            m_cars[i].setTimePerFrame(sf::seconds(0.1f));
        }
    }

    if(m_direction > 0)
    {
        for(int i = 0; i < m_cars.size(); ++i)
        {
            m_cars[i].setScale(-1.f, 1.f);
            m_cars[i].move(m_carSize * 100.f, 0.f);
        }
    
    }
}

LaneCarView::~LaneCarView()
{
}