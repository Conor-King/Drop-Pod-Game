#include "cmp_player.h"
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

int _health;

PlayerComponent::PlayerComponent(Entity* p) : ActorMovementComponent(p) {
	_health = 100;

}

void PlayerComponent::update(const double dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(-0.1, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.1, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, -0.1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, 0.1);
}


void PlayerComponent::render() {}