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

    auto w_button = std::make_unique<RectangleButtonView>(sf::Vector2f(151, 151));
    w_button->setPosition(sf::Vector2f(714, 356));
    w_button->setButtonColor(utils::hexToColor("D9D9D9"));
    ui_layer->attachChild(std::move(w_button));

    auto w_button_text = std::make_unique<TextView>(sf::Text("W", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    w_button_text->setPosition(sf::Vector2f(757, 408));
    text_layer->attachChild(std::move(w_button_text));

    auto w_button_text2 = std::make_unique<TextView>(sf::Text("Move up", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    w_button_text2->setPosition(sf::Vector2f(650, 260));
    text_layer->attachChild(std::move(w_button_text2));

    auto a_button = std::make_unique<RectangleButtonView>(sf::Vector2f(151, 151));
    a_button->setPosition(sf::Vector2f(476, 561));
    a_button->setButtonColor(utils::hexToColor("D9D9D9"));
    ui_layer->attachChild(std::move(a_button));

    auto a_button_text = std::make_unique<TextView>(sf::Text("A", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    a_button_text->setPosition(sf::Vector2f(519, 613));
    text_layer->attachChild(std::move(a_button_text));

    auto a_button_text2 = std::make_unique<TextView>(sf::Text("Move left", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    a_button_text2->setPosition(sf::Vector2f(81, 616));
    text_layer->attachChild(std::move(a_button_text2));

    auto s_button = std::make_unique<RectangleButtonView>(sf::Vector2f(151, 151));
    s_button->setPosition(sf::Vector2f(714, 561));
    s_button->setButtonColor(utils::hexToColor("D9D9D9"));
    ui_layer->attachChild(std::move(s_button));

    auto s_button_text = std::make_unique<TextView>(sf::Text("S", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    s_button_text->setPosition(sf::Vector2f(757, 613));
    text_layer->attachChild(std::move(s_button_text));

    auto s_button_text2 = std::make_unique<TextView>(sf::Text("Move down", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    s_button_text2->setPosition(sf::Vector2f(595, 771));
    text_layer->attachChild(std::move(s_button_text2));

    auto d_button = std::make_unique<RectangleButtonView>(sf::Vector2f(151, 151));
    d_button->setPosition(sf::Vector2f(952, 561));
    d_button->setButtonColor(utils::hexToColor("D9D9D9"));
    ui_layer->attachChild(std::move(d_button));

    auto d_button_text = std::make_unique<TextView>(sf::Text("D", getContext()->getFonts()->get(FontID::Inter_Bold), 60));
    d_button_text->setPosition(sf::Vector2f(995, 613));
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
