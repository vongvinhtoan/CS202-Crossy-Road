#include <Views/PlayerView.hpp>
#include <iostream>

PlayerView::PlayerView()
{
	std::cout << "PlayerView::PlayerView()" << std::endl;
	auto tileSize = (*getContext()->getConfigs())["playground"]["tileSize"].asInt();
	mShape.setSize(sf::Vector2f(tileSize, tileSize));
	mShape.setFillColor(sf::Color::Red);
}

PlayerView::~PlayerView()
{
}

void PlayerView::update(sf::Time dt)
{
}

void PlayerView::handleEvent(sf::Event& event)
{
}

void PlayerView::handleRealtimeInput()
{
}

void PlayerView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mShape, states);
}

bool PlayerView::contains(sf::Vector2f point) const
{
	return false;
}

sf::RectangleShape& PlayerView::get()
{
	return mShape;
}