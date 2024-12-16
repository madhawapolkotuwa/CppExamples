#include <iostream>
#include <mutex>

// https://youtu.be/bP9z3H3cVMY?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
	static int s_Count;

public:
	const std::string& GetName() const // const method means, It can not change the class members,
	{
		m_DebugCount++;
		s_Count++;
		return m_Name;
	}

	const int GetCallCount() const
	{
		return m_DebugCount;
	}

	const int StaticCount() const
	{
		return s_Count;
	}
};

int Entity::s_Count;


int main()
{
	const Entity e;
	const Entity e1;

	e.GetName();
	std::cout << "call count: " << e.GetCallCount() << std::endl;
	e.GetName();
	e.GetName();
	std::cout << "call count: " << e.GetCallCount() << std::endl;

	std::cout << "static count: " << e1.StaticCount() << std::endl; // static s_Count share memory for every class instance


	int x = 8;
	auto f = [=]() mutable // = means pass by the values
		{
			x++; // this will copy x value like y = x; the increment y++; this is done by mutable keyword
			std::cout << x << std::endl;
		};

	f();

	// x still be 8;

	std::cout << "----------------------------" << std::endl;

	return 0;
}