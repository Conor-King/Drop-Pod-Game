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

shared_ptr<Entity> btn4;
shared_ptr<Entity> btn5;
shared_ptr<Entity> btn6;

void SettingsScene::Load() {
    cout << "Setting Load \n";

    auto txt2 = makeEntity();
    auto t = txt2->addComponent<TextComponent>(490, 180, "Settings");

     btn4 = makeEntity();
    auto button = btn4->addComponent<Button>(380, 260, 220, 80, "Arrows Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

     btn5 = makeEntity();
    auto button2 = btn5->addComponent<Button>(600, 260, 220, 80, "WSAD Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

     btn6 = makeEntity();
    auto button3 = btn6->addComponent<Button>(500, 460, 220, 80, "Back", sf::Color::White, sf::Color::Green, sf::Color::Red);


    setLoaded(true);
}
void SettingsScene::Update(const double& dt) {

    if (btn4->GetCompatibleComponent<Button>()[0]->isPressed()) {
        switchState = Arrows;
    }
    else if (btn5->GetCompatibleComponent<Button>()[0]->isPressed()) {
        switchState = WSAD;
    }
    else if (btn6->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&menu);
    }

    if (!sf::Mouse::isButtonPressed(Mouse::Button::Left))
        Button::_mouseState = BUTTON_IDLE;

    Scene::Update(dt);
}

