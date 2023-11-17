#include <ActivityStack.hpp>
#include <ActivityPendingChange.hpp>

ActivityStack::ActivityStack()
{
}

ActivityStack::~ActivityStack()
{
}

bool ActivityStack::isEmpty() const
{
    return m_stack.empty();
}

void ActivityStack::handleEvent(sf::Event& event)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleEvent(event)) break;
    }

    applyPendingChanges();
}

void ActivityStack::handleRealtimeInput()
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleRealtimeInput()) break;
    }

    applyPendingChanges();
}

void ActivityStack::update(sf::Time dt)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->update(dt)) break;
    }

    applyPendingChanges();
}

void ActivityStack::draw()
{
    for(auto it = m_stack.begin(); it != m_stack.end(); ++it)
    {
        (*it)->draw();
    }

    applyPendingChanges();
}

void ActivityStack::pushActivity(ActivityID activityID)
{
    PendingChange change;
    change.setAction(Action::Push)
            .setActivityID(activityID)
            .setRequestCode(0)
            .setExtra(new Extra());
    m_pendingList.push_back(change);
}

void ActivityStack::pushActivity(ActivityID activityID, int requestCode, Extra* extra)
{
    PendingChange change;
    change.setAction(Action::Push)
            .setActivityID(activityID)
            .setRequestCode(requestCode)
            .setExtra(extra);
    m_pendingList.push_back(change);
}

void ActivityStack::backActivity()
{
    PendingChange change;
    change.setAction(Action::Back);
    m_pendingList.push_back(change);
}

void ActivityStack::backActivity(int resultCode, Extra* extra)
{
    PendingChange change;
    change.setAction(Action::Back)
            .setResultCode(resultCode)
            .setExtra(extra);
    m_pendingList.push_back(change);
}

void ActivityStack::clearActivities()
{
    PendingChange change;
    change.setAction(Action::Clear);
    m_pendingList.push_back(change);
}

void ActivityStack::applyPendingChanges()
{
    for(size_t i = 0; i < m_pendingList.size(); ++i)
    {
        PendingChange& change = m_pendingList[i];
        switch(change.getAction())
        {
            case Action::Push:
                applyPush(change);
                break;
            case Action::Pop:
                applyPop(change);
                break;
            case Action::Clear:
                applyClear(change);
                break;
            case Action::Back:
                applyBack(change);
                break;
        }
    }
    m_pendingList.clear();
}

void ActivityStack::applyPush(PendingChange& change)
{
    ActivityID activityID = change.getActivityID();
    int requestCode = change.getRequestCode();
    Extra* extra = change.getExtra();

    if (m_factory.find(activityID) == m_factory.end())
        throw std::runtime_error("ActivityStack::applyPendingChanges() : activity not registered");

    std::unique_ptr<Activity> activity = m_factory[activityID](*this, requestCode, *extra);

    m_stack.push_back(std::move(activity));
}

void ActivityStack::applyPop(PendingChange& change)
{
    if(m_stack.empty())
        throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot pop");
    m_stack.pop_back();
}

void ActivityStack::applyClear(PendingChange& change)
{
    m_stack.clear();
}

void ActivityStack::applyBack(PendingChange& change)
{
    if(m_stack.empty())
        throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot pop");
    m_stack.pop_back();

    if(m_stack.empty())
        throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot back");
    m_stack.back()->onActivityResult(change.getResultCode(), change.getExtra());
}