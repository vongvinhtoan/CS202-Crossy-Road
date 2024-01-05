#pragma once
#include <SFML/Graphics.hpp>

void updateConfigFile(std::string keyBinding, sf::Keyboard::Key key);
std::vector<char> getKeysFromConfigFile();
