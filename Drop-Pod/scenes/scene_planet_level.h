#pragma once

#include "engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class PlanetLevelScene : public Scene {
public:

	EntityManager ecm;

	// Views
	sf::View gameView;
	sf::View hudView;

	// Level
	float speed;
	int xCount;
	int yCount;
	sf::Vector2f startingCenter;
	bool viewToggle;
	bool pauseGame;
	std::string result;

	// Player
	std::shared_ptr<Entity> player;
	std::shared_ptr<sf::Texture> playerSpriteIdle;
	std::shared_ptr<sf::Texture> playerSpriteMoving;
	sf::IntRect playerRect;

	std::shared_ptr<sf::SoundBuffer> soundShoot_buffer;
	std::shared_ptr<sf::Sound> soundShoot;

	// Enemies
	std::shared_ptr<Entity> enemy;
	std::shared_ptr<sf::Texture> enemySprite;
	sf::IntRect enemyRect;

	// Actual HUD
	float tempTime;
	int minutes;
	int seconds;
	sf::Text timer;

	sf::Text endText;

	float fireTime;

	void Load() override;

	void UnLoad() override;

	void Update(const double& dt) override;

	void Render() override;

	void RenderEnd();
};