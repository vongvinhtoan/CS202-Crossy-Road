#include <Views/LandView.hpp>
#include <Utils.hpp>

LandView::LandView()
	: mDirection(utils::random(0, 1) == 0 ? Direction::LEFT : Direction::RIGHT)
	, mSpeed(utils::random(0.0f, 1.0f))
{
}

LandView::LandView(Direction direction, float speed)
	: mDirection(direction)
	, mSpeed(speed)
{
}

LandView::~LandView()
{
}

void LandView::update(sf::Time dt)
{
}

void LandView::handleEvent(sf::Event& event)
{
}

void LandView::handleRealtimeInput()
{
}

void LandView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

bool LandView::contains(sf::Vector2f point) const
{
	return false;
}

void LandView::setDirection(Direction direction)
{
	mDirection = direction;
}

void LandView::setSpeed(float speed)
{
	mSpeed = speed;
}

LandView::Direction LandView::getDirection() const
{
	return mDirection;
}

float LandView::getSpeed() const
{
	return mSpeed;
}