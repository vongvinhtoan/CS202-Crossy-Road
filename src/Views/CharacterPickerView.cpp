#include <Views/CharacterPickerView.hpp>
#include <ViewList.hpp>
#include <iostream>
#include <Holders/CharacterHolder.hpp>

CharacterPickerView::CharacterPickerView(const std::vector<CharacterHolder>& characters)
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
        characterView->get().setPosition(sf::Vector2f(544.f, 238.f));
        characterView->disable();
        m_characters.push_back(characterView.get());
        attachChild(std::move(characterView));
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
    m_characters[m_currentCharacter]->enable();
}

void CharacterPickerView::handleEvent(sf::Event& event)
{
}

void CharacterPickerView::handleRealtimeInput()
{
}

void CharacterPickerView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

bool CharacterPickerView::contains(sf::Vector2f point) const
{
    return m_leftArrow->contains(point) || m_rightArrow->contains(point);
}

void CharacterPickerView::previousCharacter()
{
    std::cout << "previousCharacter()" << std::endl;
    m_characters[m_currentCharacter]->disable();
    if (m_currentCharacter == 0)
        m_currentCharacter = m_characters.size() - 1;
    else
        m_currentCharacter = (m_currentCharacter - 1) % m_characters.size();
    std::cout << m_currentCharacter << std::endl;
}

void CharacterPickerView::nextCharacter()
{
    std::cout << "nextCharacter()" << std::endl;
    m_characters[m_currentCharacter]->disable();
    m_currentCharacter = (m_currentCharacter + 1) % m_characters.size();
    std::cout << m_currentCharacter << std::endl;
}