#include <Views/CharacterPickerView.hpp>
#include <ViewList.hpp>
#include <iostream>
#include <Holders/CharacterHolder.hpp>

CharacterPickerView::CharacterPickerView(const std::vector<CharacterHolder>& characters)
    : m_currentCharacter(0)
{
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
    std::cout << "m_characters.size() = " << m_characters.size() << std::endl;
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

    int l_currentCharacter = m_currentCharacter - 1;
    if (l_currentCharacter < 0)
        l_currentCharacter = m_characters.size() - 1;
    int r_currentCharacter = (m_currentCharacter + 1) % m_characters.size();

    auto m_character = m_characters[m_currentCharacter].get();
    auto l_character = m_characters[l_currentCharacter].get();
    auto r_character = m_characters[r_currentCharacter].get();
    m_character->enable();
    l_character->enable();
    r_character->enable();

    m_character->get().setFillColor(opaque);
    l_character->get().setFillColor(semiTransparent);
    r_character->get().setFillColor(semiTransparent);

    m_character->setSize(MIDDLE_CHARACTER_SIZE);
    l_character->setSize(SIDE_CHARACTER_SIZE);
    r_character->setSize(SIDE_CHARACTER_SIZE);

    m_character->get().setPosition(MIDDLE_CHARACTER_POSITION);
    l_character->get().setPosition(LEFT_CHARACTER_POSITION);
    r_character->get().setPosition(RIGHT_CHARACTER_POSITION);
}

void CharacterPickerView::handleEvent(sf::Event& event)
{
}

void CharacterPickerView::handleRealtimeInput()
{
}

void CharacterPickerView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
    int l_currentCharacter = m_currentCharacter - 1;
    if (l_currentCharacter < 0)
        l_currentCharacter = m_characters.size() - 1;
    int r_currentCharacter = (m_currentCharacter + 1) % m_characters.size();

    auto m_character = m_characters[m_currentCharacter].get();
    auto l_character = m_characters[l_currentCharacter].get();
    auto r_character = m_characters[r_currentCharacter].get();

    for(int i = 0; i < m_characters.size(); i++)
    {
        if(i == m_currentCharacter || i == l_currentCharacter || i == r_currentCharacter)
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
    for (auto& character : m_characters)
        character->disable();
    if (m_currentCharacter == 0)
        m_currentCharacter = m_characters.size() - 1;
    else
        m_currentCharacter = (m_currentCharacter - 1) % m_characters.size();
}

void CharacterPickerView::nextCharacter()
{
    for (auto& character : m_characters)
        character->disable();
    m_currentCharacter = (m_currentCharacter + 1) % m_characters.size();
}