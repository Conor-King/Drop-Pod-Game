#pragma once

#include "cmp_actor_movement.h"
#include <ecm.h>

enum move_states { WSAD = 0, Arrows };


class PlayerComponent : public ActorMovementComponent {
public:

	PlayerComponent() = delete;
	explicit PlayerComponent(Entity* p);

	void update(double dt) override;
	void render() override;
	~PlayerComponent() override = default;
	void movment();
	
	
	//void move(const double dt, const float dir_x, const float dir_y);

protected:

	int _health;
	float _speed;

};