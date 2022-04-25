#include "cmp_enemyFollowPlayer.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

EnemyFollowPlayer::EnemyFollowPlayer(Monster& self, Player& player) {
}


EnemyFollowPlayer::~EnemyFollowPlayer()
{
}

void EnemyFollowPlayer::updatePath(const float& dt)
{
	sf::Vector2f moveVec;

	moveVec.x = player.getPosition().x - self.getPosition().x;
	moveVec.y = player.getPosition().y - self.getPosition().y;

	float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));

	moveVec /= vecLength;

	if ((self.getPosition().x != player.getPosition().x) && std::abs(vecLength) < 500.f)
		self.move(moveVec.x, moveVec.y, dt);
}

