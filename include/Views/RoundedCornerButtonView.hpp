#pragma once

#include <Views/RoundedCornerRectangleView.hpp>
#include <Utils.hpp>

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

		setHoverEffect();
	}
	virtual ~RoundedCornerButtonView() final;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	void setHoverEffect(sf::Color hoverColor = utils::hexToColor("D9D9D9"));

private:
	sf::RectangleShape 					m_tmpRectangle;
};
