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

shared_ptr<Entity> btn4;
shared_ptr<Entity> btn5;
shared_ptr<Entity> btn6;
shared_ptr<Entity> btn7;
shared_ptr<Entity> btn8;

void SettingsScene::Load() {
	cout << "Setting Load \n";

	settingsView = Engine::GetWindow().getView();


	// Todo: Change from hardcoded positions to dynamic versions.
	auto txt2 = makeEntity();
	auto t = txt2->addComponent<TextComponent>(490, 180, "Settings");

	btn4 = makeEntity();
	auto btn4Pos = Vector2f(380, 260);
	auto button = btn4->addComponent<Button>(btn4Pos, "Arrows Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn5 = makeEntity();
	auto btn5Pos = Vector2f(600, 260);
	auto button2 = btn5->addComponent<Button>(btn5Pos, "WSAD Movment", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn6 = makeEntity();
	auto btn6Pos = Vector2f(380, 360);
	auto button3 = btn6->addComponent<Button>(btn6Pos, "1280 x 720", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn7 = makeEntity();
	auto btn7Pos = Vector2f(600, 360);
	auto button4 = btn7->addComponent<Button>(btn7Pos, "1920 x 1080", sf::Color::White, sf::Color::Green, sf::Color::Red);

	btn8 = makeEntity();
	auto btn8Pos = Vector2f(500, 460);
	auto button5 = btn8->addComponent<Button>(btn8Pos, "Back", sf::Color::White, sf::Color::Green, sf::Color::Red);

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
	}
	else if (btn7->GetCompatibleComponent<Button>()[0]->isPressed()) {
		Engine::changeResolution(1920, 1080);
	}

	else if (btn8->GetCompatibleComponent<Button>()[0]->isPressed())
	{
		Engine::ChangeScene(&menu);
	}

	if (!sf::Mouse::isButtonPressed(Mouse::Button::Left))
		Button::_mouseState = BUTTON_IDLE;

	Scene::Update(dt);
}