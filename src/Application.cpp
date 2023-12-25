#include <Application.hpp>
#include <iostream>
#include <json.h>

Application::Application()
: m_backend(&Backend::getInstance())
, m_context(&Context::getInstance())
, m_fontHolder(std::make_unique<FontHolder>())
, m_textureHolder(std::make_unique<TextureHolder>())
{
    loadData();

    TimePerFrame = sf::seconds(1.f / m_configs["fps"].asFloat());
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(
            m_configs["window"]["width"].asInt(), 
            m_configs["window"]["height"].asInt()
        )
        , m_configs["window"]["title"].asString()
        , sf::Style::Close
    );
    m_window->setFramerateLimit(m_configs["fps"].asFloat());
    m_window->setKeyRepeatEnabled(false);
    m_activityStack = std::make_unique<ActivityStack>(); 
    m_viewTree = std::make_unique<ViewTree>(std::make_unique<StatisticsView>(m_fontHolder->get(FontID::Main)));
    m_statisticsView = dynamic_cast<StatisticsView*>(m_viewTree->getRoot());
    if(m_configs["hide_statistic"].asBool()) m_statisticsView->toggle();

    m_context->setWindow(m_window.get());
    m_context->setTextures(m_textureHolder.get());
    m_context->setFonts(m_fontHolder.get());
    m_context->setBackend(m_backend);
    m_context->setConfigs(&m_configs);
    
    registerActivities();
    m_activityStack->pushActivity(ActivityID::Main);
    m_activityStack->applyPendingChanges();
}

Application& Application::getInstance()
{
    static Application instance;
    return instance;
}

Application::~Application()
{
    saveData();
}

void Application::saveData()
{
    m_backend->saveConfig(m_configs);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window->isOpen()) {
        if(m_activityStack->isEmpty()) {
            m_window->close();
            return;
        }

        if(!processInput()) return;
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            if(!processInput()) return;
            if(!m_isPaused) update(TimePerFrame);
        }
        draw();
    }
}

void Application::loadData()
{
    loadTextures();
    loadFonts();
    loadConfig();
}

void Application::loadTextures()
{
    m_backend->loadTextures(*m_textureHolder);
}

void Application::loadFonts()
{
    m_backend->loadFonts(*m_fontHolder);
}

void Application::loadConfig()
{
    m_backend->loadConfigs(m_configs);
}

bool Application::processInput()
{
    sf::Event event;
    while(m_window->pollEvent(event))
    {
        if(!m_isPaused) m_activityStack->handleEvent(event);
        switch (event.type)
        {
            case sf::Event::Closed:
                m_window->close();
                return false;
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
    return true;
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