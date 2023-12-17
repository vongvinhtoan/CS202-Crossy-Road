#pragma once

#include <ViewNode.hpp>
#include <Player.hpp>

class PlayerView : public ViewNode
{
public:
	PlayerView();
	virtual ~PlayerView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;

public:
	void bind(Player* player);

public:
	sf::RectangleShape& get();

	sf::Vector2f getPosition() const;

private:
	sf::RectangleShape mShape;

private:
	sf::Vector2f mPosition;
};
