#include "engine.h"
#include "drop_pod_game.h"
#include "scenes/scene_menu.h"

using namespace std;

MenuScene menu;
Level1Scene level1;
Level2Scene level2;
Level3Scene level3;

int main() {
  Engine::Start(1280, 720, "Drop Pod",&menu);
}