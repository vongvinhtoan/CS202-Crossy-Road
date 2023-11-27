#include <Views/VertexArrayView.hpp>
#include <Utils.hpp>

VertexArrayView::~VertexArrayView()
{
}

void VertexArrayView::update(sf::Time dt)
{
}

void VertexArrayView::handleEvent(sf::Event &event)
{
}

void VertexArrayView::handleRealtimeInput()
{
}

void VertexArrayView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_array, states);
}

bool VertexArrayView::contains(sf::Vector2f point) const
{
    bool result = false;
    for (int i = 1; i < m_array.getVertexCount() - 1; i++)
    {
        sf::Vector2f p1 = m_array[0].position;
        sf::Vector2f p2 = m_array[i].position;
        sf::Vector2f p3 = m_array[i + 1].position;
        if (utils::pointInTriangle(point, p1, p2, p3))
        {
            result = true;
            break;
        }
    }
    return result;
}

sf::VertexArray &VertexArrayView::get()
{
    return m_array;
}