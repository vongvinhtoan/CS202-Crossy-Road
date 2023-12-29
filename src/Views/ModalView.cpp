#include <Views/ModalView.hpp>
#include <Utils.hpp>

ModalView::ModalView()
{
    sf::Font& font = getContext()->getFonts()->get(FontID::Tourney_Bold);

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

    mTextEdit.setFillColor(utils::hexToColor("D9D9D9"));
    mTextEdit.setOutlineColor(sf::Color::Black);
    mTextEdit.setOutlineThickness(1.0f);

    mText.setFillColor(sf::Color::Black);
    mText.setFont(getContext()->getFonts()->get(FontID::Inter_Bold));
    mText.setCharacterSize(60);
}

ModalView::ModalView(char letter)
    : ModalView()
{
    mText.setString(letter);
}

ModalView::~ModalView()
{
}

void ModalView::update(sf::Time dt)
{
}

void ModalView::handleEvent(sf::Event& event)
{
}

void ModalView::handleRealtimeInput()
{
}

void ModalView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}