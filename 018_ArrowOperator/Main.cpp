#include <iostream>

class Entity
{
public:
	void Print() const
	{
		std::cout << "Hello Entity!" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Obj;

public:
	ScopedPtr(Entity* entity) 
		: m_Obj(entity){}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator ->()
	{
		return m_Obj;
	}

	const Entity* operator ->() const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z; // float 4-Byte
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	(*ptr).Print(); // is equal to ptr->Print();
	ptr->Print();

	ScopedPtr sc_e = new Entity();
	sc_e->Print();

	const ScopedPtr sc_e2 = new Entity();
	sc_e2->Print(); // const method

	std::cout << "================================" << std::endl;

	int offset_x = (int)&((Vector3*)nullptr)->x;
	int offset_y = (int)&((Vector3*)nullptr)->y;
	int offset_z = (int)&((Vector3*)nullptr)->z;
	std::cout << "offset x:" << offset_x << std::endl;
	std::cout << "offset y:" << offset_y << std::endl;
	std::cout << "offset z:" << offset_z << std::endl;

	std::cin.get();
	return 0;
}