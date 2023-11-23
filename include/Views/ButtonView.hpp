#pragma once

#include <ViewNode.hpp>

class ButtonView : public ViewNode 
{
   public:
	ButtonView();
	template <typename ...Args>
	ButtonView(Args&& ...args)
		: m_rectangle(std::forward<Args>(args)...)
	{
	}
    virtual ~ButtonView() final;

   private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)
        const final override;

   public:
    virtual bool contains(sf::Vector2f point) const final override;

   public:
    sf::RectangleShape& get();

   private:
    sf::RectangleShape m_rectangle;
};
