#include <Activities/CharacterActivity.hpp>

CharacterActivity::CharacterActivity(ActivityStack &stack, int requestCode, Extra &intent)
    : Activity(stack, requestCode, intent)
{
    ViewNode *background_layer = getLayer(0);
    ViewNode *ui_layer = getLayer(1);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    // background_layer
    auto background = std::make_unique<RectangleView>(window_size);
    background->get().setTexture(&getContext()->getTextures()->get(TextureID::Background));
    
    background_layer->attachChild(std::move(background));

    // ui_layer
    std::vector<CharacterHolder> characters(3);
    characters[0].m_texture = &getContext()->getTextures()->get(TextureID::CharacterChicken);
    characters[1].m_texture = &getContext()->getTextures()->get(TextureID::CharacterMonkey);
    characters[2].m_texture = &getContext()->getTextures()->get(TextureID::CharacterPenguin);

    auto character_picker_view = std::make_unique<CharacterPickerView>(characters);
    mCharacterPickerView = character_picker_view.get();

    ui_layer->attachChild(std::move(character_picker_view));
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
    
    return Activity::draw(); 
}
