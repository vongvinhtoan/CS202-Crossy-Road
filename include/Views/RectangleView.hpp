#pragma once

#include <ViewNode.hpp>

class RectangleView : public ViewNode
{
public:
	RectangleView();
	RectangleView(const sf::RectangleShape& rectangle);
	virtual ~RectangleView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;
	
public:
    virtual bool contains(sf::Vector2f point) const final override;
	sf::RectangleShape& get();

private:
	sf::RectangleShape m_rectangle;
};
