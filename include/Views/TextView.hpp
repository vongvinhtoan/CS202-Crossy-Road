#pragma once

#include <ViewNode.hpp>

class TextView : public ViewNode
{
public:
	TextView();

	template <typename... Args>
	TextView(Args &&...args)
		: m_text(std::forward<Args>(args)...)
	{
	}
	virtual ~TextView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event &event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;

public:
	sf::Text &get();
	sf::Vector2f getSize() const;

private:
	sf::Text m_text;
};
