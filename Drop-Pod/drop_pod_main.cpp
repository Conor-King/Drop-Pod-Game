#include "engine.h"
#include "drop_pod_game.h"
#include "scenes/scene_menu.h"

using namespace std;

MenuScene menu;
SettingsScene settings;
ProfileScene profile;
ShopScene shop;
CharSelectScene charSelect;
LevelSelectScene levelSelect;
PlanetLevelScene planetLevel;
SpaceshipLevelScene spaceshipLevel;

int main() {
  Engine::Start(1280, 720, "Drop Pod", &menu);

}