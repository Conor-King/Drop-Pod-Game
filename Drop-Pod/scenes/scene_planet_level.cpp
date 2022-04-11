#include "scene_planet_level.h"
#include "../drop_pod_game.h"
#include <LevelSystem.h>
#include <iostream>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

View view;
float speed;
int xCount;
int yCount;
Vector2f startingCenter;


void PlanetLevelScene::Load() {

    ls::loadLevelFile("res/levels/floorMap.txt");

    // print the level to the console
    for (size_t y = 0; y < ls::getHeight(); y++) {
        for (size_t x = 0; x < ls::getWidth(); x++) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }

    xCount = ls::getWidth();
    yCount = ls::getHeight();

    // Setting the top left corner position and the size of the view.
    view.reset(sf::FloatRect(xCount * 100 * 0.5, yCount * 100 * 0.5, 1280.f, 720.f));
    Engine::setView(view);

    startingCenter = view.getCenter();

    // Setting the speed of the view.
    speed = 200.f;

    setLoaded(true);
}

void PlanetLevelScene::UnLoad() { }

void PlanetLevelScene::Update(const double& dt) {

    // This does not work as center does not change.
    //if (Engine::GetWindow().getView().getCenter().x > startingCenter.x + 100 || Engine::GetWindow().getView().getCenter().x < startingCenter.x - 100 ||
    //    Engine::GetWindow().getView().getCenter().y > startingCenter.y + 100 || Engine::GetWindow().getView().getCenter().y < startingCenter.y - 100)
    //{
    //    view.reset(sf::FloatRect(xCount * 100 * 0.5, yCount * 100 * 0.5, 1280.f, 720.f));
    //
    //}

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
    if (Keyboard::isKeyPressed(Keyboard::LShift)) {
        speed = 400.f;
    }
    else {
        speed = 200.f;
    }
    Engine::moveView(Vector2f(directX * speed * dt, directY * speed * dt));

    Scene::Update(dt);
}

void PlanetLevelScene::Render() { 
    ls::renderFloor(Engine::GetWindow());
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