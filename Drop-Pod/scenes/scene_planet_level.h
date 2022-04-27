#pragma once

#include "engine.h"
#include <SFML/Graphics.hpp>

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

    // Player
    std::shared_ptr<Entity> player;
    std::shared_ptr<sf::Texture> spritesheet;

    // Actual HUD
    float tempTime;
    int minutes;
    int seconds;
    sf::Text timer;

    float fireTime;
    

  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;
};