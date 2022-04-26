#pragma once
#include "cmp_MonsterSpawningArea.h"
#include "cmp_player.h"
#include "cmp_monster.h"
class cmp_MonsterSpawningSystem
{
private:
	std::vector<Monster*>& activeEnemies;
	PlayerComponent& player;


public:
	cmp_MonsterSpawningSystem();
	virtual ~cmp_MonsterSpawningSystem();

	//Functions 
	void createMonster(const short type, const float xPosition, const float yPosition, cmp_MonsterSpawningArea& monster_spawning_area); // TO-DO
	void removeMonster(const int index); //TO - DO

	void update(const float& dt); //TO-DO
	void render(sf::RenderTarget* target);
};
