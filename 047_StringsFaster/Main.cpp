#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}

void PintStringView(std::string_view string) // c++ 17
{
	std::cout << string << std::endl;
}

int main()
{
	std::string name = "Madhawa Polkotuwa"; // 2 allocations

	auto name2 = std::string("Madahawa");	// 1 allocation

	std::string firstName = name.substr(0, 6); // 1
	std::string lastName = name.substr(8, 16); // 1

	PrintName(name);

	std::cout << s_AllocCount << " allocations" << "\n";

	std::cout << "-----------------------------------------------\n";

	std::string_view first_name(name.c_str(), 7);	 // no new allocation
	std::string_view last_name(name.c_str() + 8, 9); // no new allocation

	PintStringView(first_name);
	PintStringView(last_name);

	std::cout << s_AllocCount << " allocations" << "\n";

	std::cout << "-----------------------------------------------\n";

	const char* char_name = "Madhawa Polkotuwa"; // no allocation

	std::string_view first_name_1(char_name, 7);
	std::string_view last_name_1(char_name + 8, 9);

	PintStringView(first_name_1);
	PintStringView(last_name_1);

	std::cout << s_AllocCount << " allocations" << "\n";

	return 0;
}