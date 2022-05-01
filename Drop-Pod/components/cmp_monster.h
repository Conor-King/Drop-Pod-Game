#pragma once

#include "cmp_actor_movement.h"
#include <ecm.h>

namespace sf
{
	class Texture;
}

class MonsterComponent : public ActorMovementComponent {
protected:
	int _health;
	std::shared_ptr<Entity> _player;
	std::shared_ptr<sf::Texture> _texture;

public:
	MonsterComponent() = delete;
	explicit MonsterComponent(Entity* p, std::shared_ptr<Entity> player);

	void update(double dt) override;
	void render() override;
	void move();
	~MonsterComponent() override = default;

	void setHealth(int health);
};
