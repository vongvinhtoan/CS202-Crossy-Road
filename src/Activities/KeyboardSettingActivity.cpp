#include <Activities/KeyboardSettingActivity.hpp>
#include <Utils.hpp>

KeyboardSettingActivity::KeyboardSettingActivity(ActivityStack &stack, int requestCode, Extra &intent)
    : Activity(stack, requestCode, intent)
{
    ViewNode *background_layer = getLayer(0);
    ViewNode *ui_layer = getLayer(1);
    ViewNode *text_layer = getLayer(2);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    auto background = std::make_unique<RectangleView>(window_size);
    auto &background_shape = background->get();
    background_shape.setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
    background_layer->attachChild(std::move(background));

    auto text = std::make_unique<TextView>(sf::Text("KEYBOARD SETTING", getContext()->getFonts()->get(FontID::Tourney_Bold), 125));
    text->setPosition(sf::Vector2f((window_size.x - text->get().getLocalBounds().width) / 2, 56));
    text_layer->attachChild(std::move(text));

    // Set button properties
    sf::Color buttonColor = utils::hexToColor("D9D9D9");
    sf::Color textColor = utils::hexToColor("000000");
    sf::Vector2f buttonSize(151, 151);
    sf::Vector2f buttonPosition;

    std::vector<sf::Vector2f> buttonPositions = {sf::Vector2f(714, 356), sf::Vector2f(476, 561), sf::Vector2f(714, 561), sf::Vector2f(952, 561)};
    std::vector<std::string> buttonNames = {"W", "A", "S", "D"};

    for (int i = 0; i < 4; ++i)
    {
        buttons.push_back(std::make_unique<RectangleButtonView>(buttonSize));
        buttons.back()->setPosition(buttonPositions[i]);
        buttons.back()->get().setFillColor(buttonColor);
        ui_layer->attachChild(std::move(buttons.back()));

        texts.push_back(std::make_unique<TextView>(sf::Text(buttonNames[i], getContext()->getFonts()->get(FontID::Inter_Bold), 60)));
        sf::FloatRect textRect = texts.back()->get().getLocalBounds();
        sf::Vector2f textPosition = sf::Vector2f(buttonPositions[i].x + (buttonSize.x - textRect.width) / 2.0f, buttonPositions[i].y + buttonSize.y / 2.0f);
        texts.back()->setOrigin(textRect.left, textRect.top + textRect.height / 2.0f);
        texts.back()->setPosition(textPosition);
        texts.back()->get().setFillColor(textColor);
        text_layer->attachChild(std::move(texts.back()));
    }

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move up", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(660, 230));
    text_layer->attachChild(std::move(texts2.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move left", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(81, 616));
    text_layer->attachChild(std::move(texts2.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move down", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(600, 750));
    text_layer->attachChild(std::move(texts2.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move right", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(1149, 616));
    text_layer->attachChild(std::move(texts2.back()));

    auto home_button = std::make_unique<RectangleView>(sf::Vector2f(128, 128));
    home_button->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
    home_button->setPosition(sf::Vector2f(64.f, 64.f));
    home_button->setOnClick([this](ViewNode &view)
    {
        std::cout << "Home button clicked" << std::endl;
        finishActivity(); 
    });

    ui_layer->attachChild(std::move(home_button));

    auto keyboard_button = std::make_unique<RectangleView>(sf::Vector2f(128, 128));
    keyboard_button->get().setTexture(&getContext()->getTextures()->get(TextureID::KeyboardButton));
    keyboard_button->setPosition(sf::Vector2f(1414.f, 70.f));
    keyboard_button->setOnClick([this](ViewNode& view) {
        finishActivity();
    });

    ui_layer->attachChild(std::move(keyboard_button));
}

KeyboardSettingActivity::~KeyboardSettingActivity()
{
}

bool KeyboardSettingActivity::handleEvent(sf::Event &event)
{
    return Activity::handleEvent(event);
}

bool KeyboardSettingActivity::handleRealtimeInput()
{
    return Activity::handleRealtimeInput();
}

bool KeyboardSettingActivity::update(sf::Time dt)
{
    return Activity::update(dt);
}

bool KeyboardSettingActivity::draw()
{
    return Activity::draw();
}
