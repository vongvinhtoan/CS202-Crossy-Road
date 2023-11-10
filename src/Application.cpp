#include <Application.hpp>
#include <iostream>
#include <json.h>

Application::Application()
: m_backend(&Backend::getInstance())
, m_context(&Context::getInstance())
, m_fontHolder(std::make_unique<FontHolder>())
{
    loadData();

    TimePerFrame = sf::seconds(1.f / m_configs["fps"].asFloat());
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(
            m_configs["window"]["width"].asInt(), 
            m_configs["window"]["height"].asInt()
        ), 
        m_configs["window"]["title"].asString()
    );
    m_activityStack = std::make_unique<ActivityStack>(); 
    m_viewTree = std::make_unique<ViewTree>(std::make_unique<StatisticsView>(m_fontHolder->get(FontID::Main)));
    m_statisticsView = dynamic_cast<StatisticsView*>(m_viewTree->getRoot());

    m_context->setWindow(m_window.get());
    m_context->setTextures(m_textureHolder.get());
    m_context->setFonts(m_fontHolder.get());
    m_context->setBackend(m_backend.get());
    m_context->setConfigs(&m_configs);
    
    registerActivities();
    m_activityStack->pushActivity(ActivityID::Empty);
    m_activityStack->applyPendingChanges();
}

Application& Application::getInstance()
{
    static Application instance;
    return instance;
}

Application::~Application()
{
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window->isOpen())
    {
        if(m_activityStack->isEmpty()) m_window->close();

        processInput();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            if(!m_isPaused) update(TimePerFrame);
        }
        draw();
    }
}

void Application::registerActivities()
{
    m_activityStack->registerActivity<EmptyActivity>(ActivityID::Empty);
}

void Application::loadData()
{
    loadFonts();
    loadConfig();
}

void Application::loadFonts()
{
    m_backend->loadFonts(*m_fontHolder);
}

void Application::loadConfig()
{
    m_backend->loadConfigs(m_configs);
}

void Application::processInput()
{
    sf::Event event;
    while(m_window->pollEvent(event))
    {
        if(!m_isPaused) m_activityStack->handleEvent(event);
        switch (event.type)
        {
            case sf::Event::Closed:
                m_backend->save();
                m_window->close();
                break;
            case sf::Event::GainedFocus:
                m_isPaused = false;
                break;
            case sf::Event::LostFocus:
                m_isPaused = true;
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::F5) m_statisticsView->toggle();
                break;
        }
    }
    if(!m_isPaused) m_activityStack->handleRealtimeInput();
}

void Application::update(sf::Time dt)
{
    m_activityStack->update(dt);
    m_viewTree->update(dt);
}

void Application::draw()
{
    m_window->clear();
    m_activityStack->draw();
    m_window->draw(*m_viewTree);
    m_window->display();
}