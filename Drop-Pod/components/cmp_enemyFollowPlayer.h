#pragma once
#include "cmp_monster.h"

class EnemyFollowPlayer {
private:
	
public:
	EnemyFollowPlayer(Monster& self, Player& player);
	~EnemyFollowPlayer();
	void updatePath(const float& dt);
};