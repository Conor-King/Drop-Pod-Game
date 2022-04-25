
#include "cmp_hitBox.h"

HitBox::HitBox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height) : sprite(sprite), offsetX(offset_x), offsetY(offset_y)
{
	this->nextPosition.left = 0.f;
	this->nextPosition.top = 0.f;
	this->nextPosition.width = width;
	this->nextPosition.height = height;

	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(-1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
}

HitBox::~HitBox()
{
}

const sf::Vector2f& HitBox::getPosition() const
{
    return this->hitbox.getPosition();
    // TODO: insert return statement here
}

const sf::FloatRect HitBox::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds();
}

const sf::FloatRect& HitBox::getNextPosition(const sf::Vector2f& velocity)
{
    this->nextPosition.left = this->hitbox.getPosition().x + velocity.x;
    this->nextPosition.top = this->hitbox.getPosition().y + velocity.y;

    return this->nextPosition;
}

void HitBox::setPosition(const sf::Vector2f& position)
{
	this->hitbox.setPosition(position);
	this->sprite.setPosition(position.x - this->offsetX, position.y - this->offsetY);
}

void HitBox::setPosition(const float x, const float y)
{
}

//Checks if the hitbox intersects with another hitbox
bool HitBox::collides(const sf::FloatRect& frect)
{
    return false;
}

void HitBox::update()
{
}

void HitBox::render(sf::RenderTarget& target)
{
}
