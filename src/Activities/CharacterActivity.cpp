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
    //text_view
	auto text = std::make_unique<TextView>(sf::Text("SELECT CHARACTER", getContext()->getFonts()->get(FontID::Tourney_Bold), 125));
	text->setPosition(sf::Vector2f((window_size.x - text->get().getLocalBounds().width) / 2, 56));

    //character_picker_view
    std::vector<CharacterHolder> characters(6);
    characters[0].m_texture = &getContext()->getTextures()->get(TextureID::CharacterChicken);
    characters[1].m_texture = &getContext()->getTextures()->get(TextureID::CharacterMonkey);
    characters[2].m_texture = &getContext()->getTextures()->get(TextureID::CharacterPenguin);
    characters[3+0].m_texture = &getContext()->getTextures()->get(TextureID::CharacterChicken);
    characters[3+1].m_texture = &getContext()->getTextures()->get(TextureID::CharacterMonkey);
    characters[3+2].m_texture = &getContext()->getTextures()->get(TextureID::CharacterPenguin);

    auto character_picker_view = std::make_unique<CharacterPickerView>(characters);
    mCharacterPickerView = character_picker_view.get();

    if(requestCode == CHARACTER)
    {
        auto characterID = intent.getExtra<sf::Texture*>("characterID");
        for(int i = 0; i < characters.size(); ++i)
        {
            if(characters[i].m_texture == characterID)
            {
                mCharacterPickerView->setSelectedCharacter(i);
                break;
            }
        }
    }

    auto homeButton = std::make_unique<RectangleButtonView>(sf::Vector2f(128, 128));
    homeButton->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
    homeButton->setPosition(sf::Vector2f(64.f, 64.f));
    homeButton->setOnClick([this](ViewNode& view) {
        auto intent = new Extra();
        intent->putExtra<sf::Texture*>("characterTexture", mCharacterPickerView->getSelectedCharacter().m_texture);
        finishActivity(RESET_CHARACTER, intent);
    });

    ui_layer->attachChild(std::move(homeButton));
    ui_layer->attachChild(std::move(character_picker_view));
    ui_layer->attachChild(std::move(text));
    getContext()->getMusic()->play(Music::BackGroundMusic);    
}

CharacterActivity::~CharacterActivity() 
{
}

bool CharacterActivity::handleEvent(sf::Event &event)
{
    Activity::handleEvent(event);
    return 0;
}

bool CharacterActivity::handleRealtimeInput() 
{
    Activity::handleRealtimeInput(); 
    return 0;
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
