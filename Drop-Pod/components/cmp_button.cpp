#include"cmp_button.h"		
#include<SFML/Window.hpp>
#include <system_renderer.h>
#include <system_resources.h>
#include "engine.h"

using namespace sf;
using namespace std;

unique_ptr<Button> button;
button_states Button::_mouseState;

//shared_ptr<SoundBuffer> soundClick_buffer;
//shared_ptr<Sound> soundClick;

SoundBuffer sound_buffer2;
Sound soundClick;

//
//void Button::LoadMusic() {
//	sound_buffer2 = Resources::get<SoundBuffer>("Click.wav");
//	soundClick = make_shared<Sound>(*sound_buffer2);
//	soundClick->setVolume(0);
//}
void Button::update(double dt) {

	Vector2f point = Vector2f(Mouse::getPosition(Engine::GetWindow()));
	//window - to get position
	// Hover statement
	if (shape.getGlobalBounds().contains(point))
	{
		//Pressed statement
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = BUTTON_ACTIVED;
			soundClick.setBuffer(sound_buffer2);
			soundClick.play();
			if (_mouseState == BUTTON_IDLE)
				_mouseState = BUTTON_ACTIVED;
			else if (_mouseState == BUTTON_ACTIVED)
				_mouseState = BUTTON_DOWN;
		}
		else
		{
			buttonState = BUTTON_HOVER;
		}
	}
	else
		buttonState = BUTTON_IDLE;


	switch (buttonState)
	{
	case BUTTON_IDLE:
		shape.setFillColor(idleColor);
		break;
	case BUTTON_HOVER:
		shape.setFillColor(hoverColor);
		break;
	case BUTTON_ACTIVED:
		shape.setFillColor(activeColor);
		break;
	default:
		shape.setFillColor(sf::Color::Cyan);
		break;
	}
}

void Button::render() {
	Renderer::queue(&shape);
	Renderer::queue(&_text);
}

Button::Button(Entity* p, sf::Vector2f position, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	: Component(p){

	buttonState = BUTTON_IDLE;
	shape.setSize(sf::Vector2f(200, 70));
	shape.setPosition(position - (shape.getSize() / 2.f));
	shape.setOrigin(0,0);
	//_mouseState = BUTTON_IDLE;
	
	_text.setString(text);
	_text.setFillColor(sf::Color::Black);
	_text.setCharacterSize(20); 
	font = Resources::get<sf::Font>("font.ttf");
	_text.setFont(*font);

	_text.setPosition(Vector2f(
		(shape.getPosition().x + shape.getLocalBounds().width / 2.f) - (_text.getLocalBounds().width / 2),
		(shape.getPosition().y + shape.getLocalBounds().height / 2.f) - (_text.getLocalBounds().height / 2)));

	auto bounds = _text.getLocalBounds();
	auto box = shape.getSize();

	//_text.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
	

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	shape.setFillColor(idleColor);
	
}

const bool Button::isPressed() const
{
	if (buttonState == BUTTON_ACTIVED)
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

