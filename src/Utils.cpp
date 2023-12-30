#include <Utils.hpp>

#include <sstream>
#include <iostream>
#include <cmath>

namespace utils
{
    sf::Color hexToColor(std::string hex)
    {
        if (hex[0] == '#')
            hex.erase(0, 1);
        if (hex.size() == 3)
        {
            std::string tmp = "";
            tmp += hex[0];
            tmp += hex[0];
            tmp += hex[1];
            tmp += hex[1];
            tmp += hex[2];
            tmp += hex[2];
            hex = tmp;
        }
        if (hex.size() == 6 || hex.size() == 8)
        {
            for (char &c : hex)
                if ('0' <= c && c <= '9')
                    c -= '0';
                else if ('a' <= c && c <= 'f')
                    c -= 'a' - 10;
                else if ('A' <= c && c <= 'F')
                    c -= 'A' - 10;
                else
                    c = 0;

            sf::Color color;
            color.r = hex[0] * 16 + hex[1];
            color.g = hex[2] * 16 + hex[3];
            color.b = hex[4] * 16 + hex[5];
            if (hex.size() == 8)
                color.a = hex[6] * 16 + hex[7];
            return color;
        }
        return sf::Color::Black;
    }

    float distance(sf::Vector2f a, sf::Vector2f b)
    {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

    float sqrDistance(sf::Vector2f a, sf::Vector2f b)
    {
        return std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2);
    }

    sf::Vector2f unitVector(sf::Vector2f vector)
    {
        float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
        if (length != 0)
            return sf::Vector2f(vector.x / length, vector.y / length);
        return vector;
    }

    sf::Vector2f dot(sf::Vector2f a, sf::Vector2f b)
    {
        return sf::Vector2f(a.x * b.x, a.y * b.y);
    }

    sf::Color lerp(sf::Color a, sf::Color b, float t)
    {
        return sf::Color(
            a.r + (b.r - a.r) * t,
            a.g + (b.g - a.g) * t,
            a.b + (b.b - a.b) * t,
            a.a + (b.a - a.a) * t
        );
    }
    
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    
    float random(float min, float max)
    {
        std::uniform_real_distribution<float> distribution(min, max);
        return distribution(generator);
    }

    double random(double min, double max)
    {
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(generator);
    }

    int random(int min, int max)
    {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }

    bool pointInTriangle(sf::Vector2f point, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
    {
        float denominator = ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
        float a = ((p2.y - p3.y) * (point.x - p3.x) + (p3.x - p2.x) * (point.y - p3.y)) / denominator;
        float b = ((p3.y - p1.y) * (point.x - p3.x) + (p1.x - p3.x) * (point.y - p3.y)) / denominator;
        float c = 1.0f - a - b;
        return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;
    }

    std::string keyToString(sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::A:
            return "A";
        case sf::Keyboard::B:
            return "B";
        case sf::Keyboard::C:
            return "C";
        case sf::Keyboard::D:
            return "D";
        case sf::Keyboard::E:
            return "E";
        case sf::Keyboard::F:
            return "F";
        case sf::Keyboard::G:
            return "G";
        case sf::Keyboard::H:
            return "H";
        case sf::Keyboard::I:
            return "I";
        case sf::Keyboard::J:
            return "J";
        case sf::Keyboard::K:
            return "K";
        case sf::Keyboard::L:
            return "L";
        case sf::Keyboard::M:
            return "M";
        case sf::Keyboard::N:
            return "N";
        case sf::Keyboard::O:
            return "O";
        case sf::Keyboard::P:
            return "P";
        case sf::Keyboard::Q:
            return "Q";
        case sf::Keyboard::R:
            return "R";
        case sf::Keyboard::S:
            return "S";
        case sf::Keyboard::T:
            return "T";
        case sf::Keyboard::U:
            return "U";
        case sf::Keyboard::V:
            return "V";
        case sf::Keyboard::W:
            return "W";
        case sf::Keyboard::X:
            return "X";
        case sf::Keyboard::Y:
            return "Y";
        case sf::Keyboard::Z:
            return "Z";
        default:
            return "?";
        }
    }
};

namespace utils
{
    namespace anim
    {
        float linear(float t)
        {
            return t;
        }

        float squared(float t)
        {
            return t * t;
        }

        float square_root(float t)
        {
            return std::sqrt(t);
        }

        float quadratic_ease_out(float t)
        {
            return 1.0 - (1.0 - t) * (1.0 - t);
        }

        float triangle(float t)
        {
            return 1.0 - 2.0 * std::abs(t - 0.5);
        }

        float elastic_out(float t)
        {
            static constexpr float HALF_PI = 3.14159265358979323846 / 2.0;
            return std::sin(-13.0 * (t + 1.0) * HALF_PI) * std::pow(2.0, -10.0 * t) + 1.0;
        }

        float bounce_out(float t)
        {
            const float nl = 7.5625;
            const float dl = 2.75;

            if (t < 1.0 / dl)
            {
                return nl * t * t;
            }
            else if (t < 2.0 / dl)
            {
                return nl * (t -= 1.5 / dl) * t + 0.75;
            }
            else if (t < 2.5 / dl)
            {
                return nl * (t -= 2.25 / dl) * t + 0.9375;
            }
            else
            {
                return nl * (t -= 2.625 / dl) * t + 0.984375;
            }
        }
    };
};