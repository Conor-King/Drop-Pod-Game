#include"cmp_button.h"		
#include<SFML/Window.hpp>
#include <system_renderer.h>
#include <system_resources.h>


void Button::update(double dt) {}

void Button::render() { Renderer::queue(&_text); }

//Button::Button(Entity* p,float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
Button::Button(Entity* p)
	: Component(p){

	float x =10.f ;
	float y =10.f ;
	float width =100.f ;
	float height =100.f ;
	std::string text = "test";



	this->buttonState = BUTOON_IDLE;


	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	/*this->font = font;*/
	/*this->_text.setFont(*this->font);*/
	this->_text.setString(text);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setCharacterSize(12); 
	/*this->_text.setPosition(sf::Vector2f(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->_text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->_text.getGlobalBounds().height / 2.f
	));*/

	this->activeColor = sf::Color::Green/* activeColor*/;
	this->hoverColor = sf::Color::Green /*hoverColor*/;
	this->idleColor = sf::Color::Green /*idleColor*/;

	this->shape.setFillColor(/*this->idleColor*/sf::Color::White);

}

const bool Button::isPressed() const
{
	if (this->buttonState == BUTTON_ACTIVE)
		return true;
	return false;
}

//void Button::update(const sf::Vector2f mousePos)
//{
//	//Default
//	this->buttonState = BUTOON_IDLE;
//
//
//	// Hover statement
//	if (this->shape.getGlobalBounds().contains(mousePos))
//	{
//		this->buttonState = BUTTON_HOVER;
//		//Pressed statement
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
//			this->buttonState = BUTTON_ACTIVE;
//		}
//}
//	switch (this->buttonState)
//	{
//	case BUTOON_IDLE:
//		this->shape.setFillColor(this->idleColor);
//			break;
//		case BUTTON_HOVER:
//			this->shape.setFillColor(this->hoverColor);
//			break;
//		case BUTTON_ACTIVE:
//			this->shape.setFillColor(this->activeColor);
//	default:
//		this->shape.setFillColor(sf::Color::Red);
//		break;
//	}





//}

//void Button::render(sf::RenderTarget * target)
//{
//	target->draw(this->shape);
//	target->draw(this->_text);
//}

