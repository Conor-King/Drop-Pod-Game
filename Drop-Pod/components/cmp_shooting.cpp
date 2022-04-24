#include "cmp_shooting.h"
#include <SFML/Graphics.hpp>
#include "system_renderer.h"
#include "engine.h"

using namespace std;
using namespace sf;

unsigned char bulletCount;
Bullet bullets[256];

auto temp2 = Texture::Texture();
auto spriteTexture = make_shared<Texture>(temp2);

ShootingComponent::ShootingComponent(Entity* p) : Component(p) {
	bulletCount = 0;
	Bullet::init();
}

void ShootingComponent::update(double dt) {

	// Aiming the bullets

	// Firing the bullets
	Bullet::fire(_parent->getPosition());

}

void ShootingComponent::render() {
	// Render fired bullets?
	Bullet::render();
}

Bullet::Bullet() {}

void Bullet::init() {
	if (!spriteTexture->loadFromFile("res/assets/man/Idle.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}

	for (auto &b : bullets) {
		b.setPosition(Vector2f(-100, -100));
		b.setTexture(*spriteTexture);
		b.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(44, 40)));
		b.setOrigin(Vector2f(0.f, 0.f));
	}
}

void Bullet::update(const double dt) {
	for (auto& b : bullets) {
		b._update(dt);
	}
}

void Bullet::render() {
	for (auto& b : bullets) {
		Renderer::queue(&b);
	}
}

void Bullet::fire(const Vector2f& pos) {
	bulletCount++;
	bulletCount = bulletCount % 256;
	bullets[bulletCount].setPosition(pos);
}

void Bullet::_update(const double dt) {

	RenderWindow& window = Engine::GetWindow();
	auto view = window.getView();

	// If bullet is out of bounds. remove/return;
	if (getPosition().x < -100 || getPosition().x > view.getSize().x + 100
		|| getPosition().y < -100 || getPosition().y > view.getSize().y + 100) 
	{
		printf("Bullet out of bounds.");
		return;
	}

	Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));


	// else move bullet along path.


	// Possibly add collision
}