#include"button.h"		
#include<SFML/Window.hpp>




Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{

	this->buttonState = BUTOON_IDLE;


	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->_text.setFont(*this->font);
	this->_text.setString(text);
	this->_text.setFillColor(sf::Color::White);
	this->_text.setCharacterSize(12); 
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

void Button::update(const sf::Vector2f mousePos)
{
	//Default
	this->buttonState = BUTOON_IDLE;


	// Hover statement
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BUTTON_HOVER;
		//Pressed statement
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BUTTON_ACTIVE;
		}
}
	switch (this->buttonState)
	{
	case BUTOON_IDLE:
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

//void Button::render(sf::RenderTarget * target)
//{
//	target->draw(this->shape);
//	target->draw(this->_text);
//}

