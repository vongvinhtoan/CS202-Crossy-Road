#include <ViewNode.hpp>
#include <cassert>
#include <iostream>

ViewNode::ViewNode()
{
}

ViewNode::~ViewNode()
{
}

void ViewNode::toggle() { m_enabled = !m_enabled; }
void ViewNode::enable() { m_enabled = true; }
void ViewNode::disable() { m_enabled = false; }
void ViewNode::hide() { m_hidden = true; }
void ViewNode::show() { m_hidden = false; }

bool ViewNode::isHidden() const { return m_hidden; }

void ViewNode::attachChild(std::unique_ptr<ViewNode> child)
{
    child->m_parent = this;
    m_children.push_back(std::move(child));
}

std::unique_ptr<ViewNode> ViewNode::detachChild(const ViewNode& node)
{
    auto found = std::find_if(m_children.begin(), m_children.end(),
        [&node](std::unique_ptr<ViewNode>& p) -> bool { return p.get() == &node; });

    assert(found != m_children.end());

    std::unique_ptr<ViewNode> result = std::move(*found);
    result->m_parent = nullptr;
    m_children.erase(found);
    return result;
}

void ViewNode::drawIfEnabled(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(this->m_enabled)
        draw(target, states);
}

Context* ViewNode::getContext() const
{
    return &Context::getInstance();
}

sf::Vector2f ViewNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

sf::Transform ViewNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const ViewNode* node = this; node != nullptr; node = node->m_parent)
        transform = node->getTransform() * transform;

    return transform;
}

bool ViewNode::contains(sf::Vector2f point) const
{
    return false;
}

void ViewNode::handleEventWithCommand(sf::Event& event, Command& command)
{
    if(!this->m_enabled) return;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*getContext()->getWindow());
    sf::Vector2f localMousePosition = getWorldTransform().getInverse().transformPoint(mousePosition.x, mousePosition.y);

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(contains(localMousePosition))
        {
            m_isHolding = true;
            m_holdClock.restart();

            if(command.isOnClicked() && m_onClick)
                m_onClick(*this);

            command.remove(Command::OnClick);
        }
        else
        {
            m_isHolding = false;

            if(m_onClickAway)
                m_onClickAway(*this);
        }
    }
    else if(event.type == sf::Event::MouseButtonReleased)
    {
        m_isHolding = false;
    }
}

void ViewNode::handleRealtimeInputWithCommand(Command& command)
{
    if(!this->m_enabled) return;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*getContext()->getWindow());
    sf::Vector2f localMousePosition = getWorldTransform().getInverse().transformPoint(mousePosition.x, mousePosition.y);

    if(!contains(localMousePosition) || !command.isOnHovered())
    {
        if(m_onLostHover)
            m_onLostHover(*this);

        m_isHolding = false;
    }
    if(contains(localMousePosition))
    {
        if(m_isHolding && m_holdClock.getElapsedTime() >= m_holdRequiredTime)
        {
            if(m_onHold)
                m_onHold(*this), command.remove(Command::OnHold);
        }
        else if(!m_isHolding)
        {
            if(m_onHover)
                m_onHover(*this), command.remove(Command::OnHover);
        }
    }
}

void ViewNode::setOnClick(std::function<void(ViewNode&)> onClick)
{
    m_onClick = onClick;
}

void ViewNode::setOnClickAway(std::function<void(ViewNode&)> onClickAway)
{
    m_onClickAway = onClickAway;
}

void ViewNode::setOnHover(std::function<void(ViewNode&)> onHover)
{
    m_onHover = onHover;
}

void ViewNode::setOnLostHover(std::function<void(ViewNode&)> onLostHover)
{
    m_onLostHover = onLostHover;
}

void ViewNode::setOnHold(std::function<void(ViewNode&)> onHold)
{
    m_onHold = onHold;
}