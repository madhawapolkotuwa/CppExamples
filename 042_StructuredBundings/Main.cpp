#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
	return { "Madhaw" , 30 };
}

int main()
{

	auto person = CreatePerson();

	std::string name;
	int age;
	std::tie(name, age) = CreatePerson();

	auto [name1, age2] = CreatePerson(); // since c++ 17

	return 0;
}