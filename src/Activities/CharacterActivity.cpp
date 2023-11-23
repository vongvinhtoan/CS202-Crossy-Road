#include <Activities/CharacterActivity.hpp>

CharacterActivity::CharacterActivity(ActivityStack& stack, int requestCode, Extra& intent)
    : Activity(stack, requestCode, intent) {
    setupCharacterVector();

    std::cout << "CharacterActivity::CharacterActivity()" << std::endl;
    ViewNode* background_layer = getLayer(0);
    ViewNode* ui_layer = getLayer(1);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    // background_layer
    auto background = std::make_unique<RectangleView>(window_size);
    background->get().setTexture(&getContext()->getTextures()->get(TextureID::Background)
    );
    background_layer->attachChild(std::move(background));

    // ui_layer
    showCharacter(currentCharacterIndex, ui_layer);

    // leftArrow
    auto leftArrow = std::make_unique<ButtonView>(sf::Vector2f(115, 165));
    leftArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::LeftArrow));
    leftArrow->get().setPosition(sf::Vector2f(64.f, 383.f));
    ui_layer->attachChild(std::move(leftArrow));

    // rightArrow
    auto rightArrow = std::make_unique<ButtonView>(sf::Vector2f(115, 165));
    rightArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::RightArrow)
    );
    rightArrow->get().setPosition(sf::Vector2f(1413.f, 383.f));
    ui_layer->attachChild(std::move(rightArrow));
}

void CharacterActivity::setupCharacterVector() {
    addCharacterTexture(TextureID::CharacterPenguin);
    addCharacterTexture(TextureID::CharacterChicken);
    addCharacterTexture(TextureID::CharacterMonkey);
}

void CharacterActivity::showCharacter(int index, ViewNode* ui_layer) {
    auto centralCharacter = std::make_unique<RectangleView>(sf::Vector2f(512, 512));
    centralCharacter->get().setTexture(mCharacter[index].get());
    centralCharacter->get().setPosition(sf::Vector2f(544.f, 238.f));
    ui_layer->attachChild(std::move(centralCharacter));

    auto leftCharacter = std::make_unique<RectangleView>(sf::Vector2f(260, 288));
    if (index > 0) {
        leftCharacter->get().setTexture(mCharacter[index - 1].get());
    } else {
        leftCharacter->get().setFillColor(sf::Color::Transparent);
    }

    leftCharacter->get().setPosition(sf::Vector2f(231.f, 322.f));
    ui_layer->attachChild(std::move(leftCharacter));

    auto rightCharacter = std::make_unique<RectangleView>(sf::Vector2f(260, 288));
    if (index < mCharacter.size() - 1) {
        rightCharacter->get().setTexture(mCharacter[index + 1].get());
    } else {
        rightCharacter->get().setFillColor(sf::Color::Transparent);
    }

    rightCharacter->get().setPosition(sf::Vector2f(1123.f, 322.f));
    ui_layer->attachChild(std::move(rightCharacter));
}

void CharacterActivity::addCharacterTexture(TextureID::ID characterID) {
    auto texture = getContext()->getTextures()->get(characterID);
    mCharacter.push_back(std::make_unique<sf::Texture>(texture));
}

CharacterActivity::~CharacterActivity() {}

bool CharacterActivity::handleEvent(sf::Event& event) {
    return Activity::handleEvent(event);
}

bool CharacterActivity::handleRealtimeInput() { return Activity::handleRealtimeInput(); }

bool CharacterActivity::update(sf::Time dt) {
    Activity::update(dt);
    return 0;
}

bool CharacterActivity::draw() { return Activity::draw(); }
