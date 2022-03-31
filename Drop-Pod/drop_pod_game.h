#pragma once

#include "scenes/scene_menu.h"
#include "scenes/scene_settings.h"
#include "scenes/scene_profile.h"
#include "scenes/scene_shop.h"
#include "scenes/scene_char_select.h"
#include "scenes/scene_level_select.h"
#include "scenes/scene_planet_level.h"
#include "scenes/scene_spaceship_level.h"
#include <SFML/Graphics.hpp>
#include "player.h"

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;




extern MenuScene menu;
extern SettingsScene settings;
extern ProfileScene profile;
extern ShopScene shop;
extern CharSelectScene charSelect;
extern LevelSelectScene levelSelect;
extern PlanetLevelScene planetLevel;
extern SpaceshipLevelScene spaceshipLevel;

