#pragma once

#include <ViewNode.hpp>

class ArrowView : public ViewNode
{
public:
	ArrowView(const sf::Vector2f& vector = sf::Vector2f(0, 0));
	virtual ~ArrowView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;
	void setVector(const sf::Vector2f& vector);
	void setColor(const sf::Color& color);

public:
	// Getters

private:
	sf::Vector2f m_vector;
    sf::VertexArray m_array;
	sf::Color m_color = sf::Color::White;
	float m_hat_thickness = 20.f;
	float m_thickness = 10.f;
};
