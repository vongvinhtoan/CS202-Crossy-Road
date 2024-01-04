#pragma once

#include <ViewNode.hpp>

class RoundedCornerRectangleShape : public sf::RectangleShape
{
public:
	template <typename ...Args>
	RoundedCornerRectangleShape(Args&& ...args)
		: m_rectangle(std::forward<Args>(args)...)
	{
		m_topLeftCorner.setRadius(corner_radius);
		m_topRightCorner.setRadius(corner_radius);
		m_bottomLeftCorner.setRadius(corner_radius);
		m_bottomRightCorner.setRadius(corner_radius);

		m_topLeftCorner.setOrigin(corner_radius, corner_radius);
		m_topRightCorner.setOrigin(corner_radius, corner_radius);
		m_bottomLeftCorner.setOrigin(corner_radius, corner_radius);
		m_bottomRightCorner.setOrigin(corner_radius, corner_radius);

		m_topLeftCorner.setPosition(m_rectangle.getPosition());
		m_topRightCorner.setPosition(m_rectangle.getPosition().x+m_rectangle.getSize().x, m_rectangle.getPosition().y);
		m_bottomLeftCorner.setPosition(m_rectangle.getPosition().x, m_rectangle.getPosition().y+m_rectangle.getSize().y);
		m_bottomRightCorner.setPosition(m_rectangle.getPosition().x+m_rectangle.getSize().x, m_rectangle.getPosition().y+m_rectangle.getSize().y);

		m_topLeftCorner.setFillColor(sf::Color::White);
		m_topRightCorner.setFillColor(sf::Color::White);
		m_bottomLeftCorner.setFillColor(sf::Color::White);
		m_bottomRightCorner.setFillColor(sf::Color::White);

		m_rectangle.setSize(m_rectangle.getSize() - sf::Vector2f(corner_radius, corner_radius));
		m_topEdge.setSize(sf::Vector2f(m_rectangle.getSize().x, corner_radius));
		m_bottomEdge.setSize(sf::Vector2f(m_rectangle.getSize().x, corner_radius));
		m_leftEdge.setSize(sf::Vector2f(corner_radius, m_rectangle.getSize().y));
		m_rightEdge.setSize(sf::Vector2f(corner_radius, m_rectangle.getSize().y));

		m_topEdge.setPosition(m_rectangle.getPosition().x, m_rectangle.getPosition().y-m_topEdge.getSize().y);
		m_bottomEdge.setPosition(m_rectangle.getPosition().x, m_rectangle.getPosition().y+m_rectangle.getSize().y);
		m_leftEdge.setPosition(m_rectangle.getPosition().x - m_leftEdge.getSize().x, m_rectangle.getPosition().y);
		m_rightEdge.setPosition(m_rectangle.getPosition().x + m_rectangle.getSize().x, m_rectangle.getPosition().y);
	}
public:
	static constexpr float corner_radius = 20.0f;
	sf::RectangleShape m_rectangle;
	sf::CircleShape m_topLeftCorner, m_topRightCorner, m_bottomLeftCorner, m_bottomRightCorner;
	sf::RectangleShape m_topEdge, m_bottomEdge, m_leftEdge, m_rightEdge;

	void setFillColor(const sf::Color& color);
	void setTexture(const sf::Texture* texture);
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
};

class RoundedCornerRectangleView : public ViewNode
{
public:
	RoundedCornerRectangleView();
	template <typename ...Args>
	RoundedCornerRectangleView(Args&& ...args): m_rounded_rectangle(std::forward<Args>(args)...)
	{
	}
	virtual ~RoundedCornerRectangleView();

protected:
	virtual void update(sf::Time dt) override;
	virtual void handleEvent(sf::Event& event) override;
	virtual void handleRealtimeInput() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	virtual bool contains(sf::Vector2f point) const override;

public:
	RoundedCornerRectangleShape& get();
	RoundedCornerRectangleShape getRectangle() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;

	void setPosition(sf::Vector2f position);

protected:
	RoundedCornerRectangleShape m_rounded_rectangle;
};
