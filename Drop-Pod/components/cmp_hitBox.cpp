#include "HitBox.h"

HitBox::HitBox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
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
    // TODO: insert return statement here
}

void HitBox::setPosition(const sf::Vector2f& position)
{
}

void HitBox::setPosition(const float x, const float y)
{
}

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
