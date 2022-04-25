#include "monsterAttributes.h"

void monsterAttributes::loseHP(const int hp)
{
	this->hp -= hp;

	if (this->hp < 0)
		this->hp = 0;
}

const bool monsterAttributes::isDead() const
{
	return false;
}
