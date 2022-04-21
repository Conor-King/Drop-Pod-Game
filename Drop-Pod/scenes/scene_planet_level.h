#pragma once

#include "engine.h"

class PlanetLevelScene : public Scene {
public:

	sf::View view;
	float speed;
    int xCount;
    int yCount;
    sf::Vector2f startingCenter;

    std::shared_ptr<sf::Texture> spritesheet;
    

  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;
};