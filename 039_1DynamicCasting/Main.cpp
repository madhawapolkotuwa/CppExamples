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
public:

};

class Enemy : public Entity
{

};

int main()
{
	Player* player = new Player();

	Entity* actuallyEnemy = new Enemy();

	Entity* actuallyPlayer = player;

	Player* p0 = dynamic_cast<Player*>(actuallyEnemy); // not works

	Player* p1 = dynamic_cast<Player*>(actuallyPlayer); // works

	return 0;
}