#include <Activities/HomeActivity.hpp>

HomeActivity::HomeActivity(ActivityStack& stack, int requestCode, Extra& intent)
    : Activity(stack, requestCode, intent) {
    std::cout << "HomeActivity::HomeActivity()" << std::endl;

    ViewNode *background_layer = getLayer(0);
    ViewNode* textLayer = getLayer(1);
    ViewNode *ui_layer = getLayer(2);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    // background_layer
    auto background = std::make_unique<RectangleView>(window_size);
    background->get().setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
    
    background_layer->attachChild(std::move(background));

    //ui_layer
    //text_layer
    auto text = std::make_unique<TextView>(
        sf::Text("Crossy Road", getContext()->getFonts()->get(FontID::Tourney_Bold), 150)
    );
    sf::Vector2f textSize = text->getSize();
    text->setPosition(sf::Vector2f((window_size.x - textSize.x) / 2,97));
    textLayer->attachChild(std::move(text));

    //select_character_button
    auto select_character_button = std::make_unique<RectangleButtonView>(sf::Vector2f(319, 319));
    select_character_button->get().setTexture(&getContext()->getTextures()->get(TextureID::SelectCharacter));
    select_character_button->setPosition(sf::Vector2f(1216, 554));
    select_character_button->setOnClick([this](ViewNode& view) {
        requestActivity(ActivityID::Character);
    });
    ui_layer->attachChild(std::move(select_character_button));

    //requestActivity(ActivityID::Character);
    // music
    getContext()->getMusic()->play(Music::BackGroundMusic);
}

HomeActivity::~HomeActivity() {}

bool HomeActivity::handleEvent(sf::Event& event) { return Activity::handleEvent(event); }

bool HomeActivity::handleRealtimeInput() { return Activity::handleRealtimeInput(); }

bool HomeActivity::update(sf::Time dt) {
    Activity::update(dt);
    // finishActivity();
    return 0;
}

bool HomeActivity::draw() { return Activity::draw(); }

void HomeActivity::onActivityResult(int resultCode, Extra* extra) {
    
}