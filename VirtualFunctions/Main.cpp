#include <iostream>

class Printable
{
public:
	virtual std::string GetClassName() = 0; // Need to implement this function. From inharitance class
};

class Entity : public Printable
{
public:
 	virtual std::string GetName() { return "virtual Fn Entiry"; }

	std::string TestName() { return "not virtual Fn Entity"; }

	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
	std::string m_Name;

public:
	Player(const std::string& name) : m_Name(name) {}

	std::string GetName() override { return "Palyer : " + m_Name; }

	std::string TestName() { return "not override Fn Player"; }

	std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;
	std::cout << e->TestName() << std::endl;
	
	std::cout << "-----------------------------------" << std::endl;
	Player* p = new Player("Madhawa");
	std::cout << p->GetName() << std::endl;
	std::cout << p->TestName() << std::endl;
	
	std::cout << "-----------------------------------" << std::endl;
	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;
	std::cout << entity->TestName() << std::endl; // override the entity from player p
	
	std::cout << "-----------------------------------" << std::endl;
	Print(p);

	return 0;
}