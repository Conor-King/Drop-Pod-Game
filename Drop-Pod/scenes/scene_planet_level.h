#pragma once

#include "engine.h"

class PlanetLevelScene : public Scene {
public:

    EntityManager ecm;

	sf::View gameView;
    sf::View hudView;

	float speed;
    int xCount;
    int yCount;
    sf::Vector2f startingCenter;
    bool viewToggle;

    std::shared_ptr<Entity> player;
    std::shared_ptr<sf::Texture> spritesheet;
    

  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;
};