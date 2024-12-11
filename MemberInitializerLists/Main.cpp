#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Score;

public:
	Entity()
		: m_Name("Unkowan"), m_Score(0)
	{}

	Entity(const std::string& name, int score) 
		: m_Name(name),m_Score(score)
	{}

	const std::string& GetName() const { return m_Name; }
};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;
	
	Entity e1("Madhawa",12);
	std::cout << e1.GetName() << std::endl;

	std::cin.get();
	return 0;
}