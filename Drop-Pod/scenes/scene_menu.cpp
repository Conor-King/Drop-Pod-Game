#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include "LevelSystem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include"../components/cmp_button.h"	


using namespace std;
using namespace sf;

void MenuScene::Load() {
  cout << "Menu Load \n";
  {
      auto btn = makeEntity();
      auto b = btn->addComponent<Button>(450,350,250,100,"Exit",sf::Color::White, sf::Color::Green, sf::Color::Red);
     
      auto btn2 = makeEntity();
      auto b2 = btn2->addComponent<Button>(450, 175, 250, 100, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i position = sf::Mouse::getPosition();
        Engine::ChangeScene(&planetLevel);
    }
   {
        
    }
  /*if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
    Engine::ChangeScene(&planetLevel);
    ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
  }

  Scene::Update(dt);
}
