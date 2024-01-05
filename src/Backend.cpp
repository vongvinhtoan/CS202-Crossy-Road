#include <Backend.hpp>
#include <fstream>
#include <iostream>

Backend::Backend() {}

Backend::~Backend() {}

Backend &Backend::getInstance()
{
    static Backend instance;
    return instance;
}

void Backend::loadTextures(TextureHolder &textures)
{
    textures.load(TextureID::LoadingScreen, "res/textures/LoadingScreen.png");
    textures.load(TextureID::CharacterPenguin, "res/textures/Characters/Penguin.png");
    textures.load(TextureID::CharacterChicken, "res/textures/Characters/Chicken.png");
    textures.load(TextureID::CharacterMonkey, "res/textures/Characters/Monkey.png");
    textures.load(TextureID::LeftArrow, "res/textures/LeftArrow.png");
    textures.load(TextureID::RightArrow, "res/textures/RightArrow.png");
    textures.load(TextureID::PlayAgainArrow, "res/textures/PlayAgainArrow.png");
    textures.load(TextureID::BackGroundScreen, "res/textures/BackgroundScreen.png");
    textures.load(TextureID::HomeButton, "res/textures/HomeButton.png");
    textures.load(TextureID::KeyBinding, "res/textures/KeyBinding.png");
    textures.load(TextureID::Home, "res/textures/Home.png");
    textures.load(TextureID::HighScore, "res/textures/HighScore.png");
    textures.load(TextureID::KeyboardButton, "res/textures/KeyboardButton.png");
    textures.load(TextureID::Setting, "res/textures/Setting.png");
    textures.load(TextureID::Instruction, "res/textures/Instruction.png");
    textures.load(TextureID::InstructionText, "res/textures/InstructionText.png");
    textures.load(TextureID::SelectCharacter, "res/textures/SelectCharacter.png");
    textures.load(TextureID::ShortcutPicture, "res/textures/ShortcutPicture.png");
    textures.load(TextureID::CloseButton, "res/textures/CloseButton.png");
    textures.load(TextureID::CloseButtonHover, "res/textures/CloseButtonHover.png");
    textures.load(TextureID::LaneLand_tile_0, "res/textures/Lanes/Land/LaneLand_tile_0.png");
    textures.load(TextureID::LaneLand_tile_1, "res/textures/Lanes/Land/LaneLand_tile_1.png");
    textures.load(TextureID::LaneLand_tile_2, "res/textures/Lanes/Land/LaneLand_tile_2.png");
    textures.load(TextureID::LaneLand_obstacle_0, "res/textures/Lanes/Land/LaneLand_obstacle_0.png");
    textures.load(TextureID::LaneLand_obstacle_1, "res/textures/Lanes/Land/LaneLand_obstacle_1.png");
    textures.load(TextureID::LaneStillWater_leaf, "res/textures/Lanes/StillWater/LaneStillWater_leaf.png");
    textures.load(TextureID::LaneTrain_railway_section, "res/textures/Lanes/Train/LaneTrain_railway_section.png");
    textures.load(TextureID::LaneTrain_train_1, "res/textures/Lanes/Train/LaneTrain_train_1.png");
    textures.load(TextureID::LaneTrain_train_2, "res/textures/Lanes/Train/LaneTrain_train_2.png");
    textures.load(TextureID::LaneTrain_train_3, "res/textures/Lanes/Train/LaneTrain_train_3.png");
    textures.load(TextureID::LaneTrain_train_4, "res/textures/Lanes/Train/LaneTrain_train_4.png");
    textures.load(TextureID::LaneTrain_train_5, "res/textures/Lanes/Train/LaneTrain_train_5.png");
    textures.load(TextureID::LaneTrain_train_6, "res/textures/Lanes/Train/LaneTrain_train_6.png");
    textures.load(TextureID::LaneTrain_train_7, "res/textures/Lanes/Train/LaneTrain_train_7.png");
    textures.load(TextureID::LaneTrain_train_8, "res/textures/Lanes/Train/LaneTrain_train_8.png");
    textures.load(TextureID::LaneTrain_train_coal, "res/textures/Lanes/Train/LaneTrain_train_coal.png");
    textures.load(TextureID::LaneTrain_train_log, "res/textures/Lanes/Train/LaneTrain_train_log.png");
    textures.load(TextureID::LaneTrain_train_empty, "res/textures/Lanes/Train/LaneTrain_train_empty.png");
    textures.load(TextureID::LaneCar_background_1, "res/textures/Lanes/Car/LaneCar_background_1.png");
    textures.load(TextureID::LaneCar_background_2, "res/textures/Lanes/Car/LaneCar_background_2.png");
    textures.load(TextureID::LaneCar_walking_car_1, "res/textures/Lanes/Car/LaneCar_walking_car_1.png");
    textures.load(TextureID::LaneCar_walking_car_2, "res/textures/Lanes/Car/LaneCar_walking_car_2.png");
    textures.load(TextureID::LaneCar_walking_car_3, "res/textures/Lanes/Car/LaneCar_walking_car_3.png");
    textures.load(TextureID::LaneCar_walking_car_4, "res/textures/Lanes/Car/LaneCar_walking_car_4.png");
    textures.load(TextureID::LaneCar_normal_car_1, "res/textures/Lanes/Car/LaneCar_normal_car_1.png");
    textures.load(TextureID::LaneCar_normal_car_2, "res/textures/Lanes/Car/LaneCar_normal_car_2.png");
    textures.load(TextureID::LaneCar_running_cat_1, "res/textures/Lanes/Car/LaneCar_running_cat_1.png");
    textures.load(TextureID::LaneCar_running_cat_2, "res/textures/Lanes/Car/LaneCar_running_cat_2.png");
    textures.load(TextureID::LaneCar_running_cat_3, "res/textures/Lanes/Car/LaneCar_running_cat_3.png");
    textures.load(TextureID::LaneCar_running_cat_4, "res/textures/Lanes/Car/LaneCar_running_cat_4.png");
    textures.load(TextureID::LaneCar_running_cat_5, "res/textures/Lanes/Car/LaneCar_running_cat_5.png");
    textures.load(TextureID::LaneCar_running_cat_6, "res/textures/Lanes/Car/LaneCar_running_cat_6.png");
    textures.load(TextureID::LaneCar_running_cat_7, "res/textures/Lanes/Car/LaneCar_running_cat_7.png");
    textures.load(TextureID::LaneCar_vroom_car_1, "res/textures/Lanes/Car/LaneCar_vroom_car_1.png");
    textures.load(TextureID::LaneCar_vroom_car_2, "res/textures/Lanes/Car/LaneCar_vroom_car_2.png");
    textures.load(TextureID::LaneCar_vroom_car_3, "res/textures/Lanes/Car/LaneCar_vroom_car_3.png");
    textures.load(TextureID::LaneMovingWater_log_head, "res/textures/Lanes/MovingWater/LaneMovingWater_log_head.png");
    textures.load(TextureID::LaneMovingWater_log_body, "res/textures/Lanes/MovingWater/LaneMovingWater_log_body.png");
    textures.load(TextureID::LaneMovingWater_log_tail, "res/textures/Lanes/MovingWater/LaneMovingWater_log_tail.png");
}

void Backend::loadFonts(FontHolder &fonts)
{
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
    fonts.load(FontID::Tourney, "res/fonts/Tourney_SemiCondensed-Light.ttf");
    fonts.load(FontID::Tourney_Bold, "res/fonts/Tourney_SemiCondensed-Bold.ttf");
    fonts.load(FontID::Inter_Bold, "res/fonts/Inter-Bold.ttf");
}

void Backend::loadConfigs(Json::Value &configs)
{
    std::ifstream file("res/configs/configs.json");
    file >> configs;
    file.close();
}

void Backend::saveConfig(Json::Value &configs)
{
    std::ofstream file("res/configs/configs.json");
    file << configs;
    file.close();
}