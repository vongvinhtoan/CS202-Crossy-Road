#pragma once

#include <ViewNode.hpp>
#include <Player.hpp>
#include <PlaygroundCamera.hpp>

class PlayerView : public ViewNode
{
public:
	PlayerView();
	virtual ~PlayerView() final;

public:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;

public:
	void bind(Player* player, PlaygroundCamera* camera);

public:
	sf::RectangleShape& get();

private:
	sf::RectangleShape mShape;
};
