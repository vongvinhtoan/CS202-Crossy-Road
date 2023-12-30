#pragma once

#include <ViewNode.hpp>

class RectangleView;

class ModalView : public ViewNode
{
public:
    ModalView();
    virtual ~ModalView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
    void setButtonIndex(int index);

private:
    sf::RectangleShape mBackground, mTextEdit;
    RectangleView* mCloseButton;
    sf::Text mText, mIntroduction, mIntroduction2, mWarning;
    int buttonClickedIndex;
};