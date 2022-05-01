#pragma once

#include<iostream>	
#include<ctime>	
#include<cstdlib>	
#include<sstream>	
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <ecm.h>
#include <system_renderer.h>
#include <system_resources.h>

enum button_states { BUTTON_IDLE, BUTTON_HOVER, BUTTON_ACTIVED, BUTTON_DOWN };


class Button : public Component {

private:
	sf::RectangleShape shape;
	
	std::shared_ptr<sf::Font> font;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:
sf::Text _text;
	short unsigned buttonState;
	//bool presed;
	//bool hover;


	Button() = delete;
	
	explicit Button(Entity* p, sf::Vector2f position, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	void update(double dt) override;
	void render() override;
	~Button() override = default;
		
	const bool isPressed() const;

	static button_states _mouseState;
};

