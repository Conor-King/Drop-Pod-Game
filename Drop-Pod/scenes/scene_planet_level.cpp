#include "scene_planet_level.h"
#include "../drop_pod_game.h"
#include <LevelSystem.h>
#include <iostream>
using namespace std;
using namespace sf;


void PlanetLevelScene::Load() {

    ls::loadLevelFile("res/levels/maze.txt");
    

    // print the level to the console
    for (size_t y = 0; y < ls::getHeight(); y++) {
        for (size_t x = 0; x < ls::getWidth(); x++) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }
}

void PlanetLevelScene::UnLoad() { }

void PlanetLevelScene::Update(const double& dt) {

    Scene::Update(dt);
}

void PlanetLevelScene::Render() { 
    ls::render(Engine::GetWindow());
}
