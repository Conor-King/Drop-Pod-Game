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



// Possible algorithm for Rendering the on screen tiles only.

//define tileResolutionX as the number of tiles per row
//define tileResolutionY as the number of tiles per column
//define screenResolutionX as the width of the window you are rendering to
//define screenResolutionY as the height of the window you are rendering to
//
//xOffset = player.x - floor(tileResolutionX / 2)->This will center the map around your player's x-position
//yOffset = player.y - floor(tileResolutionY / 2)->This will center the map around your player's y-position
//for x = 0 to tileResolutionX - 1
//for y = 0 to tileResolutionY - 1
//render tile(x + xOffset, y + yOffset) at(x * (screenResolutionX / tileResolutionX), y * (screenResolutionY /
//    tileResolutionY))->This keeps all sprite sizes relative to one another and renders them relative to the player
//    end for
//    end for