#include <Activity.hpp>
#include <ActivityStack.hpp>
#include <ViewList.hpp>

Activity::Activity(ActivityStack &stack, int requestCode, Extra &extra)
    : m_stack(&stack), m_viewTree(std::make_unique<ViewTree>()), m_context(&Context::getInstance())
{
}

Activity::~Activity()
{
}

bool Activity::handleEvent(sf::Event &event)
{
    m_viewTree->handleEvent(event);
    return true;
}

bool Activity::handleRealtimeInput()
{
    m_viewTree->handleRealtimeInput();
    return true;
}

bool Activity::update(sf::Time dt)
{
    m_viewTree->update(dt);
    return true;
}

bool Activity::draw()
{
    m_context->getWindow()->draw(*m_viewTree);
    return true;
}

ViewNode *Activity::getLayer(int layer)
{
    while (m_layers.size() <= layer)
    {
        std::unique_ptr<ViewNode> node = std::make_unique<EmptyView>();
        m_layers.push_back(node.get());
        m_viewTree->getRoot()->attachChild(std::move(node));
    }

    return m_layers[layer];
}

ViewNode *Activity::getViewRoot()
{
    return m_viewTree->getRoot();
}

Context *Activity::getContext() const
{
    return m_context;
}

void Activity::requestActivity(ActivityID activityID)
{
    m_stack->pushActivity(activityID);
}

void Activity::requestActivity(ActivityID activityID, int requestCode, Extra *extra)
{
    m_stack->pushActivity(activityID, requestCode, extra);
}

void Activity::finishActivity()
{
    m_stack->backActivity();
}

void Activity::finishActivity(int resultCode, Extra *extra)
{
    m_stack->backActivity(resultCode, extra);
}

void Activity::onActivityResult(int resultCode, Extra *extra)
{
}