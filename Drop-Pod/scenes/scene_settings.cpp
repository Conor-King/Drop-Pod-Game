#include "scene_settings.h"
#include "../drop_pod_game.h"
#include <LevelSystem.h>
#include <iostream>

#include"../components/cmp_button.h"
#include "../components/cmp_text.h"
#include <SFML/Window/Keyboard.hpp>
#include <engine.cpp>
#include "../components/cmp_player.h"
using namespace std;
using namespace sf;

shared_ptr<Button> button5;
shared_ptr<Button> button6;
shared_ptr<Button> button7;

void SettingsScene::Load() {
    cout << "Setting Load \n";

    auto txt2 = makeEntity();
    auto t = txt2->addComponent<TextComponent>(490, 180, "Settings");

    auto btn5 = makeEntity();
    button5 = btn5->addComponent<Button>(380, 260, 220, 80, "Arrows Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

    auto btn6 = makeEntity();
    button6 = btn6->addComponent<Button>(600, 260, 220, 80, "WSAD Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

    auto btn7 = makeEntity();
    button7 = btn7->addComponent<Button>(500, 460, 220, 80, "Back", sf::Color::White, sf::Color::Green, sf::Color::Red);


    setLoaded(true);
}
void SettingsScene::Update(const double& dt) {

    if (button5->isPressed()) {
        PlayerComponent::switchState = WSAD;
    }
        
    if (button6->isPressed()) {
        PlayerComponent::switchState = Arrows;
    }
    if (button7->isPressed())
    {
        Engine::ChangeScene(&menu);
    }
Scene::Update(dt);
}

