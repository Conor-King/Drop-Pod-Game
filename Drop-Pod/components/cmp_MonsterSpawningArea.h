#pragma once
class cmp_MonsterSpawningArea
{
private:
	int monsterType;
	int monsterAmount;
	int monsterCount;

public:
	cmp_MonsterSpawningArea(int grid_x, int grid_y, float gridSizef, int monsterType, int monsterAmount);
	virtual ~cmp_MonsterSpawningArea();
		//Accessors 
	const int& getMonsterAmount() const;
	const int& getMonsterCount() const;
	const int& getMonsterType() const;
		//Functions
	void update();
	void render(sf::RenderTarget& target, );

};