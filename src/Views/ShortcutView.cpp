#include <Views/ShortcutView.hpp>
#include <Utils.hpp>
#include <Views/TextView.hpp>
#include <Views/RectangleButtonView.hpp>

ShortcutView::ShortcutView()
{
    sf::Color buttonColor = utils::hexToColor("D9D9D9");
    sf::Color textColor = utils::hexToColor("000000");
    sf::Vector2f buttonSize(151, 151);
    sf::Vector2f buttonPosition;

    std::vector<sf::Vector2f> buttonPositions = {sf::Vector2f(714, 356), sf::Vector2f(476, 561), sf::Vector2f(714, 561), sf::Vector2f(952, 561)};
    std::vector<std::string> buttonNames = {"W", "A", "S", "D"};

    for (int i = 0; i < 4; ++i)
    {
        auto text = std::make_unique<TextView>(sf::Text(buttonNames[i], getContext()->getFonts()->get(FontID::Inter_Bold), 60));
        auto text_shape = text.get();

        texts.push_back(text_shape);
        text->get().setFillColor(textColor);

        auto button = std::make_unique<RectangleButtonView>(buttonSize);
        auto button_shape = button.get();
        buttons.push_back(button_shape);
        button->setPosition(buttonPositions[i]);
        button->get().setFillColor(buttonColor);
        button->setOnClick([this, i](ViewNode &view)
                           { texts[i]->setEditable(true); });

        attachChild(std::move(button));
        attachChild(std::move(text));
    }
}

ShortcutView::~ShortcutView()
{
}

void ShortcutView::update(sf::Time dt)
{
    std::vector<sf::Vector2f> buttonPositions = {sf::Vector2f(714, 356), sf::Vector2f(476, 561), sf::Vector2f(714, 561), sf::Vector2f(952, 561)};
    std::vector<std::string> buttonNames = {"W", "A", "S", "D"};
    sf::Vector2f buttonSize(151, 151);

    for (int i = 0; i < 4; ++i)
    {
        sf::FloatRect textRect = texts[i]->get().getLocalBounds();
        sf::Vector2f textPosition = sf::Vector2f(buttonPositions[i].x + (buttonSize.x - textRect.width) / 2.0f, buttonPositions[i].y + buttonSize.y / 2.0f);
        texts[i]->setOrigin(textRect.left, textRect.top + textRect.height / 2.0f);
        texts[i]->setPosition(textPosition);
    }
}

void ShortcutView::handleEvent(sf::Event &event)
{
}

void ShortcutView::handleRealtimeInput()
{
}

void ShortcutView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}
