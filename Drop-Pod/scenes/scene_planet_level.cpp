#include "scene_planet_level.h"
#include "../drop_pod_game.h"
#include <LevelSystem.h>
#include <iostream>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

View view;
float speed;

void PlanetLevelScene::Load() {

    ls::loadLevelFile("res/levels/maze.txt");

    // print the level to the console
    for (size_t y = 0; y < ls::getHeight(); y++) {
        for (size_t x = 0; x < ls::getWidth(); x++) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }

    // Setting the top left corner position and the size of the view.
    view.reset(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
    Engine::setView(view);

    // Setting the speed of the view.
    speed = 200.f;

    setLoaded(true);
}

void PlanetLevelScene::UnLoad() { }

void PlanetLevelScene::Update(const double& dt) {

    

    // Moving the window to test the stitching.
    float directY = 0.f;
    float directX = 0.f;

    if (Keyboard::isKeyPressed(Keyboard::A)) {
        directX--;
        //printf("Move left. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        directX++;
        //printf("Move right. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        directY--;
        //printf("Move up. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        directY++;
        //printf("Move down. \n");
    }
    Engine::moveView(Vector2f(directX * speed * dt, directY * speed * dt));

    ls::render(Engine::GetWindow()); // I don't think this should render every update.

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