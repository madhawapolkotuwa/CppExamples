#include <iostream>

// https://youtu.be/CiHfz6pTolQ?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

class Entity
{
public:
	virtual void PrintEntity(){} // fot dynamic casting need virtual function 
								 // runtime dynamic_cast must have polymorphic class type
};

class Player : public Entity
{
private:
	const char* m_player = "Player";
public:
	void PrintPlayer() { std::cout << m_player << "\n"; }
};

class Enemy : public Entity
{
private:
	const std::string m_enemy = "Enemy";
public:
	std::string Get() { return m_enemy; };
	void PrintEnemy() { std::cout << m_enemy << "\n"; }
};

int main()
{
	Player* player = new Player();

	Entity* actuallyEnemy = new Enemy();

	Entity* actuallyPlayer = player;

	Player* p0 = dynamic_cast<Player*>(actuallyEnemy); // not works

	p0 = static_cast<Player*>(actuallyEnemy); // works
	p0->PrintPlayer();

	Player* p1 = dynamic_cast<Player*>(actuallyPlayer); // works

	return 0;
}