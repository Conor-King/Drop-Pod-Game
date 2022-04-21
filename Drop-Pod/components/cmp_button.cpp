#include"cmp_button.h"		
#include<SFML/Window.hpp>
#include <system_renderer.h>
#include <system_resources.h>
#include "engine.h"

using namespace sf;
using namespace std;

unique_ptr<Button> button;

void Button::update(double dt) {
	//Default
	this->buttonState = BUTTON_IDLE;

	Vector2f point = Vector2f(Mouse::getPosition(Engine::GetWindow()).x, Mouse::getPosition(Engine::GetWindow()).y);
	//window - to get position
	// Hover statement
	if (this->shape.getGlobalBounds().contains(point))
	{
		this->buttonState = BUTTON_HOVER;
		//Pressed statement
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BUTTON_ACTIVE;
		}
	}
	else
		this->buttonState = BUTTON_IDLE;


	switch (this->buttonState)
	{
	case BUTTON_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BUTTON_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BUTTON_ACTIVE:
		this->shape.setFillColor(this->activeColor);
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render() {
	Renderer::queue(&shape);
	Renderer::queue(&_text);
}

Button::Button(Entity* p,float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	: Component(p){

	this->buttonState = BUTTON_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	
	this->_text.setString(text);
	this->_text.setFillColor(sf::Color::Black);
	this->_text.setCharacterSize(20); 
	font.loadFromFile("res/fonts/font.ttf");
	this->_text.setFont(font);
	this->_text.setPosition(sf::Vector2f(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->_text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->_text.getGlobalBounds().height / 2.f
	));

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	this->shape.setFillColor(this->idleColor);

}

const bool Button::isPressed() const
{
	if (this->buttonState == BUTTON_ACTIVE)
		return true;
	return false;
}






//}

//void Button::render(sf::RenderTarget * target)
//{
//	target->draw(this->shape);
//	target->draw(this->_text);
//}

