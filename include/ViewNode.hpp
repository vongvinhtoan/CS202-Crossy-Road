#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <functional>
#include <Command.hpp>
#include <Context.hpp>

class ViewTree;

class ViewNode :
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{

friend class ViewTree;

public:
    ViewNode();
    virtual ~ViewNode();

public:
    void                        attachChild(std::unique_ptr<ViewNode> child);
    std::unique_ptr<ViewNode>   detachChild(const ViewNode& node);
    Context*                    getContext() const;
    sf::Vector2f                getWorldPosition() const;
    sf::Transform               getWorldTransform() const;
    virtual bool                contains(sf::Vector2f point) const;

public:
    virtual void setOnClick(std::function<void(ViewNode&)> onClick);
    virtual void setOnClickAway(std::function<void(ViewNode&)> onClickAway);
    virtual void setOnHover(std::function<void(ViewNode&)> onHover);
    virtual void setOnLostHover(std::function<void(ViewNode&)> onLostHover);
    virtual void setOnHold(std::function<void(ViewNode&)> onHold);

protected:
    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void handleRealtimeInput() = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private:
    void handleEventWithCommand(sf::Event& event, Command& command);
    void handleRealtimeInputWithCommand(Command& command);

private:
    void drawIfEnabled(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    void toggle();
    void enable();
    void disable();
    bool isEnabled();

private:
    ViewNode*                               m_parent = nullptr;
    bool                                    m_enabled = true;
    bool                                    m_isHolding = false;
    sf::Clock                               m_holdClock;
    sf::Time                                m_holdRequiredTime = sf::seconds(0.15f);
    std::vector<std::unique_ptr<ViewNode>>  m_children;

protected:
    std::function<void(ViewNode&)>          m_onClick;
    std::function<void(ViewNode&)>          m_onClickAway;
    std::function<void(ViewNode&)>          m_onHover;
    std::function<void(ViewNode&)>          m_onLostHover;
    std::function<void(ViewNode&)>          m_onHold;
};