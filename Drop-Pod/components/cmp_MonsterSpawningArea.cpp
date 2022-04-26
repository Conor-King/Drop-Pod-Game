
#include "cmp_MonsterSpawningArea.h"

cmp_MonsterSpawningArea::cmp_MonsterSpawningArea(int grid_x, int grid_y, float gridSizef, int monsterType, int monsterAmount)
{
	this->monsterType = monsterType;
	this->monsterAmount = monsterAmount;
	this->monsterCount = 0;

}

cmp_MonsterSpawningArea::~cmp_MonsterSpawningArea()
{
}

const int& cmp_MonsterSpawningArea::getMonsterAmount() const
{
	return this->monsterAmount;
	// TODO: insert return statement here
}

const int& cmp_MonsterSpawningArea::getMonsterCount() const
{
	return this->monsterCount;
	// TODO: insert return statement here
}

const int& cmp_MonsterSpawningArea::getMonsterType() const
{
	return this->monsterType;
	// TODO: insert return statement here
}

void cmp_MonsterSpawningArea::update()
{
}

//void cmp_MonsterSpawningArea::render(sf::RenderTarget& target)
//{
//}
