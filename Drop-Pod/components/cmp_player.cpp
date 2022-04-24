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

//this->switchState = WSAD;

	switch (switchState) {
	case WSAD:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(-0.1, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.1, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, -0.1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, 0.1);
		break;

	case Arrows:

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(-0.1, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.1, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, -0.1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, 0.1);
		break;
	}
}

void PlayerComponent::render() {}

/*const bool PlayerComponent::arrowsSwitch() const
{
	{
		if (this->switchState == Arrows)
			return true;
		return false;
	}
}

const bool PlayerComponent::wsadSwitch() const
{
	if (this->switchState == WSAD)
		return true;
	return false;
}*/
