#pragma once

#include "engine.h"

class SettingsScene : public Scene {
public:
    SettingsScene() = default;
    ~SettingsScene() override = default;
    void Load() override;

    void Update(const double& dt) override;
    std::shared_ptr<Entity> btn4;
    std::shared_ptr<Entity> btn5;
    std::shared_ptr<Entity> btn6;
};