#include "cmp_actor_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void ActorMovementComponent::update(double dt) {}

ActorMovementComponent::ActorMovementComponent(Entity* p)
	: Component(p), _speed(100.0f), _moving(false), _direction(false) {}

bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {
	return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
	// return true;
}

void ActorMovementComponent::move(const sf::Vector2f& p) {
	auto pp = _parent->getPosition() + p;
	if (validMove(pp)) {
		_parent->setPosition(pp);
	}
}

void ActorMovementComponent::enemyMove(const sf::Vector2f& p) {
	auto pp = _parent->getPosition() + p;
	_parent->setPosition(pp);
}

void ActorMovementComponent::move(float x, float y) {
	move(Vector2f(x, y));
}

float ActorMovementComponent::getSpeed() const { return _speed; }

void ActorMovementComponent::setSpeed(float speed) { _speed = speed; }

bool ActorMovementComponent::getMoving() const { return _moving; }

void ActorMovementComponent::setMoving(bool moving) { _moving = moving; }

bool ActorMovementComponent::getDirection() { return _direction; }

void ActorMovementComponent::setDirection(bool direction) { _direction = direction; }