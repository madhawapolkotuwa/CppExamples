#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
	int m_Age;

public:
	Entity(const String& name) 
		: m_Name(name), m_Age(-1) {}

	Entity(int age) 
		: m_Name("Unknown"), m_Age(age) {}

	String GetEntity() const {
		return m_Name + "," + std::to_string(m_Age);
	}
};

void PrintEntity(const Entity& entity)
{
	std::cout << entity.GetEntity() << std::endl;
}

int main()
{
	Entity a = String("Madhawa");
	Entity b = 22;

	PrintEntity(22);
	PrintEntity(String("Madhawa"));



	std::cin.get();
	return 0;
}