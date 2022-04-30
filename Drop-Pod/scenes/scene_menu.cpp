#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include "LevelSystem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>	
#include"../components/cmp_button.h"
#include "engine.cpp"
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;

//sf::Music music;

shared_ptr<Entity> btn;
shared_ptr<Entity> btn2;
shared_ptr<Entity> btn3;


void MenuScene::Load() {
  cout << "Menu Load \n";
  
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>(current_x/2.0f, current_y/5.0f, "DROP POD");

    btn = makeEntity();
    auto button = btn->addComponent<Button>(current_x / 2.0f, current_y / 1.5f,  "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btn2 = makeEntity();
    auto button2 = btn2->addComponent<Button>(current_x / 2.0f, current_y / 2.0f,  "Setting", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btn3 = makeEntity();
    auto button3 = btn3->addComponent<Button>(current_x / 2.0f, current_y / 3.0f, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);


  
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

    if (btn3->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&planetLevel);
        ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
    }
    else if (btn2->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&settings);
    }
    else if (btn->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::GetWindow().close();
    }

    if(!sf::Mouse::isButtonPressed(Mouse::Button::Left))
        Button::_mouseState = BUTTON_IDLE;


    //cout << Button::_mouseState << endl;
   
  Scene::Update(dt);
}
