#include "Player.h"


	
float movementSpeed = 100.f;


Player::Player()
{
	
	
}
Player::~Player()
{
	delete this->sprite;
}

//Functions
void Player::move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->sprite)
	{
		this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
	}
}

void Player::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, 1.f);
}

void Player::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
}
