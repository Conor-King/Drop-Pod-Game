#pragma once
class monsterAttributes
{
public:
	// Stats
	int hp;
	int hpmax;
	int damage;

	//functions 
	void loseHP(const int hp);
	const bool isDead() const;

};

