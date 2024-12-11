#include <iostream>

using String = std::string;

class Entity
{
private:

	String m_Name;

public:
	Entity() : m_Name("Unknown!") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }

};

int main()
{
	int a = 2;

	int* b = new int[50]; // 200 Bytes

	Entity* entity = new Entity("Madhawa");

	// malloc - memeory allocation
	// Entity* e = (Entity*)malloc(sizeof(Entity)); // what is done in the new key word


	delete[] b;
	delete entity;

	return 0;
}