#include "scene_planet_level.h"
#include "engine.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_player.h"
#include "../components/cmp_monster.h"
#include "../components/cmp_shooting.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_text.h"
#include <LevelSystem.h>
#include <system_resources.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>


/* Todo:
* Return to menu
* Victory text
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
bool pauseGame = false;
string result = "Not Set";

// Player Variables
shared_ptr<Entity> player;
shared_ptr<Texture> playerSpriteIdle;
shared_ptr<Texture> playerSpriteMoving;
IntRect playerRect;

shared_ptr<SoundBuffer> soundShoot_buffer;
shared_ptr<Sound> soundShoot;

// Enemy Variables
shared_ptr<Entity> enemy;
shared_ptr<Texture> enemySprite;
IntRect enemyRect;

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

Text endText;

// Shooting Delay
float fireTime = 0.f;

void PlanetLevelScene::Load() {
	ecm = Scene::getEcm();

	ls::loadLevelFile("res/levels/smallFloorMap.txt");

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
	gameView.reset(sf::FloatRect(xCount * 100 * 0.5, yCount * 100 * 0.5, Engine::GetWindow().getSize().x, Engine::GetWindow().getSize().y));
	Engine::setView(gameView);

	startingCenter = gameView.getCenter();

	// Setting the speed of the view.
	speed = 200.f;

	// Sound -----------------------------------------------------------------------

	soundShoot_buffer = Resources::get<SoundBuffer>("Shoot_001.wav");
	soundShoot = make_shared<Sound>(*soundShoot_buffer);
	soundShoot->setVolume(20);

	

	// Player Entity ---------------------------------------------------------------

	playerRect = { Vector2i(0, 0), Vector2i(150, 150) };

	playerSpriteIdle = Resources::get<Texture>("Idle.png");
	playerSpriteMoving = Resources::get<Texture>("Run.png");

	player = makeEntity();
	//player->setPosition(Vector2f(view.getSize().x * 0.5, view.getSize().y * 0.5));
	player->setPosition(startingCenter);

	auto psprite = player->addComponent<SpriteComponent>();
	psprite->setTexture(playerSpriteIdle);
	psprite->getSprite().setOrigin(psprite->getSprite().getLocalBounds().width * 0.5, psprite->getSprite().getLocalBounds().height * 0.5);
	psprite->getSprite().setScale(2, 2);

	auto panimation = player->addComponent<AnimationComponent>();
	panimation->setAnimation(8, 0.1, playerSpriteIdle, playerRect);

	auto pmove = player->addComponent<ActorMovementComponent>();
	pmove->setSpeed(10.f); // -----------------------------------------------------------------Player speed

	auto pattributes = player->addComponent<PlayerComponent>();

	auto pshooting = player->addComponent<ShootingComponent>();

	// Enemies entity -----------------------------------------------------------------

	enemyRect = { Vector2i(0, 0), Vector2i(64, 64) };

	enemySprite = Resources::get<Texture>("Trash-Monster-Sprite-V2.png");

	enemy = makeEntity();

	enemy->setPosition(startingCenter + Vector2f(200, 0));

	auto esprite = enemy->addComponent<SpriteComponent>();
	esprite->setTexture(enemySprite);
	esprite->getSprite().setOrigin(esprite->getSprite().getLocalBounds().width * 0.5, esprite->getSprite().getLocalBounds().height * 0.5);
	esprite->getSprite().setScale(2, 2);

	auto eanimation = enemy->addComponent<AnimationComponent>();
	eanimation->setAnimation(6, 0.1, enemySprite, enemyRect);

	auto emove = enemy->addComponent<ActorMovementComponent>();
	auto eattributes = enemy->addComponent<MonsterComponent>(player);

	// HUD ----------------------------------------------------------------------------
	tempTime = 0.f;
	// Todo: Make sure to change this back after testing.
	seconds = 0;
	minutes = 9;
	timer.setString("Timer: 00:00");
	timer.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	timer.setCharacterSize(20);
	timer.setOrigin(timer.getGlobalBounds().width * 0.5, timer.getGlobalBounds().height * 0.5);
	timer.setPosition(gameView.getSize().x * 0.5 - timer.getGlobalBounds().width * 0.5 - 50, 20);

	endText.setString("");
	endText.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	endText.setCharacterSize(50);
	endText.setPosition(gameView.getSize().x / 2, gameView.getSize().y / 2);

	// Debug Text ---------------------------------------------------------------------
	viewText.setPosition(20, 20);
	viewText.setString(viewToggle ? "View Toggle: true" : "View Toggle: false");
	viewText.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	viewText.setCharacterSize(20);

	mousePosText.setPosition(20, 80);
	mousePosText.setString("Mouse Pos: ");
	mousePosText.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	mousePosText.setCharacterSize(20);

	playerPosText.setPosition(20, 150);
	playerPosText.setString("Player Pos: ");
	playerPosText.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	playerPosText.setCharacterSize(20);

	centerPosText.setPosition(20, 200);
	centerPosText.setString("Center Pos: ");
	centerPosText.setFont(*Resources::get<Font>("RobotoMono-Regular.ttf"));
	centerPosText.setCharacterSize(20);

	// Add Entities to be updated/rendered
	ecm.addEntity(player);
	ecm.addEntity(enemy);

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

	if (minutes >= 10)
	{
		pauseGame = true;
		result = "win";
	}

	if (player->isAlive() == false)
	{
		pauseGame = true;
		result = "lose";
	}

	if (!pauseGame)
	{
		// Player updates -----------------------------------------------------------------------------------------------
		fireTime -= dt;

		if (fireTime <= 0 && Mouse::isButtonPressed(Mouse::Left)) {
			player->GetCompatibleComponent<ShootingComponent>()[0]->Fire();
			fireTime = 0.5f;
			soundShoot->play();
		}

		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			player->GetCompatibleComponent<PlayerComponent>()[0]->setHealth(0);
		}

		// Switch between idle and moving animation for player moving.
		if (player->GetCompatibleComponent<ActorMovementComponent>()[0]->getMoving())
		{
			player->GetCompatibleComponent<AnimationComponent>()[0]->setAnimation(8, 0.1, playerSpriteMoving, playerRect);
		}
		else
		{
			player->GetCompatibleComponent<AnimationComponent>()[0]->setAnimation(8, 0.1, playerSpriteIdle, playerRect);
		}

		// Flip the sprite if moving left.
		if (player->GetCompatibleComponent<ActorMovementComponent>()[0]->getDirection())
		{
			auto& p = player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite();
			player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setOrigin(p.getLocalBounds().width * 0.5, p.getLocalBounds().height * 0.5);
			player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setScale(-2.f, 2.f);
		}
		else
		{
			auto& p = player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite();
			player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setOrigin(p.getLocalBounds().width * 0.5, p.getLocalBounds().height * 0.5);
			player->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setScale(2.f, 2.f);
		}

		// Moving the window for testing. --------------------------------------------------------------------------------
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

			gameView.setCenter(player->getPosition());
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
	else
	{
		RenderEnd();
	}
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
	Engine::GetWindow().draw(endText);

	Engine::setView(gameView);
}

// Todo: Text does not render properly in the middle of the screen like i think it should.
void PlanetLevelScene::RenderEnd()
{
	if (result == "win")
	{
		endText.setString("Victory!");
		endText.setOutlineColor(Color::Black);
		endText.setOutlineThickness(2);
		endText.setOrigin(endText.getLocalBounds().width * 0.5, endText.getLocalBounds().height * 0.5);
		endText.setPosition(gameView.getSize().x * 0.5, gameView.getSize().y * 0.5);
	}
	if (result == "lose")
	{
		endText.setString("Defeat!");
		endText.setOutlineColor(Color::Black);
		endText.setOutlineThickness(2);
		Vector2f pos = Vector2f((gameView.getSize().x / 2.f) - endText.getGlobalBounds().width / 2.f, (gameView.getSize().y / 2.f) - endText.getGlobalBounds().height / 2.f);
		endText.setPosition(pos);
		endText.setOrigin(endText.getLocalBounds().width * 0.5, endText.getLocalBounds().height * 0.5);
	}
}