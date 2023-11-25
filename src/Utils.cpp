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
        if (hex.size() == 6)
        {
            for(char&c : hex)
                if('0' <= c && c <= '9')
                    c -= '0';
                else if('a' <= c && c <= 'f')
                    c -= 'a' - 10;
                else if('A' <= c && c <= 'F')
                    c -= 'A' - 10;
                else
                    c = 0;

            sf::Color color;;
            color.r = hex[0] * 16 + hex[1];
            color.g = hex[2] * 16 + hex[3];
            color.b = hex[4] * 16 + hex[5];
            return color;
        }
        return sf::Color::Black;
    }
};

namespace utils {
    namespace anim {
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

            if (t < 1.0 / dl) {
                return nl * t * t;
            } else if (t < 2.0 / dl) {
                return nl * (t -= 1.5 / dl) * t + 0.75;
            } else if (t < 2.5 / dl) {
                return nl * (t -= 2.25 / dl) * t + 0.9375;
            } else {
                return nl * (t -= 2.625 / dl) * t + 0.984375;
            }
        }
    };
};