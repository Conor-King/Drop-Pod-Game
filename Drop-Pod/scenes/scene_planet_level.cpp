#include "scene_planet_level.h"
#include "engine.h"
#include "../drop_pod_game.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_player.h"
#include "../components/cmp_shooting.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_text.h"
#include "system_renderer.h"
#include <LevelSystem.h>
#include <system_resources.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdio.h>

/* Todo:
* Return to menu
* Victory text
* Animations?
*/

using namespace std;
using namespace sf;

EntityManager ecm;

// Views
View gameView;
View hudView;

// Level global variables
float speed;
int xCount;
int yCount;
Vector2f startingCenter;
bool viewToggle = false;

// Player Variables
shared_ptr<Entity> player;
auto temp = Texture::Texture();
auto spritetemp = make_shared<Texture>(temp);
//shared_ptr<sf::Texture> spritesheet;

// Debug Hud variables
Text viewText;
Text mousePosText;
Text playerPosText;
Text centerPosText;

// Actual Hud
float tempTime;
int minutes;
int seconds;
Text timer;

// Shooting Delay
float fireTime = 0.f;

void PlanetLevelScene::Load() {

    ecm = Scene::getEcm();

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

    // Setting the center position and the size of the view.
    gameView.reset(sf::FloatRect(xCount * 100 * 0.5, yCount * 100 * 0.5, Engine::GetWindow().getSize().x, Engine::GetWindow().getSize().y ));
    Engine::setView(gameView);

    startingCenter = gameView.getCenter();

    // Setting the speed of the view.
    speed = 200.f;

    IntRect spriteArea = { Vector2i(0, 0), Vector2i(150, 150) };

    if (!spritetemp->loadFromFile("res/assets/man/Idle.png", spriteArea)) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }

    // Player Entity ---------------------------------------------------------------
    player = makeEntity();
    //player->setPosition(Vector2f(view.getSize().x * 0.5, view.getSize().y * 0.5));
    player->setPosition(startingCenter);

    auto psprite = player->addComponent<SpriteComponent>();
    psprite->setTexure(spritetemp);
    psprite->getSprite().setScale(2, 2);

    auto panimation = player->addComponent<AnimationComponent>(player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite());
  /*  for (auto i = 0; i < 7; i++)
    {
        Frame tempFrame;
        tempFrame.rect = IntRect(Vector2i(150 * i, 0), Vector2i(150, 150));
        tempFrame.duration = 0.1;
        panimation->addFrame(tempFrame);
    }*/

    auto pmove = player->addComponent<ActorMovementComponent>();
    pmove->setSpeed(600.f);

	auto pmovement = player->addComponent<PlayerComponent>();

    auto pshooting = player->addComponent<ShootingComponent>();

    // Enemies entity -----------------------------------------------------------------



    // HUD ----------------------------------------------------------------------------
    tempTime = 0.f;
    seconds = 0;
    timer.setString("Timer: 00:00");
    timer.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    timer.setCharacterSize(20);
    timer.setOrigin(timer.getGlobalBounds().width * 0.5, timer.getGlobalBounds().height * 0.5);
    timer.setPosition(gameView.getSize().x * 0.5 - timer.getGlobalBounds().width * 0.5 - 50, 20);
    



    // Debug Text ---------------------------------------------------------------------
    viewText.setPosition(20, 20);
    viewText.setString(viewToggle ? "View Toggle: true" : "View Toggle: false");
    viewText.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    viewText.setCharacterSize(20);

    mousePosText.setPosition(20, 80);
    mousePosText.setString("Mouse Pos: ");
    mousePosText.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    mousePosText.setCharacterSize(20);

    playerPosText.setPosition(20, 150);
    playerPosText.setString("Player Pos: ");
    playerPosText.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    playerPosText.setCharacterSize(20);

    centerPosText.setPosition(20, 200);
    centerPosText.setString("Center Pos: ");
    centerPosText.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    centerPosText.setCharacterSize(20);

   // Add Entities to be updated/rendered
    ecm.addEntity(player);

    // Set load to true when finished.
    setLoaded(true);
}

void PlanetLevelScene::UnLoad() { }

void PlanetLevelScene::Update(const double& dt) {

    // This does not work as center does not change. FOR INFINITE MAP
    //if (Engine::GetWindow().getView().getCenter().x > startingCenter.x + 100 || Engine::GetWindow().getView().getCenter().x < startingCenter.x - 100 ||
    //    Engine::GetWindow().getView().getCenter().y > startingCenter.y + 100 || Engine::GetWindow().getView().getCenter().y < startingCenter.y - 100)
    //{
    //    view.reset(sf::FloatRect(xCount * 100 * 0.5, yCount * 100 * 0.5, 1280.f, 720.f));
    //
    //}
    
    fireTime -= dt;

    if (fireTime <= 0 && Mouse::isButtonPressed(Mouse::Left)) {
        player->GetCompatibleComponent<ShootingComponent>()[0]->Fire();
        fireTime = 0.5f;
    }

    // Moving the window for testing.
    float directY = 0.f;
    float directX = 0.f;

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        directX--;
        //printf("Move left. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        directX++;
        //printf("Move right. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        directY--;
        //printf("Move up. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        directY++;
        //printf("Move down. \n");
    }
    if (Keyboard::isKeyPressed(Keyboard::C)) {
        if (viewToggle) {
            viewToggle = false;
        }
        else {
            viewToggle = true;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::LShift)) {
        speed = 400.f;
    }
    else {
        speed = 200.f;
    }

    // Toggle between fixed player cam and free cam.
    if (viewToggle)
    {
        Engine::moveView(Vector2f(directX * speed * dt, directY * speed * dt));
        viewText.setString(viewToggle ? "View Toggle: true" : "View Toggle: false");
    }
    else {
        gameView = Engine::GetWindow().getView();

        Vector2f offset(150, 150);
        gameView.setCenter(player->getPosition() + offset);
        Engine::setView(gameView);
        //Engine::moveView(Vector2f(player->getPosition()));
        viewText.setString(viewToggle ? "View Toggle: true" : "View Toggle: false");
    }

    // HUD update ----------------------------------------------------------------------------- 
    tempTime += dt;
    if (tempTime >= 1) { seconds++; tempTime = 0.f; }
    if (seconds == 60) { minutes++; seconds = 0; }

    string sec;
    string min;
    if (seconds < 10) { sec = "0" + to_string(seconds); }
    else { sec = to_string(seconds); }

    if (minutes < 10) { min = "0" + to_string(minutes); }
    else { min = to_string(minutes); }

    string s = ("Timer: " + min + ":" + sec);
    timer.setString(s);

    // Debug text update ----------------------------------------------------------------------
    auto mousePos = Mouse::getPosition(Engine::GetWindow());
    string mouseTextx = to_string(mousePos.x);
    string mouseTexty = to_string(mousePos.y);
    mousePosText.setString("Mouse pos: " + mouseTextx + " " + mouseTexty);
    
    auto playerPos = player->getPosition();
    string playerx = to_string(playerPos.x);
    string playery = to_string(playerPos.y);
    playerPosText.setString("Player pos: " + playerx + " " + playery);

    auto centerPos = Engine::GetWindow().getView().getCenter();
    string centerX = to_string(centerPos.x);
    string centerY = to_string(centerPos.y);
    centerPosText.setString("Center pos: " + centerX + " " + centerY);

    Scene::Update(dt);
}

void PlanetLevelScene::Render() { 

    Engine::setView(gameView);
    ls::renderFloor(Engine::GetWindow());
    Scene::Render();

    Engine::setView(hudView);
    Engine::GetWindow().draw(viewText);
    Engine::GetWindow().draw(mousePosText);
    Engine::GetWindow().draw(playerPosText);
    Engine::GetWindow().draw(centerPosText);
    Engine::GetWindow().draw(timer);
    

    Engine::setView(gameView);
}