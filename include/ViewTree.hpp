#pragma once

#include <ViewList.hpp>
#include <ViewNode.hpp>
#include <Command.hpp>

class ViewTree : public sf::Drawable, public sf::Transformable
{
public:
    ViewTree();
    ViewTree(std::unique_ptr<ViewNode> root);
    ~ViewTree();

public:
    void setRoot(std::unique_ptr<ViewNode> root);
    ViewNode* getRoot() const;

public:
    void update(sf::Time dt);
    void handleEvent(sf::Event& event);
    void handleRealtimeInput();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    void update(sf::Time dt, ViewNode& node);
    void handleEvent(sf::Event& event, ViewNode& node, Command& command);
    void handleRealtimeInput(ViewNode& node, Command& command);
    void draw(sf::RenderTarget& target, sf::RenderStates states, const ViewNode& node) const;

private:
    std::unique_ptr<ViewNode> m_root;
};