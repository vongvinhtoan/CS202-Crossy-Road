#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

namespace utils
{
    namespace anim
    {
        float linear(float t);
        float squared(float t);
        float square_root(float t);
        float quadratic_ease_out(float t);

        template <int k>
        float parabola(float t)
        {
            return std::pow(4.0 * t * (1.0 - t), k);
        }

        float triangle(float t);
        float elastic_out(float t);
        float bounce_out(float t);
    };

    template <typename T, typename F>
    T lerp(T a, T b, float t, F &&func)
    {
        return a + func(t) * (b - a);
    }

    template <typename T>
    T lerp(T a, T b, float t)
    {
        return lerp(a, b, t, [](float t)
                    { return t; });
    }

    sf::Color hexToColor(std::string hex);
    bool pointInTriangle(sf::Vector2f point, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);
    float distance(sf::Vector2f a, sf::Vector2f b);
    float sqrDistance(sf::Vector2f a, sf::Vector2f b);
    sf::Vector2f unitVector(sf::Vector2f vector);
    sf::Vector2f dot(sf::Vector2f a, sf::Vector2f b);
    sf::Color lerp(sf::Color a, sf::Color b, float t);
};