#include<iostream>	
#include<ctime>	
#include<cstdlib>	
#include<sstream>	
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <ecm.h>
#include <system_renderer.h>
#include <system_resources.h>

enum button_states{BUTOON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
private:
	sf::RectangleShape shape;
	sf::Text _text;
	sf::Font* font;

	short unsigned buttonState;
	bool presed;
	bool hover;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:
	Button(float x,float y, float width, float height,sf::Font* font, std::string text, sf::Color idleColor,sf::Color hoverColor,sf::Color activeColor );

		~Button();


		const bool isPressed() const;

		void update(sf::Vector2f mousePos);
		void Renderer::queue(sf::RenderTarget* target);

};

