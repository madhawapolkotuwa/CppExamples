#include <iostream>

using String = std::string;

class Entity 
{
private:

	String m_Name;

public:
	Entity() : m_Name("Madhawa"){}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }

};

int main() 
{
	Entity* e;

	{ // stack allocation
		Entity entity0("Madhawa");
		e = &entity0;
		std::cout << entity0.GetName() << std::endl;
	}

	{ // heep allocation
		Entity* entity1 = new Entity("Madhawa");
		e = entity1;
		//std::cout << (*entity1).GetName() << std::endl;
		std::cout << entity1->GetName() << std::endl;
	}
	
	delete e; // if heep new need to delete
	std::cin.get();
	return 0;
}