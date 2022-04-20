#pragma once

#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"

class Entity
{
private:

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Component functions


	//functions
	virtual void move(const float& dt,const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};