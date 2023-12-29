#include <Activities/KeyboardSettingActivity.hpp>
#include <Utils.hpp>

KeyboardSettingActivity::KeyboardSettingActivity(ActivityStack &stack, int requestCode, Extra &intent)
    : Activity(stack, requestCode, intent)
{
    ViewNode *background_layer = getLayer(0);
    ViewNode *text_layer = getLayer(1);
    ViewNode *ui_layer = getLayer(2);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    auto background = std::make_unique<RectangleView>(window_size);
    auto &background_shape = background->get();
    background_shape.setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
    background_layer->attachChild(std::move(background));

    auto text = std::make_unique<TextView>(sf::Text("KEYBOARD SETTING", getContext()->getFonts()->get(FontID::Tourney_Bold), 125));
    text->setPosition(sf::Vector2f((window_size.x - text->get().getLocalBounds().width) / 2, 56));
    text_layer->attachChild(std::move(text));

    auto shortcut = std::make_unique<ShortcutView>();
    m_shortcutView = shortcut.get();
    ui_layer->attachChild(std::move(shortcut));

    auto shortcut_picture = std::make_unique<RectangleView>(sf::Vector2f(627, 356));
    shortcut_picture->get().setTexture(&getContext()->getTextures()->get(TextureID::ShortcutPicture));
    shortcut_picture->setPosition(sf::Vector2f(476, 356));
    m_shortcutPicture = shortcut_picture.get();
    text_layer->attachChild(std::move(shortcut_picture));
    m_shortcutPicture->hide();

    text = std::make_unique<TextView>(sf::Text("Move up", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    text->setPosition(sf::Vector2f(660, 230));
    text_layer->attachChild(std::move(text));

    text = std::make_unique<TextView>(sf::Text("Move left", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    text->setPosition(sf::Vector2f(81, 616));
    text_layer->attachChild(std::move(text));

    text = std::make_unique<TextView>(sf::Text("Move down", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    text->setPosition(sf::Vector2f(600, 750));
    text_layer->attachChild(std::move(text));

    text = std::make_unique<TextView>(sf::Text("Move right", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
    text->setPosition(sf::Vector2f(1149, 616));
    text_layer->attachChild(std::move(text));

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
        std::cout << "Keyboard button clicked" << std::endl;
        if(m_shortcutPicture->isHidden()) {
            m_shortcutPicture->show();
            m_shortcutView->hide();
        } else {
            m_shortcutPicture->hide();
            m_shortcutView->show();
        }
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
