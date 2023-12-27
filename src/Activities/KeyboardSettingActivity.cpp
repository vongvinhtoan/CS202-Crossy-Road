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
    buttons.push_back(std::make_unique<RectangleButtonView>(buttonSize));
    buttons.back()->setPosition(buttonPosition);
    buttons.back()->get().setFillColor(buttonColor);
    ui_layer->attachChild(std::move(buttons.back()));

    texts.push_back(std::make_unique<TextView>(sf::Text("W", getContext()->getFonts()->get(FontID::Inter_Bold), 60)));
    texts.back()->setPosition(sf::Vector2f(757, 408));
    texts.back()->get().setFillColor(textColor);
    text_layer->attachChild(std::move(texts.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move up", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(650, 260));
    text_layer->attachChild(std::move(texts2.back()));

    // A Button
    buttonPosition = sf::Vector2f(476, 561);
    buttons.push_back(std::make_unique<RectangleButtonView>(buttonSize));
    buttons.back()->setPosition(buttonPosition);
    buttons.back()->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(buttons.back()));

    texts.push_back(std::make_unique<TextView>(sf::Text("A", getContext()->getFonts()->get(FontID::Inter_Bold), 60)));
    texts.back()->setPosition(sf::Vector2f(519, 613));
    texts.back()->get().setFillColor(textColor);
    text_layer->attachChild(std::move(texts.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move left", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(81, 616));
    text_layer->attachChild(std::move(texts2.back()));

    // S Button
    buttonPosition = sf::Vector2f(714, 561);
    buttons.push_back(std::make_unique<RectangleButtonView>(buttonSize));
    buttons.back()->setPosition(buttonPosition);
    buttons.back()->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(buttons.back()));

    texts.push_back(std::make_unique<TextView>(sf::Text("S", getContext()->getFonts()->get(FontID::Inter_Bold), 60)));
    texts.back()->setPosition(sf::Vector2f(757, 613));
    texts.back()->get().setFillColor(textColor);
    text_layer->attachChild(std::move(texts.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move down", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(595, 771));
    text_layer->attachChild(std::move(texts2.back()));

    // D Button
    buttonPosition = sf::Vector2f(952, 561);
    buttons.push_back(std::make_unique<RectangleButtonView>(buttonSize));
    buttons.back()->setPosition(buttonPosition);
    buttons.back()->setButtonColor(buttonColor);
    ui_layer->attachChild(std::move(buttons.back()));

    texts.push_back(std::make_unique<TextView>(sf::Text("D", getContext()->getFonts()->get(FontID::Inter_Bold), 60)));
    texts.back()->setPosition(sf::Vector2f(995, 613));
    texts.back()->get().setFillColor(textColor);
    text_layer->attachChild(std::move(texts.back()));

    texts2.push_back(std::make_unique<TextView>(sf::Text("Move right", getContext()->getFonts()->get(FontID::Tourney_Bold), 69)));
    texts2.back()->setPosition(sf::Vector2f(1149, 618));
    text_layer->attachChild(std::move(texts2.back()));
}

KeyboardSettingActivity::~KeyboardSettingActivity()
{
}

bool KeyboardSettingActivity::handleEvent(sf::Event &event)
{
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
