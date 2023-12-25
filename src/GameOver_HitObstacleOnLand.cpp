#include <GameOver_HitObstacleOnLand.hpp>
#include <Utils.hpp>

const sf::Vector2f GameOver_HitObstacleOnLand::m_acceleration = sf::Vector2f(0, 1000.f);

GameOver_HitObstacleOnLand::GameOver_HitObstacleOnLand(Game* game)
: GameOverStategy(game)
, m_elapsedTime(sf::Time::Zero)
, m_animationTime(sf::seconds(3.f))
, m_velocity(sf::Vector2f(100.f, -300.f))
{
    std::cout << "GameOver_HitObstacleOnLand" << std::endl;
    auto* player = getGame()->getPlayer();
    auto* adapter = getGame()->getAdapter();
    auto playerRect = adapter->getPlayer()->getTransformed();
    
    player->setInvincible(true);
    
    m_overlay = playerRect;
    m_overlay.setFillColor(playerRect.getFillColor());
    m_overlay.setPosition(playerRect.getPosition());
    m_overlay.setSize(playerRect.getSize());

    if(utils::random(0, 1))
        m_velocity.x *= -1;
}

void GameOver_HitObstacleOnLand::update(sf::Time dt)
{
    m_elapsedTime += dt;
    if(m_overlay.getPosition().y - 100.f > (*Context::getInstance().getWindow()).getSize().y)
    {
        done();
    }

    m_velocity += m_acceleration * dt.asSeconds();
    m_overlay.move(m_velocity * dt.asSeconds());
}

void GameOver_HitObstacleOnLand::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            done();
        }
    }
}

void GameOver_HitObstacleOnLand::handleRealtimeInput()
{
}

void GameOver_HitObstacleOnLand::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_overlay, states);
}