#include <Views/CharacterPickerView.hpp>
#include <ViewList.hpp>
#include <iostream>
#include <Holders/CharacterHolder.hpp>
#include <cmath>
#include <Utils.hpp>

CharacterPickerView::CharacterPickerView(const std::vector<CharacterHolder>& characters)
    : m_currentCharacter(0)
    , m_currentViewCharacter(0.f)
    , m_animFunction([](float t) { return 0; })
    , m_animElapsedTime(sf::Time::Zero)
{
    auto& configs = (*getContext()->getConfigs())["character_picker"];
    m_animTime = sf::seconds(configs["animation_time"].asFloat());
    auto& dynamics = configs["animation_dynamic"];
    m_animDynamics = std::make_unique<SecondOrderDynamics<float>>(dynamics["f"].asFloat(), dynamics["z"].asFloat(), dynamics["r"].asFloat(), 0.f);

    auto leftArrow = std::make_unique<RectangleView>(sf::Vector2f(115, 165));
    leftArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::LeftArrow));
    leftArrow->get().setPosition(sf::Vector2f(64.f, 383.f));
    leftArrow->setOnClick([this](ViewNode& view) {
        previousCharacter();
    });
    m_leftArrow = leftArrow.get();
    
    auto rightArrow = std::make_unique<RectangleView>(sf::Vector2f(115, 165));
    rightArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::RightArrow));
    rightArrow->get().setPosition(sf::Vector2f(1413.f, 383.f));
    rightArrow->setOnClick([this](ViewNode& view) {
        nextCharacter();
    });
    m_rightArrow = rightArrow.get();

    for (auto& character : characters)
    {
        auto characterView = std::make_unique<CharacterView>(character);
        characterView->disable();
        m_characters.push_back(std::move(characterView));
    }

    attachChild(std::move(leftArrow));
    attachChild(std::move(rightArrow));
}

CharacterPickerView::~CharacterPickerView()
{
}

void CharacterPickerView::update(sf::Time dt)
{
    for (auto& character : m_characters) {
        character->update(dt);
        character->setPosition(MIDDLE_CHARACTER_POSITION);
        character->setSize(sf::Vector2f(0, 0));
    }

    m_animElapsedTime += dt;
    if (m_animElapsedTime > m_animTime)
        m_animElapsedTime = m_animTime;

    float t = m_animElapsedTime / m_animTime;
    m_currentViewCharacter = m_animFunction(t);

    updateCharacterPositions(m_animDynamics->update(dt.asSeconds(), m_currentViewCharacter));
}

void CharacterPickerView::updateCharacterPositions(float T)
{
    auto [l_id, m_id, r_id, f_id] = getCharacterIds(T);

    auto m_character = m_characters[m_id].get();
    auto l_character = m_characters[l_id].get();
    auto r_character = m_characters[r_id].get();
    auto f_character = m_characters[f_id].get();

    float t = T - std::floor(T);
    
    // Animating the middle character
    m_character->get().setPosition(utils::lerp(MIDDLE_CHARACTER_POSITION, LEFT_CHARACTER_POSITION, t));
    m_character->setSize(utils::lerp(MIDDLE_CHARACTER_SIZE, SIDE_CHARACTER_SIZE, t));
    m_character->get().setFillColor(utils::lerp(opaque, semiTransparent, t));

    // Animating the left character      
    l_character->get().setPosition(utils::lerp(LEFT_CHARACTER_POSITION, MIDDLE_CHARACTER_POSITION, t));
    l_character->setSize(utils::lerp(SIDE_CHARACTER_SIZE, sf::Vector2f(0, 0), t));
    l_character->get().setFillColor(utils::lerp(semiTransparent, transparent, t));

    // Animating the right character
    r_character->get().setPosition(utils::lerp(RIGHT_CHARACTER_POSITION, MIDDLE_CHARACTER_POSITION, t));
    r_character->setSize(utils::lerp(SIDE_CHARACTER_SIZE, MIDDLE_CHARACTER_SIZE, t));
    r_character->get().setFillColor(utils::lerp(semiTransparent, opaque, t));

    // Animating the far character
    f_character->get().setPosition(utils::lerp(MIDDLE_CHARACTER_POSITION, RIGHT_CHARACTER_POSITION, t));
    f_character->setSize(utils::lerp(sf::Vector2f(0, 0), SIDE_CHARACTER_SIZE, t));
    f_character->get().setFillColor(utils::lerp(transparent, semiTransparent, t));
}

void CharacterPickerView::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Left)
            previousCharacter();
        else if(event.key.code == sf::Keyboard::Right)
            nextCharacter();
    }
}

void CharacterPickerView::handleRealtimeInput()
{
}

void CharacterPickerView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    auto [l_id, m_id, r_id, f_id] = getCharacterIds(m_currentViewCharacter);

    auto m_character = m_characters[m_id].get();
    auto l_character = m_characters[l_id].get();
    auto r_character = m_characters[r_id].get();

    for(int i = 0; i < m_characters.size(); i++)
    {
        if(i == m_id || i == l_id || i == r_id)
            continue;
        m_characters[i]->draw(target, states);
    }

    target.draw(*l_character, states);
    target.draw(*r_character, states);
    target.draw(*m_character, states);
}

bool CharacterPickerView::contains(sf::Vector2f point) const
{
    return false;
}

void CharacterPickerView::previousCharacter()
{
    m_currentCharacter--;
    resetAnimFunction();
    m_animElapsedTime = sf::Time::Zero;
}

void CharacterPickerView::nextCharacter()
{
    m_currentCharacter++;
    resetAnimFunction();
    m_animElapsedTime = sf::Time::Zero;
}

void CharacterPickerView::resetAnimFunction()
{
    float t = m_animElapsedTime / m_animTime;
    float a = m_animFunction(t);
    float b = m_currentCharacter;
    m_animFunction = [a, b](float t) -> float {
        return utils::lerp(a, b, t);
    };
    m_animElapsedTime = sf::Time::Zero;
}

std::tuple<int, int, int, int> CharacterPickerView::getCharacterIds(float T) const
{
    int m_id = int(std::floor(T)) % int(m_characters.size());
    if (m_id < 0)
        m_id += m_characters.size();
    int l_id = m_id - 1;
    if (l_id < 0)
        l_id = m_characters.size() - 1;
    int r_id = (m_id + 1) % m_characters.size();
    int f_id = (m_id + 2) % m_characters.size();
    return std::make_tuple(l_id, m_id, r_id, f_id);
}