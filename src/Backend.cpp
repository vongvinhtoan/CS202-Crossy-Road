#include <Backend.hpp>
#include <fstream>
#include <iostream>

Backend::Backend() {}

Backend::~Backend() {}

Backend& Backend::getInstance() {
    static Backend instance;
    return instance;
}

void Backend::loadTextures(TextureHolder& textures) {
    textures.load(TextureID::LoadingScreen, "res/textures/LoadingScreen.png");
    textures.load(TextureID::Background, "res/textures/Background.png");
    textures.load(TextureID::CharacterPenguin, "res/textures/Characters/Penguin.png");
    textures.load(TextureID::CharacterChicken, "res/textures/Characters/Chicken.png");
    textures.load(TextureID::CharacterMonkey, "res/textures/Characters/Monkey.png");
    textures.load(TextureID::LeftArrow, "res/textures/LeftArrow.png");
    textures.load(TextureID::RightArrow, "res/textures/RightArrow.png");
    textures.load(TextureID::BackGroundScreen, "res/textures/BackgroundScreen.png");
    textures.load(TextureID::HomeButton, "res/textures/HomeButton.png");
    textures.load(TextureID::Home, "res/textures/Home.png");
    textures.load(TextureID::SelectCharacter, "res/textures/SelectCharacter.png");
}

void Backend::loadFonts(FontHolder& fonts) {
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
    fonts.load(FontID::Tourney, "res/fonts/Tourney_SemiCondensed-Light.ttf");
    fonts.load(FontID::Tourney_Bold, "res/fonts/Tourney_SemiCondensed-Bold.ttf");
    fonts.load(FontID::Inter_Bold, "res/fonts/Inter-Bold.ttf");
}

void Backend::loadConfigs(Json::Value& configs) {
    std::ifstream file("res/configs/configs.json");
    file >> configs;
    file.close();
}

void Backend::saveConfig(Json::Value& configs) {
    std::ofstream file("res/configs/configs.json");
    file << configs;
    file.close();
}