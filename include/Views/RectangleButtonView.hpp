#pragma once

#include <Views/RectangleView.hpp>
#include <Utils.hpp>

class RectangleButtonView : public RectangleView
{
public:
	RectangleButtonView();
	template <typename ...Args>
	RectangleButtonView(Args&& ...args)
		: RectangleView(std::forward<Args>(args)...),
		  m_tmpRectangle(std::forward<Args>(args)...)
	{
		m_tmpRectangle.setOutlineColor(sf::Color::Transparent);
		m_tmpRectangle.setOutlineThickness(0);

		setHoverEffect();
	}
	virtual ~RectangleButtonView() final;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	void setHoverEffect(sf::Color hoverColor = utils::hexToColor("D9D9D9"));

private:
	sf::RectangleShape 		m_tmpRectangle;
};
