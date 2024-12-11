#include <iostream>
#include <string>

// https://youtu.be/f7mtWD9GdJ4?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

void Function()
{
	int i = 0;
	i++;
	std::cout << i << std::endl;
}

void FunctionWithStaticVariable()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}


class Singleton
{
	std::string m_Name{""};
public:
	Singleton(std::string name) : m_Name(name){}

	static Singleton& Get()
	{
		static Singleton instance("World!");
		return instance;
	}

	void Hello()
	{
		std::cout << "Hello " << m_Name << std::endl;
	}
};

int main()
{
	Function();
	Function();
	Function();
	Function();
	Function();

	std::cout << "____________________________" << std::endl;

	FunctionWithStaticVariable();
	FunctionWithStaticVariable();
	FunctionWithStaticVariable();
	FunctionWithStaticVariable();
	FunctionWithStaticVariable();

	std::cout << "____________________________" << std::endl;

	Singleton::Get().Hello();

	std::cout << "____________________________" << std::endl;
	Singleton singleton1("Madhawa");
	singleton1.Hello();
	
	std::cout << "____________________________" << std::endl;
	singleton1.Get().Hello();
}