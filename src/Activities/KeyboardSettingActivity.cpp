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

    // W Button
    buttonPosition = sf::Vector2f(714, 356);
    auto w_button = std::make_unique<RectangleButtonView>(buttonSize);
    w_button->setPosition(buttonPosition);
    w_button->get().setFillColor(buttonColor);
    ui_layer->attachChild(std::move(w_button));

    auto w_button_text = std::make_unique<TextView>(sf::Text("W", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    w_button_text->setPosition(sf::Vector2f(757, 408));
    w_button_text->get().setFillColor(textColor);
    text_layer->attachChild(std::move(w_button_text));

    auto w_button_text2 = std::make_unique<TextView>(sf::Text("Move up", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    w_button_text2->setPosition(sf::Vector2f(650, 260));
    text_layer->attachChild(std::move(w_button_text2));

    // A Button
    buttonPosition = sf::Vector2f(476, 561);
    auto a_button = std::make_unique<RectangleButtonView>(buttonSize);
    a_button->setPosition(buttonPosition);
    a_button->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(a_button));

    auto a_button_text = std::make_unique<TextView>(sf::Text("A", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    a_button_text->setPosition(sf::Vector2f(519, 613));
    a_button_text->get().setFillColor(textColor);
    text_layer->attachChild(std::move(a_button_text));

    auto a_button_text2 = std::make_unique<TextView>(sf::Text("Move left", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    a_button_text2->setPosition(sf::Vector2f(81, 616));
    text_layer->attachChild(std::move(a_button_text2));

    // S Button
    buttonPosition = sf::Vector2f(714, 561);
    auto s_button = std::make_unique<RectangleButtonView>(buttonSize);
    s_button->setPosition(buttonPosition);
    s_button->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(s_button));

    auto s_button_text = std::make_unique<TextView>(sf::Text("S", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    s_button_text->setPosition(sf::Vector2f(757, 613));
    s_button_text->get().setFillColor(textColor);
    text_layer->attachChild(std::move(s_button_text));

    auto s_button_text2 = std::make_unique<TextView>(sf::Text("Move down", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    s_button_text2->setPosition(sf::Vector2f(595, 771));
    text_layer->attachChild(std::move(s_button_text2));

    // D Button
    buttonPosition = sf::Vector2f(952, 561);
    auto d_button = std::make_unique<RectangleButtonView>(buttonSize);
    d_button->setPosition(buttonPosition);
    d_button->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(d_button));

    auto d_button_text = std::make_unique<TextView>(sf::Text("D", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    d_button_text->setPosition(sf::Vector2f(995, 613));
    d_button_text->get().setFillColor(textColor);
    text_layer->attachChild(std::move(d_button_text));

    auto d_button_text2 = std::make_unique<TextView>(sf::Text("Move right", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    d_button_text2->setPosition(sf::Vector2f(1149, 618));
    text_layer->attachChild(std::move(d_button_text2));
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
