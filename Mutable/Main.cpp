#include <iostream>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;

public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;

	e.GetName();

	int x = 8;
	auto f = [=]() mutable // = means pass by the values
		{
			x++; // this will copy x value like y = x; the increment y++; this is done by mutable keyword
			std::cout << x << std::endl;
		};

	f();

	// x still be 8;

	return 0;
}