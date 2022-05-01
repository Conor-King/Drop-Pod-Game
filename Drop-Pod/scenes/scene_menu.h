#pragma once

#include "engine.h"
#include "../components/cmp_button.h"

class MenuScene : public Scene {
public:
  MenuScene() = default;
  ~MenuScene() override = default;

  void Load() override;

  void Update(const double& dt) override;

  std::shared_ptr<Entity> btn;
  std::shared_ptr<Entity> btn2;
  std::shared_ptr<Entity> btn3;

  

	void Render() override;
};
