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
      auto b = btn->addComponent<Button>();
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
