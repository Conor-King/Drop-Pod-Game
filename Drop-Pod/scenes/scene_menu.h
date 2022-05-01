#pragma once

#include "engine.h"
#include "../components/cmp_button.h"

class MenuScene : public Scene {
public:
  MenuScene() = default;
  ~MenuScene() override = default;

  void Load() override;

  void Update(const double& dt) override;

  std::shared_ptr<Entity> btnPlay;
  std::shared_ptr<Entity> btnSetting;
  std::shared_ptr<Entity> btnExit;

  

	void Render() override;
};
