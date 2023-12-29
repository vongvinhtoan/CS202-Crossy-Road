#pragma once

#include <ViewNode.hpp>

class ModalView : public ViewNode
{
public:
    ModalView();
    ModalView(char letter);
    virtual ~ModalView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

private:
    sf::RectangleShape mBackground, mTextEdit;
    sf::Text mText, mIntroduction, mIntroduction2, mWarning;
};