#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <ViewTree.hpp>
#include <Context.hpp>
#include <Extra.hpp>
#include <ActivityIdentifiers.hpp>
#include <iostream>
#include <ViewList.hpp>

class ActivityStack;

class Activity
{
friend class ActivityStack;

public:
    Activity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~Activity();

protected:
    virtual bool handleEvent(sf::Event& event) = 0;
    virtual bool handleRealtimeInput() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool draw() = 0;

protected:
    void requestActivity(ActivityID activityID);
    void requestActivity(ActivityID activityID, int requestCode, Extra* extra);
    void finishActivity();
    void finishActivity(int resultCode, Extra* extra);
    virtual void onActivityResult(int resultCode, Extra* extra);

protected:
    ViewNode* getLayer(int layer);
    ViewNode* getViewRoot();
    Context* getContext() const;

private:
    ActivityStack*              m_stack;
    std::unique_ptr<ViewTree>   m_viewTree;
    Context*                    m_context;
    std::vector<ViewNode*>      m_layers;
};

