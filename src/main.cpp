#include <iostream>
#include <Application.hpp>

int main() 
{
    try
    {
        Application &application = Application::getInstance();
        application.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}
// #include <SFML/Graphics.hpp>

// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Rounded Rectangle in SFML");

//     // Define the properties of the rounded rectangle
//     float width = 200.0f;
//     float height = 100.0f;
//     float cornerRadius = 20.0f;

//     sf::RectangleShape roundedRect(sf::Vector2f(width, height));
//     roundedRect.setOutlineThickness(2);
//     roundedRect.setOutlineColor(sf::Color::Black);

//     // Define circles for the corners
//     sf::CircleShape topLeftCorner(cornerRadius);
//     sf::CircleShape topRightCorner(cornerRadius);
//     sf::CircleShape bottomLeftCorner(cornerRadius);
//     sf::CircleShape bottomRightCorner(cornerRadius);

//     // Set positions for the corners
//     topLeftCorner.setPosition(0, 0);
//     topRightCorner.setPosition(width - cornerRadius * 2, 0);
//     bottomLeftCorner.setPosition(0, height - cornerRadius * 2);
//     bottomRightCorner.setPosition(width - cornerRadius * 2, height - cornerRadius * 2);

//     // Set the fill color for the corners
//     topLeftCorner.setFillColor(sf::Color::Black);
//     topRightCorner.setFillColor(sf::Color::Black);
//     bottomLeftCorner.setFillColor(sf::Color::Black);
//     bottomRightCorner.setFillColor(sf::Color::Black);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear(sf::Color::White);

//         // Draw rectangles for the sides
//         sf::RectangleShape leftSide(sf::Vector2f(cornerRadius, height - cornerRadius * 2));
//         leftSide.setPosition(0, cornerRadius);
//         leftSide.setFillColor(sf::Color::Black);
//         window.draw(leftSide);

//         sf::RectangleShape rightSide(sf::Vector2f(cornerRadius, height - cornerRadius * 2));
//         rightSide.setPosition(width - cornerRadius, cornerRadius);
//         rightSide.setFillColor(sf::Color::Black);
//         window.draw(rightSide);

//         sf::RectangleShape topSide(sf::Vector2f(width - cornerRadius * 2, cornerRadius));
//         topSide.setPosition(cornerRadius, 0);
//         topSide.setFillColor(sf::Color::Black);
//         window.draw(topSide);

//         sf::RectangleShape bottomSide(sf::Vector2f(width - cornerRadius * 2, cornerRadius));
//         bottomSide.setPosition(cornerRadius, height - cornerRadius);
//         bottomSide.setFillColor(sf::Color::Black);
//         window.draw(bottomSide);

//         // Draw circles for the corners
//         window.draw(topLeftCorner);
//         window.draw(topRightCorner);
//         window.draw(bottomLeftCorner);
//         window.draw(bottomRightCorner);

//         window.display();
//     }

//     return 0;
// }