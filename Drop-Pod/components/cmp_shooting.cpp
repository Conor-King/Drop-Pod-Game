#include "cmp_shooting.h"
#include "cmp_actor_movement.h"
#include "cmp_sprite.h"
#include <SFML/Graphics.hpp>
#include "system_renderer.h"
#include "engine.h"

using namespace std;
using namespace sf;

unsigned int bulletCount;
vector<Bullet> bullets(20);
bool isVisible = false;
float angle;

float tempfloat = 0.f;
shared_ptr<float> angleshot = make_unique<float>(tempfloat);
Vector2f mousePos;

auto temp2 = Texture::Texture();
auto spriteTexture = make_shared<Texture>(temp2);

ShootingComponent::ShootingComponent(Entity* p) : ActorMovementComponent(p) {
	Bullet::init();
}

void ShootingComponent::update(double dt) {
	Bullet::update(dt);
}

void ShootingComponent::render() {
	Bullet::render();
}

void ShootingComponent::Fire() {
	auto spriteSize = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().getLocalBounds();
	Vector2f spriteCenter = Vector2f(spriteSize.width * 0.5, spriteSize.height * 0.5);
	// Firing the bullets
	Bullet::fire(_parent->getPosition());
}

Bullet::Bullet() {}

void Bullet::init() {
	if (!spriteTexture->loadFromFile("res/assets/weapons/MainWeapons/bulletGlow.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}

	for (auto& b : bullets) {
		b.setPosition(Vector2f(-100, -100));
		b.setTexture(*spriteTexture);
		b.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(spriteTexture->getSize().x, spriteTexture->getSize().y)));
		b.setOrigin(Vector2f(spriteTexture->getSize().x * 0.5, spriteTexture->getSize().y * 0.5));
		b.setAngle(0.f, b);
		b.mousePos = Vector2f(0, 0);
		b.isVisible = false;
	}
}

void Bullet::setAngle(float a, Bullet& b) {
	b.angle = a;
}

void Bullet::update(const double dt) {
	for (auto& b : bullets) {
		b._update(dt);
	}
}

void Bullet::render() {
	for (auto& b : bullets) {
		if (b.isVisible) {
			Renderer::queue(&b);
		}
	}
}

void Bullet::fire(const Vector2f& pos) {
	RenderWindow& window = Engine::GetWindow();

	auto mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

	bulletCount++;
	bulletCount = bulletCount % 20;
	bullets[bulletCount].setPosition(pos);
	bullets[bulletCount].isVisible = true;

	// Sets the angle of the bullet.
	*angleshot = atan2(mousePos.y - bullets[bulletCount].getPosition().y, mousePos.x - bullets[bulletCount].getPosition().x);
	bullets[bulletCount].setAngle(*angleshot, bullets[bulletCount]);
}

void Bullet::_update(const double dt) {
	RenderWindow& window = Engine::GetWindow();
	const View view = window.getView();

	// If bullet is out of bounds. remove/return;
	if (getPosition().x < view.getCenter().x - 100 - view.getSize().x * 0.5 || getPosition().x > view.getCenter().x + 100 + view.getSize().x * 0.5
		|| getPosition().y < view.getCenter().y - 100 - view.getSize().y * 0.5 || getPosition().y > view.getCenter().y + 100 + view.getSize().y * 0.5)
	{
		this->isVisible = false;
		return;
	}
	else {
		this->move(cos(this->angle) * 200.f * dt, 0);
		this->move(0, sin(this->angle) * 200.f * dt);
	}
}