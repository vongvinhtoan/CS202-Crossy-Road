#pragma once

#include <ViewNode.hpp>

class TextView;
class RectangleButtonView;
class ModalView;

class ShortcutView : public ViewNode
{
public:
    ShortcutView();
    virtual ~ShortcutView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:

private:
    std::vector<RectangleButtonView*> buttons;
    std::vector<TextView*> texts;
    ModalView* modalView;
};