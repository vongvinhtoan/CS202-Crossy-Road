#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Activity.hpp>
#include <ActivityIdentifiers.hpp>
#include <Extra.hpp>
#include <memory>
#include <vector>
#include <map>
#include <functional>

class PendingChange;

class ActivityStack
{
private:
    friend class PendingChange;
    friend class PendingChangeBuilder;

    enum class Action;

public:
    ActivityStack();
    ~ActivityStack();

public:
    template <typename ActivityChild>
    void registerActivity(ActivityID activityID);

public:
    bool isEmpty() const;
    void handleEvent(sf::Event& event);
    void handleRealtimeInput();
    void update(sf::Time dt);
    void draw();

public:
    void pushActivity(ActivityID activityID);
    void pushActivity(ActivityID activityID, int requestCode,  Extra* extra);
    void backActivity();
    void backActivity(int resultCode, Extra* extra);
    void clearActivities();
    void applyPendingChanges();

private:
    void applyPush(PendingChange& change);
    void applyPop(PendingChange& change);
    void applyClear(PendingChange& change);
    void applyBack(PendingChange& change);

private:
    std::vector<std::unique_ptr<Activity>>  m_stack;
    std::vector<PendingChange>              m_pendingList;
    
    using GenFunction = std::function<std::unique_ptr<Activity>(ActivityStack&, int, Extra&)>;
    std::map<ActivityID, GenFunction>       m_factory;
};

enum class ActivityStack::Action
{
    Null,
    Push,
    Pop,
    Clear,
    Back
};

template <typename ActivityChild>
void ActivityStack::registerActivity(ActivityID activityID) 
{
    auto function = std::function<std::unique_ptr<Activity>(ActivityStack&, int, Extra&)> (
        [&] (ActivityStack& stack, int requestCode, Extra& extra) -> std::unique_ptr<Activity> {
            return std::make_unique<ActivityChild>(stack, requestCode, extra);
        }
    );

    m_factory[activityID] = function;
}