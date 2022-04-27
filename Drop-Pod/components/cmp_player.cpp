#include "cmp_player.h"
#include <SFML/Window.hpp>
#include "../drop_pod_game.h"
using namespace std;
using namespace sf;

int _health;


PlayerComponent::PlayerComponent(Entity* p) : ActorMovementComponent(p) {
	_health = 100;

}


void PlayerComponent::update(const double dt)
{

	float directX = 0.f;
	float directY = 0.f;

	switch (switchState) {
	case WSAD:

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			directX--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			directX++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			directY--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			directY++;
		break;

	case Arrows:

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			directX--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			directX++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			directY--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			directY++;
		break;
	}

	auto speed = _parent->GetCompatibleComponent<ActorMovementComponent>()[0]->getSpeed();
	_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(Vector2f(directX * speed * dt, directY * speed * dt));
}

void PlayerComponent::render() {}

//void PlayerComponent::movment()
//{
//	switch (switchState) {
//	case WSAD:
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(-1, 0.f);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(1, 0.f);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, -1);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, 1);
//		break;
//
//	case Arrows:
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(-1, 0.f);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(1, 0.f);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, -1);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//			_parent->GetCompatibleComponent<ActorMovementComponent>()[0]->move(0.f, 1);
//		break;
//
//	}
//}

