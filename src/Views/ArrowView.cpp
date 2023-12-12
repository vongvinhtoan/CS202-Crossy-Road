#include <Views/ArrowView.hpp>
#include <cmath>

ArrowView::ArrowView(const sf::Vector2f& vector)
	: m_vector(vector)
	, m_array(sf::TrianglesStrip, 7)
{
}

ArrowView::~ArrowView()
{
}

void ArrowView::update(sf::Time dt)
{
	sf::Vector2f dir = m_vector;
	sf::Vector2f dir_norm = dir / std::sqrt(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f dir_norm_perp = sf::Vector2f(-dir_norm.y, dir_norm.x);

	sf::Vector2f p1 = dir_norm_perp * m_thickness;
	sf::Vector2f p7 = - dir_norm_perp * m_thickness;
	sf::Vector2f p4 = m_vector;
	sf::Vector2f p2 = m_vector - dir_norm * m_hat_thickness + dir_norm_perp * m_thickness;
	sf::Vector2f p6 = m_vector - dir_norm * m_hat_thickness - dir_norm_perp * m_thickness;
	sf::Vector2f p5 = p2 + dir_norm_perp * m_thickness;
	sf::Vector2f p3 = p6 - dir_norm_perp * m_thickness;

	m_array[0].position = p1;
	m_array[1].position = p2;
	m_array[2].position = p3;
	m_array[3].position = p4;
	m_array[4].position = p5;
	m_array[5].position = p6;
	m_array[6].position = p7;

	for (int i = 0; i < 7; ++i)
		m_array[i].color = m_color;
}

void ArrowView::handleEvent(sf::Event& event)
{
}

void ArrowView::handleRealtimeInput()
{
}

void ArrowView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_array, states);
}

bool ArrowView::contains(sf::Vector2f point) const
{
	return false;
}

void ArrowView::setVector(const sf::Vector2f& vector)
{
	m_vector = vector;
}

void ArrowView::setColor(const sf::Color& color)
{
	m_color = color;
}