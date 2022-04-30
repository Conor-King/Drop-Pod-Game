#pragma once

#include "cmp_actor_movement.h"
#include <ecm.h>

class MonsterComponent : public ActorMovementComponent {
protected:
	int _health;
	std::shared_ptr<Entity> _player;

public:
	MonsterComponent() = delete;
	explicit MonsterComponent(Entity* p, std::shared_ptr<Entity> player);

	void update(double dt) override;
	void render() override;
	~MonsterComponent() override = default;

	void setHealth(int health);

};