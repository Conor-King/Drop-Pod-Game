#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include "LevelSystem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>	
#include"../components/cmp_button.h"
#include "engine.h"
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;

shared_ptr<Button> button;
shared_ptr<Button> button2;
shared_ptr<Button> button3;
//sf::Music music;

void MenuScene::Load() {
  cout << "Menu Load \n";

      auto txt = makeEntity();
      auto t = txt->addComponent<TextComponent>(490, 180, "DROP POD");

    auto btn = makeEntity();
    button = btn->addComponent<Button>(500, 460, 220, 80, "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);

    auto btn2 = makeEntity();
    button2 = btn2->addComponent<Button>(500, 360, 220, 80, "Setting", sf::Color::White, sf::Color::Green, sf::Color::Red);

    auto btn3 = makeEntity();
    button3 = btn3->addComponent<Button>(500, 260, 220, 80, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);


  
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

    if (button3->isPressed())
    {
        Engine::ChangeScene(&planetLevel);
        ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
    }
    if (button2->isPressed())
    {
        Engine::ChangeScene(&settings);
    }
    if (button->isPressed())
    {
        Engine::GetWindow().close();
    }

  Scene::Update(dt);
}
