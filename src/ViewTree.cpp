#include <ViewTree.hpp>

ViewTree::ViewTree()
: m_root(std::make_unique<EmptyView>())
{
}

ViewTree::ViewTree(std::unique_ptr<ViewNode> root)
: m_root(std::move(root))
{
}

ViewTree::~ViewTree()
{
}

void ViewTree::setRoot(std::unique_ptr<ViewNode> root)
{
    m_root = std::move(root);
}

ViewNode* ViewTree::getRoot() const
{
    return m_root.get();
}

void ViewTree::update(sf::Time dt)
{
    if (!m_root) return;

    update(dt, *m_root);
}

void ViewTree::handleEvent(sf::Event& event)
{
    if (!m_root) return;

    Command command;
    handleEvent(event, *m_root, command);
}

void ViewTree::handleRealtimeInput()
{
    if (!m_root) return;

    Command command;
    handleRealtimeInput(*m_root, command);
}

void ViewTree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!m_root) return;
    if(!m_root->m_hidden) {
        draw(target, states, *m_root);
    }
}

void ViewTree::update(sf::Time dt, ViewNode& node)
{
    for (auto &child: node.m_children)
        update(dt, *child);
    
    node.update(dt);
}

void ViewTree::handleEvent(sf::Event& event, ViewNode& node, Command& command)
{
    for (auto it = node.m_children.rbegin(); it != node.m_children.rend(); ++it)
        handleEvent(event, **it, command);
    
    node.handleEvent(event);
    node.handleEventWithCommand(event, command);
}

void ViewTree::handleRealtimeInput(ViewNode& node, Command& command)
{
    for (auto it = node.m_children.rbegin(); it != node.m_children.rend(); ++it)
        handleRealtimeInput(**it, command);
    
    node.handleRealtimeInput();
    node.handleRealtimeInputWithCommand(command);
}

void ViewTree::draw(sf::RenderTarget& target, sf::RenderStates states, const ViewNode& node) const
{
    states.transform *= node.getTransform();
    
    node.drawIfEnabled(target, states);

    for (auto& child : node.m_children) {
        if(!child->m_hidden) {
            draw(target, states, *child);
        }
    }
}