#include "cmp_monster.h"

#include "cmp_sprite.h"
#include "engine.h"

using namespace std;
using namespace sf;

MonsterComponent::MonsterComponent(Entity* p, shared_ptr<Entity> player, shared_ptr<Texture> texture) : ActorMovementComponent(p),
_health(100), _player(player), _texture(texture) { }

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

	//Vector2f direction = playerPos - enemyPos;
	////Vector2f normalizeDir = direction / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	////Vector2f direction = Vector2f(xDistance, yDistance);

	//auto hyp = sqrtf((xDistance * xDistance) + (yDistance * yDistance));
	//if (hyp != 0) {
	//	direction.x /= hyp;
	//	direction.y /= hyp;
	//}
	

	auto& playerPos = Engine::GetWindow().getView().getCenter();
	auto& enemyPos = _parent->getPosition();
	float xDistance = playerPos.x - enemyPos.x;
	float yDistance = playerPos.y - enemyPos.y;

	auto distance = (xDistance * xDistance) + (yDistance * yDistance);

	if (distance > 3500)
	{
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->setMoving(true);
		Vector2f direction = normalize(playerPos - enemyPos);
		auto speed = _parent->GetCompatibleComponent<ActorMovementComponent>()[0]->getSpeed();

		auto move = Vector2f(direction.x * speed * dt, direction.y * speed * dt);
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->enemyMove(move);
	}
	else
	{
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->setMoving(false);
	}

	// Swap the animation for moving and attacking when the sprite stops moving (Reaches the player)
	if (!_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->getMoving())
	{
		_parent->GetCompatibleComponent<AnimationComponent>()[0]->switchRow(4);
		_parent->GetCompatibleComponent<AnimationComponent>()[0]->setDuration(0.17);

		// Attack

	}
	else
	{
		_parent->GetCompatibleComponent<AnimationComponent>()[0]->switchRow(0);
		_parent->GetCompatibleComponent<AnimationComponent>()[0]->setDuration(0.1);
	}

	// Flip the sprite if moving left.
	if (enemyPos.x < playerPos.x)
	{
		auto& p = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite();
		_parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setScale(-2.f, 2.f);
	}
	else
	{
		auto& p = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite();
		_parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setScale(2.f, 2.f);
	}
}

void MonsterComponent::render() { }

