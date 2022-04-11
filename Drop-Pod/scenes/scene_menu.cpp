#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include"../components/cmp_button.h"	


using namespace std;
using namespace sf;

void MenuScene::Load() {
  cout << "Menu Load \n";
  {
      auto btn = makeEntity();
      auto b = btn->addComponent<Button>(450,200,250,100,"Go to game",sf::Color::White, sf::Color::Green, sf::Color::Red);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
      }
    
      sf::Vector2i position = sf::Mouse::getPosition();
    
      sf::Mouse::setPosition(sf::Vector2i(450, 200), window); {
          Engine::ChangeScene(&planetLevel);
      }
      auto btn2 = makeEntity();
      auto b2 = btn2->addComponent<Button>(450, 50, 250, 100, "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);
      //CurrentScene.Size.Width / 2
      //CurrentScene.Size.Height / 2
  }

  /*{
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>(
        "Drop Pod\nPress Space to Start");
  }*/
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

  if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
    Engine::ChangeScene(&planetLevel);
  }

  Scene::Update(dt);
}
