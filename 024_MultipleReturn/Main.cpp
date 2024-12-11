#include <iostream>
#include <tuple>
#include <array>
#include <vector>


std::array<std::string, 2> getString() // c++ 14
{
	return std::array<std::string, 2> {"Str_one", "Str_two"};
}

std::vector<std::string> getStringVector() // c++ 14
{
	return std::vector<std::string> {"Str_vec_one", "Str_vec_two"};
}

struct Student
{
	std::string m_FirstName{ "" };
	std::string m_LastName{ "" };
	int m_Age{ 0 };
};

Student getStudent()
{
	auto ds = Student{ "Madhawa", "Heshan", 30 };
	return ds;
}

std::tuple<std::string, std::string, int> getData() // structured binding since c++17:
{
	return { "One", "two", 3 };
}

int main()
{
	auto [ st1, st2 ] = getString();
	std::cout << st1 << ", " << st2 << std::endl;

	auto [stV1, stV2] = getString();
	std::cout << stV1 << ", " << stV2 << std::endl;

	Student student = getStudent();
	std::cout << student.m_FirstName << " " << student.m_LastName << " " << student.m_Age << std::endl;

	auto [str1,str2,number] = getData(); 
	std::cout << str1 << ", " << str2 << ", " << number << std::endl;

	std::cin.get();
}