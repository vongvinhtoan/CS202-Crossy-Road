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
	states.transform *= getTransform();
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

sf::RectangleShape PlayerView::getTransformed() const
{
	auto rect = mShape;
	rect.setPosition(getPosition());
	return rect;
}

void PlayerView::bind(Player* player, PlaygroundCamera* camera)
{
	auto rect = player->getBounds();
	rect.top -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
	mShape.setSize(sf::Vector2f(rect.width, rect.height));
	rect.top = (*getContext()->getWindow()).getSize().y - rect.top;
	setPosition(rect.left, rect.top);

	if(player->isInvincible())
	{
		mShape.setFillColor(sf::Color(0, 0, 0, 0));
	}
}