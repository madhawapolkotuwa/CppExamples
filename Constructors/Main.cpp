#include <iostream>

class Entity
{
public:
	float X{}, Y{};

	Entity() 
	{
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Constructed Entity!" << std::endl;
	}

	Entity(int x, int y)
	{
		X = x;
		Y = y;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}


	void Print() 
	{
		std::cout << "(" << X << "," << Y << ")" << std::endl;
	}

};

class Log
{
public:
	Log() = delete; // can not initialize the constructor

	static void Write()
	{
		std::cout << "Hello World!" << std::endl;
	}
};

void Function() 
{
	Entity e2;
	e2.Print();
}

int main() 
{
	//Entity e(1,2);
	//e.Print();

	Function();
	
	// Log l; // Error because of the default constructor dissabled
	Log::Write();
	
	std::cin.get();
	return 0;
}