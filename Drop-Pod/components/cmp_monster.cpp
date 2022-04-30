#include "cmp_monster.h"

using namespace std;
using namespace sf;

MonsterComponent::MonsterComponent(Entity* p, shared_ptr<Entity> player) : ActorMovementComponent(p),
_health(100), _player(player) { }

void MonsterComponent::setHealth(int health)
{
	_health = health;
}

void MonsterComponent::update(double dt)
{
	if (_health <= 0)
	{
		_parent->setAlive(false);
	}

	auto& playerPos = _player->getPosition();
	auto& enemyPos = _parent->getPosition();

	Vector2f direction = playerPos - enemyPos;
	//Vector2f normalizeDir = direction / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	float xDistance = playerPos.x - enemyPos.x;
	float yDistance = playerPos.y - enemyPos.y;

	//Vector2f direction = Vector2f(xDistance, yDistance);

	auto hyp = sqrtf((xDistance * xDistance) + (yDistance * yDistance));

	if (hyp != 0) {

		direction.x /= hyp;
		direction.y /= hyp;
	}

	auto speed = _parent->GetCompatibleComponent<ActorMovementComponent>()[0]->getSpeed();
	_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(direction.x * speed * dt, direction.y * speed * dt);
}

void MonsterComponent::render() { }