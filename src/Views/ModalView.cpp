#include <Views/ModalView.hpp>
#include <Utils.hpp>
#include <Views/RectangleView.hpp>
#include <ConfigManager.hpp>

ModalView::ModalView()
{
    sf::Font &font = getContext()->getFonts()->get(FontID::Tourney_Bold);

    mBackground.setFillColor(utils::hexToColor("D9D9D9"));
    mBackground.setOutlineColor(sf::Color::Black);
    mBackground.setOutlineThickness(1.0f);
    mBackground.setSize(sf::Vector2f(1000, 514));

    mWarning.setFillColor(sf::Color::Black);
    mWarning.setString("Change your shortcuts.");
    mWarning.setFont(font);
    mWarning.setCharacterSize(50);

    mIntroduction.setFillColor(sf::Color::Black);
    mIntroduction.setString("Only one letter.");
    mIntroduction.setFont(font);
    mIntroduction.setCharacterSize(50);

    mIntroduction2.setFillColor(sf::Color::Black);
    mIntroduction2.setString("Enter to SAVE");
    mIntroduction2.setFont(font);
    mIntroduction2.setCharacterSize(50);

    mTextEdit.setFillColor(utils::hexToColor("C0C0C0"));
    mTextEdit.setOutlineColor(sf::Color::Black);
    mTextEdit.setOutlineThickness(2.0f);
    mTextEdit.setSize(sf::Vector2f(151, 151));
    mTextEdit.setPosition((mBackground.getSize().x - mTextEdit.getLocalBounds().width) / 2, (mBackground.getSize().y - mTextEdit.getLocalBounds().height) / 2);

    mText.setFillColor(sf::Color::Black);
    mText.setFont(getContext()->getFonts()->get(FontID::Inter_Bold));
    mText.setCharacterSize(60);

    sf::FloatRect introRect = mIntroduction.getLocalBounds();
    sf::Vector2f introPosition = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - introRect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f - 150.0f);
    mIntroduction.setOrigin(introRect.left, introRect.top + introRect.height / 2.0f);
    mIntroduction.setPosition(introPosition);

    sf::FloatRect intro2Rect = mIntroduction2.getLocalBounds();
    sf::Vector2f intro2Position = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - intro2Rect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f + 200.0f);
    mIntroduction2.setOrigin(intro2Rect.left, intro2Rect.top + intro2Rect.height / 2.0f);
    mIntroduction2.setPosition(intro2Position);

    auto closeButton = std::make_unique<RectangleView>(sf::Vector2f(63, 65));
    closeButton->get().setTexture(&getContext()->getTextures()->get(TextureID::CloseButton));
    closeButton->setPosition(sf::Vector2f(mBackground.getPosition().x + mBackground.getSize().x - 90, mBackground.getPosition().y + 20));
    closeButton->setOnClick([this](ViewNode &view)
                            { hide(); });
    closeButton->setOnHover([this](ViewNode &view)
                            { mCloseButton->get().setTexture(&getContext()->getTextures()->get(TextureID::CloseButtonHover)); });
    closeButton->setOnLostHover([this](ViewNode &view)
                                { mCloseButton->get().setTexture(&getContext()->getTextures()->get(TextureID::CloseButton)); });
    mCloseButton = closeButton.get();
    attachChild(std::move(closeButton));
}

ModalView::~ModalView()
{
}

void ModalView::update(sf::Time dt)
{
    sf::FloatRect warningRect = mWarning.getLocalBounds();
    sf::Vector2f warningPosition = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - warningRect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f - 200.0f);
    mWarning.setOrigin(warningRect.left, warningRect.top + warningRect.height / 2.0f);
    mWarning.setPosition(warningPosition);

    sf::FloatRect textRect = mText.getLocalBounds();
    sf::Vector2f textPosition = sf::Vector2f(mTextEdit.getPosition().x + (mTextEdit.getSize().x - textRect.width) / 2.0f, mTextEdit.getPosition().y + mTextEdit.getSize().y / 2.0f);
    mText.setOrigin(textRect.left, textRect.top + textRect.height / 2.0f);
    mText.setPosition(textPosition);
}

void ModalView::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z)
        {
            char letter = static_cast<char>(event.key.code + 65);
            mText.setString(std::string(1, letter));
        }

        std::vector<char> keys = getKeysFromConfigFile();
        auto it = std::find_if(keys.begin(), keys.end(), [this](char key)
                               { return key == mText.getString()[0]; });

        mWarning.setString(it != keys.end() ? "This letter is already used." : "Change your shortcuts.");

        if (event.key.code == sf::Keyboard::Enter)
        {
            if (it == keys.end() && mText.getString() != "")
            {
                int keyNum = mText.getString()[0] - 65;
                updateConfigFile(buttonClickedIndex == 0 ? "moveUp" : buttonClickedIndex == 1 ? "moveLeft"
                                                                  : buttonClickedIndex == 2   ? "moveDown"
                                                                  : buttonClickedIndex == 3   ? "moveRight"
                                                                                              : "",
                                 sf::Keyboard::Key(keyNum));
                hide();
                mText.setString("");
            }
        }
    }
}

void ModalView::handleRealtimeInput()
{
}

void ModalView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mBackground, states);
    target.draw(mWarning, states);
    target.draw(mIntroduction, states);
    target.draw(mIntroduction2, states);
    target.draw(mTextEdit, states);
    target.draw(mText, states);
}

void ModalView::setButtonIndex(int index)
{
    buttonClickedIndex = index;
}
