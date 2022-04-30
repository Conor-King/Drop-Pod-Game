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

sf::Music music;

shared_ptr<Entity> btn;
shared_ptr<Entity> btn2;
shared_ptr<Entity> btn3;

View menuView;
View debugView;

Text mousePosText2;


void MenuScene::Load() {
    cout << "Menu Load \n";

    menuView = Engine::GetWindow().getView();

    mousePosText2.setPosition(20, 20);
    mousePosText2.setString("Mouse Pos: ");
    mousePosText2.setFont(*Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
    mousePosText2.setCharacterSize(20);

    RenderWindow& window = Engine::GetWindow();
    Vector2u windowSize = window.getSize();

    auto txt = makeEntity();
    auto pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 5.0f);
    auto t = txt->addComponent<TextComponent>(menuView.getSize().x / 2.0f, menuView.getSize().y / 5.0f, "DROP POD");

    btn = makeEntity();
    auto btnPos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 1.5f);
    auto button = btn->addComponent<Button>(btnPos,  "Exit", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btn2 = makeEntity();
    auto btn2Pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 2.f);
    auto button2 = btn2->addComponent<Button>(btn2Pos,  "Setting", sf::Color::White, sf::Color::Green, sf::Color::Red);

    btn3 = makeEntity();
    auto btn3Pos = Vector2f(menuView.getSize().x / 2.0f, menuView.getSize().y / 3.f);
    auto button3 = btn3->addComponent<Button>(btn3Pos, "Play", sf::Color::White, sf::Color::Green, sf::Color::Red);

    auto musicstatus = music.getStatus();
    if (musicstatus == SoundSource::Stopped || musicstatus == SoundSource::Paused)
    {
        if (!music.openFromFile("res/assets/background_music/Cold-Moon.ogg"))
            printf("music broken"); // error
        music.setVolume(30);
    	music.setLoop(true);
    	music.play();
    }
  
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

    if (btn3->GetCompatibleComponent<Button>()[0]->isPressed())
    {
        Engine::ChangeScene(&planetLevel);
        ls::setTextureMap("res/assets/tiles/grass.png");
        music.stop();
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

    auto mousePos = Mouse::getPosition(Engine::GetWindow());
    string mouseTextx = to_string(mousePos.x);
    string mouseTexty = to_string(mousePos.y);
    mousePosText2.setString("Mouse pos: " + mouseTextx + " " + mouseTexty);
    //cout << Button::_mouseState << endl;
   
  Scene::Update(dt);
}

void MenuScene::Render()
{
    Engine::setView(debugView);
    Engine::GetWindow().draw(mousePosText2);

    Engine::setView(menuView);
    Scene::Render();
}

