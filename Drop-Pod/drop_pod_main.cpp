#include "engine.h"
#include "drop_pod_game.h"
#include "scenes/scene_menu.h"
#include "components/cmp_player.h"

using namespace std;

MenuScene menu;
SettingsScene settings;
ProfileScene profile;
ShopScene shop;
CharSelectScene charSelect;
LevelSelectScene levelSelect;
PlanetLevelScene planetLevel;
SpaceshipLevelScene spaceshipLevel;
short unsigned switchState;

int main() {
	switchState = WSAD;
  Engine::Start(1280, 720, "Drop Pod", &menu);
}

