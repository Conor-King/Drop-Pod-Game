#include<iostream>	
#include<ctime>	
#include<cstdlib>	
#include<sstream>	
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <ecm.h>
#include <system_renderer.h>
#include <system_resources.h>

enum button_states{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button : public Component {

private:
	sf::RectangleShape shape;
	sf::Text _text;
	sf::Font font;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:

	short unsigned buttonState;
	bool presed;
	bool hover;


	Button() = delete;
	/*explicit Button(Entity* p);*/
	explicit Button(Entity* p, float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	void update(double dt) override;

	void render() override;

	~Button() override = default;
		


		const bool isPressed() const;

		/*void update(sf::Vector2f mousePos);
		void Renderer::queue(sf::RenderTarget* target);*/

};

