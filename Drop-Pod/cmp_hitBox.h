#pragma once

#include <SFML/Graphics.hpp>

class HitBox
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	sf::FloatRect nextPos;
	float offsetX;
	float offsetY;

public:
	HitBox(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	virtual ~HitBox();

	//Accessors
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect& getNextPosition(const sf::Vector2f& velocity);
	//Editors

	void setPosition(const sf::Vector2f& position);
	void setPosition(const float x, const float y);

	//Functions
	bool collides(const sf::FloatRect& frect);
	void update();
	void render(sf::RenderTarget& target);


};

