#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include "LevelSystem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>	
#include"../components/cmp_button.h"
#include "engine.cpp"


using namespace std;
using namespace sf;

shared_ptr<Button> button;
shared_ptr<Button> button2;
shared_ptr<Button> button3;

void MenuScene::Load() {
  cout << "Menu Load \n";

  auto txt = makeEntity();
  auto t = txt->addComponent<TextComponent>(490, 180, "DROP POD");

  {
      auto btn = makeEntity();
      button = btn->addComponent<Button>(500, 460, 220, 80, "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);

      auto btn2 = makeEntity();
      button2 = btn2->addComponent<Button>(500, 360, 220, 80, "Setting", sf::Color::White, sf::Color::Green, sf::Color::Red);

      auto btn3 = makeEntity();
      button3 = btn3->addComponent<Button>(500, 260, 220, 80, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);

  }

  /*{
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>(
        "Drop Pod\nPress Space to Start");
  }*/
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

    if (button3->isPressed())
    {
        Engine::ChangeScene(&planetLevel);
        ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
    }


    if (button->isPressed())
    {
        Engine::GetWindow().close();
    }

  // cout << "Menu Update "<<dt<<"\n";
    
  //if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
  //  Engine::ChangeScene(&planetLevel);
  //  ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
  //}

  Scene::Update(dt);
}
