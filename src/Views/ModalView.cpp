#include <Views/ModalView.hpp>
#include <Utils.hpp>

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

    sf::FloatRect warningRect = mWarning.getLocalBounds();
    sf::Vector2f warningPosition = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - warningRect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f - 200.0f);
    mWarning.setOrigin(warningRect.left, warningRect.top + warningRect.height / 2.0f);
    mWarning.setPosition(warningPosition);

    sf::FloatRect introRect = mIntroduction.getLocalBounds();
    sf::Vector2f introPosition = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - introRect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f - 150.0f);
    mIntroduction.setOrigin(introRect.left, introRect.top + introRect.height / 2.0f);
    mIntroduction.setPosition(introPosition);

    sf::FloatRect intro2Rect = mIntroduction2.getLocalBounds();
    sf::Vector2f intro2Position = sf::Vector2f(mBackground.getPosition().x + (mBackground.getSize().x - intro2Rect.width) / 2.0f, mBackground.getPosition().y + mBackground.getSize().y / 2.0f + 200.0f);
    mIntroduction2.setOrigin(intro2Rect.left, intro2Rect.top + intro2Rect.height / 2.0f);
    mIntroduction2.setPosition(intro2Position);
}

ModalView::~ModalView()
{
}

void ModalView::update(sf::Time dt)
{
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

        if (event.key.code == sf::Keyboard::Enter)
        {
            hide();
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

void ModalView::setLetter(char letter)
{
    mText.setString(std::string(1, letter));
}