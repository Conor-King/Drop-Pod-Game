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

//sf::Music music;

shared_ptr<Entity> btnPlay;
shared_ptr<Entity> btnSetting;
shared_ptr<Entity> btnExit;

View menuView;





void MenuScene::Load() {
    cout << "Menu Load \n";

    menuView = Engine::GetWindow().getView();
    RenderWindow& window = Engine::GetWindow();
    Vector2u windowSize = window.getSize();

    auto txt = makeEntity();
    auto pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 5.0f);
    auto t = txt->addComponent<TextComponent>(menuView.getSize().x / 2.0f, menuView.getSize().y / 5.0f, "DROP POD");

    btnPlay = makeEntity();
    auto btnPos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 1.5f);
    auto button = btnPlay->addComponent<Button>(btnPos,  "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btnSetting = makeEntity();
    auto btn2Pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 2.f);
    auto button2 = btnSetting->addComponent<Button>(btn2Pos,  "Setting", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btnExit = makeEntity();
    auto btn3Pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 3.f);
    auto button3 = btnExit->addComponent<Button>(btn3Pos, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);
  
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

    if (btnExit->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&planetLevel);
        ls::setTextureMap(IntRect(Vector2i(0, 32), Vector2i(100, 100)), "res/assets/tiles/grass.png");
    }
    else if (btnSetting->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&settings);
    }
    else if (btnPlay->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::GetWindow().close();
    }

    if(!sf::Mouse::isButtonPressed(Mouse::Button::Left))
        Button::_mouseState = BUTTON_IDLE;

    
    //cout << Button::_mouseState << endl;
   
  Scene::Update(dt);
}

void MenuScene::Render()
{
    Engine::setView(menuView);
    Scene::Render();
}

