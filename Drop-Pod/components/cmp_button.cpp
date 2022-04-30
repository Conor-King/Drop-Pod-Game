#include"cmp_button.h"		
#include<SFML/Window.hpp>
#include <system_renderer.h>
#include <system_resources.h>
#include "engine.h"

using namespace sf;
using namespace std;

unique_ptr<Button> button;
button_states Button::_mouseState;

void Button::update(double dt) {

	Vector2f point = Vector2f(Mouse::getPosition(Engine::GetWindow()).x, Mouse::getPosition(Engine::GetWindow()).y);
	//window - to get position
	// Hover statement
	if (this->shape.getGlobalBounds().contains(point))
	{
		//Pressed statement
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BUTTON_ACTIVED;

			if (_mouseState == BUTTON_IDLE)
				_mouseState = BUTTON_ACTIVED;
			else if (_mouseState == BUTTON_ACTIVED)
				_mouseState = BUTTON_DOWN;
		}
		else
		{
			this->buttonState = BUTTON_HOVER;
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
	case BUTTON_ACTIVED:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Cyan);
		break;
	}
}

void Button::render() {
	Renderer::queue(&shape);
	Renderer::queue(&_text);
}

Button::Button(Entity* p,float x, float y, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	: Component(p){

	this->buttonState = BUTTON_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(220, 80));
	this->shape.setOrigin(shape.getLocalBounds().width / 2.0f, shape.getLocalBounds().height / 2.0f);
	//_mouseState = BUTTON_IDLE;
	
	this->_text.setString(text);
	this->_text.setFillColor(sf::Color::Black);
	this->_text.setCharacterSize(20); 
	font = Resources::get<sf::Font>("font.ttf");
	this->_text.setFont(*font);
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
	if (this->buttonState == BUTTON_ACTIVED)
	{
		if(_mouseState == BUTTON_ACTIVED)
			return true;
	}
		
	return false;
}






//}

//void Button::render(sf::RenderTarget * target)
//{
//	target->draw(this->shape);
//	target->draw(this->_text);
//}

