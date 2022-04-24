#pragma once

#include "ecm.h"
#include <SFML/Graphics.hpp>

class ShootingComponent : public Component {
protected:

public:
	ShootingComponent() = delete;

	explicit ShootingComponent(Entity* p);

	void update(double dt) override;
	void render() override;

};

class Bullet : sf::Sprite {
protected:
	void _update(const double dt);
public:
	static Bullet bullets[256];
	static unsigned char bulletCount;

	static void update(const double dt);
	static void render();
	static void fire(const sf::Vector2f& pos);
	static void init();

	~Bullet() = default;
	Bullet();
};