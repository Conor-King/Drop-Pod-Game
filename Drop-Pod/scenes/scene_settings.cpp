#include "scene_settings.h"
#include "../drop_pod_game.h"
#include <LevelSystem.h>
#include <iostream>
#include"../components/cmp_button.h"
#include "../components/cmp_text.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <engine.h>
#include "../components/cmp_player.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

View settingsView;
bool vsync = false;

shared_ptr<Entity> btn4;
shared_ptr<Entity> btn5;
shared_ptr<Entity> btn6;
shared_ptr<Entity> btn7;
shared_ptr<Entity> btn8;

void SettingsScene::Load() {
	cout << "Setting Load \n";

	settingsView = Engine::GetWindow().getView();
	RenderWindow& window = Engine::GetWindow();
	Vector2u windowSize = window.getSize();

	// Todo: Change from hardcoded positions to dynamic versions.
	auto txt2 = makeEntity();
	auto pos = Vector2f(settingsView.getSize().x / 2.0f, 50);
	auto t = txt2->addComponent<TextComponent>(pos.x , pos.y, "Settings");

	btn4 = makeEntity();
	auto btn4Pos = Vector2f(settingsView.getSize().x / 1.6f, settingsView.getSize().y / 5.0f);
	auto button = btn4->addComponent<Button>(btn4Pos, "Arrows Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn5 = makeEntity();
	auto btn5Pos = Vector2f(settingsView.getSize().x / 2.7f, settingsView.getSize().y / 5.0f);
	auto button2 = btn5->addComponent<Button>(btn5Pos, "WSAD Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn6 = makeEntity();
	auto btn6Pos = Vector2f(settingsView.getSize().x / 1.6f, settingsView.getSize().y / 3.0f);
	auto button3 = btn6->addComponent<Button>(btn6Pos, "1280 x 720", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn7 = makeEntity();
	auto btn7Pos = Vector2f(settingsView.getSize().x / 2.7f, settingsView.getSize().y / 3.0f);
	auto button4 = btn7->addComponent<Button>(btn7Pos, "1920 x 1080", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn8 = makeEntity();
	auto btn8Pos = Vector2f(settingsView.getSize().x / 2.0f, settingsView.getSize().y / 1.5f);
	auto button5 = btn8->addComponent<Button>(btn8Pos, "Controlling the framerate", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn9 = makeEntity();
	auto btn9Pos = Vector2f(settingsView.getSize().x / 2.7f, settingsView.getSize().y / 2.0f);
	auto button6 = btn9->addComponent<Button>(btn9Pos, "Sound + 10", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn10 = makeEntity();
	auto btn10Pos = Vector2f(settingsView.getSize().x / 1.6f, settingsView.getSize().y / 2.0f);
	auto button7 = btn10->addComponent<Button>(btn10Pos, "Sound - 10", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn11 = makeEntity();
	auto btn11Pos = Vector2f(settingsView.getSize().x / 2.0f, settingsView.getSize().y / 1.2f);
	auto button8 = btn11->addComponent<Button>(btn11Pos, "Back", sf::Color::White, sf::Color::Green, sf::Color::Red);

	setLoaded(true);
}
void SettingsScene::Update(const double& dt) {
	if (btn4->GetCompatibleComponent<Button>()[0]->isPressed()) {
		switchState = Arrows;
	}
	else if (btn5->GetCompatibleComponent<Button>()[0]->isPressed()) {
		switchState = WSAD;
	}
	else if (btn6->GetCompatibleComponent<Button>()[0]->isPressed()) {
		Engine::changeResolution(1280, 720);
		Engine::ChangeScene(&settings);
	}
	else if (btn7->GetCompatibleComponent<Button>()[0]->isPressed()) {
		Engine::changeResolution(1920, 1080);
		Engine::ChangeScene(&settings);
	}

	else if (btn8->GetCompatibleComponent<Button>()[0]->isPressed()) {
		if (vsync)
		{
			Engine::GetWindow().setVerticalSyncEnabled(false);
			btn8->GetCompatibleComponent<Button>()[0]->_text.setString("Vsync - OFF");
			vsync = false;
		}
		else
		{
			Engine::GetWindow().setVerticalSyncEnabled(true);
			btn8->GetCompatibleComponent<Button>()[0]->_text.setString("Vsync - ON");
			vsync = true;
		}

		
	}

	else if (btn9->GetCompatibleComponent<Button>()[0]->isPressed()) {
		volume >= 100 ? volume = 100 : volume += 10;
	}

	else if (btn10->GetCompatibleComponent<Button>()[0]->isPressed()) {
		volume <= 0 ? volume = 0 :  volume -= 10;
	}

	else if (btn11->GetCompatibleComponent<Button>()[0]->isPressed())
	{
		Engine::ChangeScene(&menu);
	}

	if (!sf::Mouse::isButtonPressed(Mouse::Button::Left))
		Button::_mouseState = BUTTON_IDLE;

	Scene::Update(dt);
}

//void SettingsScene::Render()
//{
//	Engine::setView(settingsView);
//	Scene::Render();
//}