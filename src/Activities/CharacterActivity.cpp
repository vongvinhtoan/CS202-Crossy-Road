#include <Activities/CharacterActivity.hpp>
#include <Utils.hpp>

CharacterActivity::CharacterActivity(ActivityStack &stack, int requestCode, Extra &intent)
    : Activity(stack, requestCode, intent)
{
    ViewNode *background_layer = getLayer(0);
    ViewNode *ui_layer = getLayer(1);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    // background_layer
    auto background = std::make_unique<RectangleView>(window_size);
    background->get().setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
    
    background_layer->attachChild(std::move(background));

    // ui_layer
    std::vector<CharacterHolder> characters(6);
    characters[0].m_texture = &getContext()->getTextures()->get(TextureID::CharacterChicken);
    characters[1].m_texture = &getContext()->getTextures()->get(TextureID::CharacterMonkey);
    characters[2].m_texture = &getContext()->getTextures()->get(TextureID::CharacterPenguin);
    characters[3].m_texture = &getContext()->getTextures()->get(TextureID::CharacterChicken);
    characters[4].m_texture = &getContext()->getTextures()->get(TextureID::CharacterMonkey);
    characters[5].m_texture = &getContext()->getTextures()->get(TextureID::CharacterPenguin);

    auto character_picker_view = std::make_unique<CharacterPickerView>(characters);
    mCharacterPickerView = character_picker_view.get();

    auto homeButton = std::make_unique<RectangleButtonView>(sf::Vector2f(128, 128));
    homeButton->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
    homeButton->setPosition(sf::Vector2f(64.f, 64.f));
    homeButton->setOnClick([this](ViewNode& view) {
        finishActivity();
    });

    ui_layer->attachChild(std::move(homeButton));
    ui_layer->attachChild(std::move(character_picker_view));
    getContext()->getMusic()->play(Music::BackGroundMusic);    
}

CharacterActivity::~CharacterActivity() 
{
}

bool CharacterActivity::handleEvent(sf::Event &event)
{
    return Activity::handleEvent(event);
}

bool CharacterActivity::handleRealtimeInput() 
{
    return Activity::handleRealtimeInput(); 
}

bool CharacterActivity::update(sf::Time dt)
{
    Activity::update(dt);
    return 0;
}

bool CharacterActivity::draw() 
{
	getContext()->getWindow()->clear(utils::hexToColor("#9ae0a8"));
    return Activity::draw(); 
}
