#include <LaneTrainView.hpp>
#include <LaneTrain.hpp>
#include <iostream>
#include <Utils.hpp>

const float LaneTrainView::TRAIN_ANIMATION_TIME = 0.1f;

LaneTrainView::LaneTrainView(LaneType laneType)
	: LaneView(laneType)
    , m_background()
    , m_trains()
    , m_trainTextures()
    , m_animElapsedTime(sf::Time::Zero)
    , m_trainTextureIndex(0)
    , m_lastLane(nullptr)
{
    float winsizex = getContext()->getWindow()->getSize().x;
    m_background.setSize({winsizex, 100.f});
    auto &texture = getContext()->getTextures()->get(TextureID::LaneTrain_railway_section);
    texture.setRepeated(true);
    m_background.setTexture(&texture);
    m_background.setTextureRect({0, 0, int(winsizex), 100});

    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_1));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_2));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_3));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_4));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_5));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_6));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_7));
    m_trainTextures.push_back(&getContext()->getTextures()->get(TextureID::LaneTrain_train_8));

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
    m_animElapsedTime += dt;
    while(m_animElapsedTime > sf::seconds(TRAIN_ANIMATION_TIME))
    {
        stepTexture();
    }
}

void LaneTrainView::stepTexture()
{
    m_animElapsedTime -= sf::seconds(TRAIN_ANIMATION_TIME);
    m_trainTextureIndex = (m_trainTextureIndex + 1) % m_trainTextures.size();
    m_trains[0].setTexture(m_trainTextures[m_trainTextureIndex]);
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
    
    m_trains.resize(lane->getSize()-1);
    if(m_lastLane != _lane)
    {
        m_lastLane = _lane;
        m_animElapsedTime = sf::Time::Zero;
        m_trainTextureIndex = 0;
        resetTexture();
    }
    auto trainPos = lane->getPosition();
    m_direction = Direction(lane->getDirection());
    for(int i=0; i<m_trains.size(); i++)
    {
        if(i==0) 
        {
            m_trains[i].setSize({200.f, 100.f});
            m_trains[i].setPosition({trainPos + i * 100.f, pos});
        }
        else 
        {
            m_trains[i].setSize({100.f, 100.f});
            m_trains[i].setPosition({trainPos + i * 100.f + 100.f, pos});
        }
    }
    
    if(lane->getDirection() == LaneTrain::Direction::Right)
    {
        for(auto& train : m_trains)
            train.setScale(-1.f, 1.f);
        std::vector<sf::Vector2f> positions;
        for(auto& train : m_trains)
            positions.push_back(train.getPosition());
        std::reverse(positions.begin(), positions.end());
        for(int i=0; i<m_trains.size(); i++)
            m_trains[i].setPosition(positions[i]);
        m_trains[0].move({100.f, 0.f});
        m_trains.back().move({200.f, 0.f});
    }
}

void LaneTrainView::resetTexture()
{
    const static std::vector<sf::Texture*> trainBodyTextures = {
        &getContext()->getTextures()->get(TextureID::LaneTrain_train_coal),
        &getContext()->getTextures()->get(TextureID::LaneTrain_train_log),
        &getContext()->getTextures()->get(TextureID::LaneTrain_train_empty)
    };

    m_trains[0].setTexture(m_trainTextures[0]);
    for(int i=1; i<m_trains.size(); i++)
        m_trains[i].setTexture(trainBodyTextures[utils::random(0, trainBodyTextures.size()-1)]);    
}

LaneTrainView::~LaneTrainView()
{
}