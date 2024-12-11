#include <iostream>

class Entity
{
public:
	Entity() {
		std::cout << "Ctreated Entity!" << std::endl;
	}

	~Entity() {
		std::cout << "destroyed Entity!" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Ptr;

public:
	ScopedPtr(Entity* ptr) : m_Ptr(ptr){}

	~ScopedPtr() {
		delete m_Ptr;
	}
};


int main() 
{
	{ // scope
		Entity e; // on stack memory (auto destroyed when jump out to scope)
	}

	std::cout << "================================" << std::endl;

	{ // scope
		Entity* en = new Entity; // Heap memory
		
		// heap memory  will not destroy out of the scope 
		// we need to clean-up
		delete en;
	}

	std::cout << "================================" << std::endl;

	{
		Entity* e = new Entity();
		ScopedPtr scope = ScopedPtr(e);
	}

	return 0;
}