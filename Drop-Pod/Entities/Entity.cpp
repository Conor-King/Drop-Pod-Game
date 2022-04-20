#include "Entity.h"

void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->movementSpeed = 100.f;
}

Entity::Entity()
{
	this->initVariables;
	
}
Entity::~Entity()
{
	delete this->sprite;
}

//Component functions
void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

//Functions
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->sprite)
	{
		this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
	}
}

void Entity::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::s))
		this->move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape)
}
