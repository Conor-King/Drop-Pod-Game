#include "engine.h"
#include "drop_pod_game.h"
#include "scenes/scene_menu.h"
#include "components/cmp_player.h"
#include <SFML/Graphics.hpp>
using namespace sf;
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
	Engine::Start(1280, 720, "Drop Pod", &menu);
}
/* Todo:
* itch.io page
* resolution change / change the render to suit with the map.
* show controls?
* Victory Text/screen
* Save the settings preferences
* 
* 
*/
