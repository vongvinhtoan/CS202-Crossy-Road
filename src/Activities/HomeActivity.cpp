#include <Activities/HomeActivity.hpp>

HomeActivity::HomeActivity(ActivityStack& stack, int requestCode, Extra& intent)
    : Activity(stack, requestCode, intent) {
    std::cout << "HomeActivity::HomeActivity()" << std::endl;

    sf::Font& font = getContext()->getFonts()->get(FontID::Tourney);
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

    //new_game_button
	auto new_game_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(650, 180));
	new_game_button->get().setFillColor(utils::hexToColor("D9D9D9"));
	new_game_button->get().setPosition(sf::Vector2f(487, 320));

	auto new_game_text = std::make_unique<TextView>("New game", font,100);
	new_game_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &new_game_text_ref = new_game_text->get();
	sf::FloatRect textRect = new_game_text_ref.getLocalBounds();
	new_game_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	new_game_text_ref.setPosition(window_size.x/2.0f,
	                 new_game_button->getPosition().y + new_game_button->get().getSize().y/2.0f);

    //continue_button
    auto continue_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(650, 180));
    continue_button->get().setFillColor(utils::hexToColor("D9D9D9"));
    continue_button->get().setPosition(sf::Vector2f(487, 560));
    
    auto continue_text = std::make_unique<TextView>("Continue", font,100);
    continue_text->get().setFillColor(utils::hexToColor("FFFFFF"));
    auto &continue_text_ref = continue_text->get();
    textRect = continue_text_ref.getLocalBounds();
    continue_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    continue_text_ref.setPosition(window_size.x/2.0f,
                     continue_button->getPosition().y + continue_button->get().getSize().y/2.0f);
    
    //setting_button
    auto setting_button = std::make_unique<RectangleButtonView>(sf::Vector2f(152, 152));
    setting_button->get().setTexture(&getContext()->getTextures()->get(TextureID::Setting));
    setting_button->setPosition(sf::Vector2f(132, 675));
    setting_button->setOnClick([this](ViewNode& view) {
        requestActivity(ActivityID::Setting);
    });

    //instruction_button
    auto instruction_button = std::make_unique<RectangleButtonView>(sf::Vector2f(225, 225));
    instruction_button->get().setTexture(&getContext()->getTextures()->get(TextureID::Instruction));
    instruction_button->setPosition(sf::Vector2f(95, 379));

    ui_layer->attachChild(std::move(select_character_button));
    ui_layer->attachChild(std::move(new_game_button));
    ui_layer->attachChild(std::move(new_game_text));

    ui_layer->attachChild(std::move(continue_button));
    ui_layer->attachChild(std::move(continue_text));

    ui_layer->attachChild(std::move(setting_button));
    ui_layer->attachChild(std::move(instruction_button));
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