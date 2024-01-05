#include <Context.hpp>
#include <ConfigManager.hpp>

void updateConfigFile(std::string keyBinding, sf::Keyboard::Key key) {
    auto x = Context::getInstance().getConfigs();
    (*x)["keyBinding"][keyBinding] = static_cast<int>(key);
}

std::vector<char> getKeysFromConfigFile() {
    Json::Value configData = *Context::getInstance().getConfigs();

    std::vector<char> keys;
    keys.push_back(static_cast<char>(configData["keyBinding"]["moveUp"].asInt() + 65));
    keys.push_back(static_cast<char>(configData["keyBinding"]["moveLeft"].asInt() + 65));
    keys.push_back(static_cast<char>(configData["keyBinding"]["moveDown"].asInt() + 65));
    keys.push_back(static_cast<char>(configData["keyBinding"]["moveRight"].asInt() + 65));

    return keys;
}
