#include "cmp_shooting.h"
#include "cmp_actor_movement.h"
#include "cmp_sprite.h"
#include <SFML/Graphics.hpp>
#include "system_renderer.h"
#include "engine.h"

using namespace std;
using namespace sf;

unsigned char bulletCount;
vector<Bullet> bullets(10);
shared_ptr<float> angleshot;
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
	// Render fired bullets?
	Bullet::render();
}

void ShootingComponent::Fire() {

	RenderWindow& window = Engine::GetWindow();
	auto view = window.getView();
	auto mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
	*angleshot = atan2(mousePos.y - this->_parent->getPosition().y, mousePos.x - this->_parent->getPosition().x);

	auto spriteSize = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().getLocalBounds();
	Vector2f spriteCenter = Vector2f(spriteSize.width * 0.6, spriteSize.height * 0.6);
	// Firing the bullets
	Bullet::fire(_parent->getPosition() + spriteCenter);
}

Bullet::Bullet() {}

void Bullet::init() {

	if (!spriteTexture->loadFromFile("res/assets/weapons/MainWeapons/bulletGlow.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}

	for (auto &b : bullets) {
		b.setPosition(Vector2f(-100, -100));
		b.setTexture(*spriteTexture);
		b.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(44, 40)));
		b.setOrigin(Vector2f(0.f, 0.f));

		b.setAngle(0.f , b);
		b.mousePos = Vector2f(0, 0);
	}
}

void Bullet::setAngle(float angle, Bullet b) {
	b.angleshot = make_shared<float>(angle);
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

	RenderWindow& window = Engine::GetWindow();
	auto view = window.getView();
	auto mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
	//*angleshot = atan2(mousePos.y - this->_parent->getPosition().y, mousePos.x - this->_parent->getPosition().x);

	bulletCount++;
	bulletCount = bulletCount % 10;
	bullets[bulletCount].setPosition(pos);
	bullets[bulletCount].setAngle(atan2(mousePos.y - bullets[bulletCount].getPosition().y, mousePos.x - bullets[bulletCount].getPosition().x), bullets[bulletCount]);
}

void Bullet::_update(const double dt) {
	
	RenderWindow& window = Engine::GetWindow();
	auto view = window.getView();

	// If bullet is out of bounds. remove/return;
	if (getPosition().x < -100 || getPosition().x > view.getSize().x + 100
		|| getPosition().y < -100 || getPosition().y > view.getSize().y + 100) 
	{
		printf("Bullet out of bounds.");
		this->setPosition(-100, -100);
		return;
	}
	else {
		
		// Does not keep the angle after being set.
		this->move(cos(*this->angleshot) * 1.0f, 0);
		this->move(0, sin(*this->angleshot) * 1.0f);
		
	}



	// else move bullet along path.


	// Possibly add collision
}