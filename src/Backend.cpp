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
    textures.load(TextureID::PlayAgainArrow, "res/textures/PlayAgainArrow.png");
    textures.load(TextureID::BackGroundScreen, "res/textures/BackgroundScreen.png");
    textures.load(TextureID::HomeButton, "res/textures/HomeButton.png");
    textures.load(TextureID::Home, "res/textures/Home.png");
    textures.load(TextureID::Setting, "res/textures/Setting.png");
    textures.load(TextureID::Instruction, "res/textures/Instruction.png");
    textures.load(TextureID::SelectCharacter, "res/textures/SelectCharacter.png");
    textures.load(TextureID::LaneLand_tile_0, "res/textures/Lanes/Land/LaneLand_tile_0.png");
    textures.load(TextureID::LaneLand_tile_1, "res/textures/Lanes/Land/LaneLand_tile_1.png");
    textures.load(TextureID::LaneLand_tile_2, "res/textures/Lanes/Land/LaneLand_tile_2.png");
    textures.load(TextureID::LaneLand_obstacle_0, "res/textures/Lanes/Land/LaneLand_obstacle_0.png");
    textures.load(TextureID::LaneLand_obstacle_1, "res/textures/Lanes/Land/LaneLand_obstacle_1.png");
}

void Backend::loadFonts(FontHolder& fonts) {
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
    fonts.load(FontID::Tourney, "res/fonts/Tourney_SemiCondensed-Light.ttf");
    fonts.load(FontID::Tourney_Bold, "res/fonts/Tourney_SemiCondensed-Bold.ttf");
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