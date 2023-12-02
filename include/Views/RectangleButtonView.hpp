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
		  m_tmpRectangle(getRectangle()),
		  m_isOnHover(false)
	{
	}
	virtual ~RectangleButtonView() final;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const override;

private:
	void setOnLostHover(std::function<void(ViewNode&)> onLostHover);

public:
	void setHoverEffect(sf::Color hoverColor = utils::hexToColor("D9D9D9"));

private:
	sf::RectangleShape 					m_tmpRectangle;
	bool 								m_isOnHover;
};
