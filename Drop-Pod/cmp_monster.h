#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Monster {
private:
	void initVariables();

protected:
	sf::Sprite sprite;
	/*MovementComponent* movementComponent;*/

public:
	Monster();
	virtual ~Monster();

	//Component functions
	void setTexture(sf::Texture& texture);


};