#include <iostream>
#include <string>

void PrintEntity_ConstRef(const Entity& e);

void PrintEntity_Ptr(Entity* e);


class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;

		PrintEntity_ConstRef(*this);
		PrintEntity_Ptr(this);
	}
};

void PrintEntity_ConstRef(const Entity& e)
{

}

void PrintEntity_Ptr(Entity* e) 
{

}

int main()
{


	return 0;
}