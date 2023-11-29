#include <Activities/MainActivity.hpp>
#include <Utils.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	// requestActivity(ActivityID::Loading);
	auto layer = getLayer(0);
	auto rect = std::make_unique<RectangleView>(sf::Vector2f(50, 50));
	rect->get().setOrigin(25, 25);
	this->rect = rect.get();
	layer->attachChild(std::move(rect));

	auto arrowLayer = getLayer(1);

	auto velocity_arrow = std::make_unique<ArrowView>(sf::Vector2f(0, 0));
	m_velocity_arrow = velocity_arrow.get();
	arrowLayer->attachChild(std::move(velocity_arrow));
	auto acceleration_arrow = std::make_unique<ArrowView>(sf::Vector2f(0, 0));
	m_acceleration_arrow = acceleration_arrow.get();
	arrowLayer->attachChild(std::move(acceleration_arrow));
	auto spring_force_arrow = std::make_unique<ArrowView>(sf::Vector2f(0, 0));
	m_spring_force_arrow = spring_force_arrow.get();
	arrowLayer->attachChild(std::move(spring_force_arrow));
	auto damping_force_arrow = std::make_unique<ArrowView>(sf::Vector2f(0, 0));
	m_damping_force_arrow = damping_force_arrow.get();
	arrowLayer->attachChild(std::move(damping_force_arrow));

	m_velocity_arrow->setColor(sf::Color::Green);
	m_acceleration_arrow->setColor(sf::Color::Red);
	m_spring_force_arrow->setColor(sf::Color::Blue);
	m_damping_force_arrow->setColor(sf::Color::Yellow);
}

MainActivity::~MainActivity()
{
}

bool MainActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool MainActivity::handleRealtimeInput()
{
	auto mouse_pos = sf::Mouse::getPosition(*getContext()->getWindow());
	dest = sf::Vector2f(mouse_pos.x, mouse_pos.y);
	return Activity::handleRealtimeInput();
}

bool MainActivity::update(sf::Time dt)
{
	const sf::Vector2f velocity = pos_cur - pos_old;
	const float distance = utils::distance(dest, pos_cur);
	const sf::Vector2f unitDir = utils::unitVector(dest - pos_cur);
	const sf::Vector2f acceleration = 1000.f * 1000.f * unitDir / distance / distance;
	m_velocity_arrow->setVector(velocity / dt.asSeconds());
	m_acceleration_arrow->setVector(acceleration);
	m_spring_force_arrow->setVector(unitDir * distance);
	std::cout << "velocity: " << velocity.x << ", " << velocity.y << std::endl;
	std::cout << "acceleration: " << acceleration.x << ", " << acceleration.y << std::endl;
	std::cout << "spring force: " << unitDir.x * distance << ", " << unitDir.y * distance << std::endl;

	pos_old = pos_cur;
	pos_cur += velocity + acceleration * dt.asSeconds() * dt.asSeconds();
	rect->setPosition(pos_cur);
	m_acceleration_arrow->setPosition(pos_cur);
	m_velocity_arrow->setPosition(pos_cur);
	m_spring_force_arrow->setPosition(pos_cur);
	m_damping_force_arrow->setPosition(pos_cur);
	return Activity::update(dt);
}

bool MainActivity::draw()
{
	return Activity::draw();
}
