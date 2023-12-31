#pragma once

#include <Views/RoundedCornerRectangleView.hpp>
#include <Utils.hpp>
#include <iostream>

class RoundedCornerButtonView : public RoundedCornerRectangleView
{
public:
	RoundedCornerButtonView();
	template <typename ...Args>
	RoundedCornerButtonView(Args&& ...args)
		: RoundedCornerRectangleView(std::forward<Args>(args)...),
		  m_tmpRectangle(std::forward<Args>(args)...)
	{
		m_tmpRectangle.setOutlineColor(sf::Color::Transparent);
		m_tmpRectangle.setOutlineThickness(0);
		m_tmpRectangle.setPosition(RoundedCornerButtonView::getPosition());

		setHoverEffect();
	}
	virtual ~RoundedCornerButtonView() final;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	void setHoverEffect(sf::Color hoverColor = utils::hexToColor("D9D9D9"));
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;

private:
	sf::RectangleShape 		m_tmpRectangle;
};
