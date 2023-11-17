#pragma once

#include <ViewNode.hpp>

class TextView : public ViewNode
{
public:
	TextView();
	TextView(const sf::Text& text);
	virtual ~TextView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
    virtual bool contains(sf::Vector2f point) const final override;

public:
	sf::Text& text();

private:
	sf::Text m_text;
};
